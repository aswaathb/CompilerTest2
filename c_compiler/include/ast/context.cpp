#include "context.hpp"

ast_context::ast_context(std::ostream &in_stream) : current_scope_depth(-1), stream(in_stream), makeNameUnq(0),
										 stack_mem(0), break_number(0), function_num(0) {
	for (unsigned int i =0; i < 4; i++){ 
		parameters_ids.push_back("");
	}
}
//Initialised to 0: the global scope

//When entering a new subroutine
void ast_context::enter_subroutine () {
	stream 	<< "\t.frame\t$fp,"<< stack_mem <<",$31"	<< std::endl
		 	<< "\t.mask\t0x40000000,-4"					<< std::endl
		 	<< "\t.fmask\t0x00000000,0"					<< std::endl
		 	<< "\t.set	noreorder"						<< std::endl
		 	<< "\t.set	nomacro"						<< std::endl;

	//Right now memory allocation is an arbitrary number -->
	//Could put everything through stringstream instead of ostream, calculate and then ostream at the end to get exact memory value
	stream << "\taddiu" << "\t" << "$sp, $sp, " << -stack_mem << "\t\t# Memory allocation" << std::endl;
	stream << "\t#------Saving Preserved registers ----------#" << std::endl;
	stream << "\tsw" << "\t" << "$31, " << stack_mem-4 << "($sp)" << "\t\t# frame pointer at stack bottom"<< std::endl;
	stream << "\tsw" << "\t" << "$fp, " << stack_mem-8 << "($sp)" << "\t\t# frame pointer at stack bottom"<< std::endl;
	
	//Preserver other registers....

	//Add memory accordingly
	//sw      $4,24($fp)        Check if there are parameters, and allocate registers accordingly
    //sw      $5,28($fp)        Check if there are parameters, and allocate registers accordingly
	stream << "\tmove\t$fp,$sp" << "\t\t# Copying $sp into $fp. Can use offsets from $fp to access the stack locations" << std::endl;
}

//Exiting the current subroutine
void ast_context::exit_subroutine () {
	
	stream << "\tmove\t$sp,$fp" << "\t\t# Copying $fp into $sp" << std::endl;

	//stream << "lw\t$31,$fp" << "\t\t# Copying $fp into $sp" << std::endl;
	//Accordingly...
	
	stream << "\tlw" << "\t" << "$31, " << stack_mem-4 << "($sp)" << "\t\t# frame pointer at stack bottom"<< std::endl;
	stream << "\tlw" << "\t" << "$fp, " << stack_mem-8 << "($sp)" << "\t\t# restore frame pointer"<< std::endl;
	stream << "\taddiu" << "\t" << "$sp, $sp, " << stack_mem << "\t\t# Pop off the frame" << std::endl;
	stream << "\tj\t$31" << "\t\t# Return to caller" << std::endl;
	stream << "\tnop" << std::endl;
}

//Inserting a symbol
//Returns true if inserted, returns false if found before --> i.e. need to overwrite
bool ast_context::insert_symbols(std::string in_type, std::string in_id, int in_reg, bool declaration) {		
		bool not_found = true;

		if ((unsigned)current_scope_depth > symbol_table.size()) {
			stream << "Exiting. Scope depth is greater than symbol table size." << std::endl;
			exit (EXIT_FAILURE);
		}

		symbol_vector* temp = new symbol_vector;
		temp->symbol_id = in_id;
		temp->symbol_type = in_type;
		temp->reg_num = in_reg;

		if (!declaration) {
		//Check if already there --> skip this if declaration
			for (int n = current_scope_depth; n >= 0 ; n--) {
				for (unsigned int i =0; i < symbol_table[n]->all_symbols.size(); i++) {
					std::string cur = symbol_table[n]->all_symbols.at(i)->symbol_id;			
					if ( cur == in_id) {
						//stream << "Variable already in there: " << in_id << std::endl;
						//stream << "Rewriting from register" << symbol_table[current_scope_depth]->all_symbols.at(i)->reg_num 
						//		<< " to register: " << in_reg << std::endl;

						not_found = false;
						symbol_table[n]->all_symbols.at(i)->symbol_id = in_id;
						symbol_table[n]->all_symbols.at(i)->symbol_type = in_type;
						symbol_table[n]->all_symbols.at(i)->reg_num = in_reg;
						return not_found;
					}
				}
			}
		}

		if (not_found) {
			if (temp != NULL)
				symbol_table[current_scope_depth]->all_symbols.push_back(temp);
		}

		return not_found;
	}

//Creating a new scope
void ast_context::make_scope(std::string in_id, std::string in_scope_type, int mem_needed) {
	scope_symbol_table* temp = new scope_symbol_table;
	temp->scope_ID = in_id;
	temp->scope_type = in_scope_type;

	symbol_table.push_back(temp);
	current_scope_depth++;

	if (in_scope_type == "function"){
		function_num++;
		//current_scope_depth--;
		stack_mem += mem_needed;
		enter_subroutine();
		//Function returns 0 by default!
		stream << "\tmove\t$2, $0" << std::endl;
	}
}

//Exiting the scope
void ast_context::exit_scope() {
	//Delete all the variables from the vector, since they cannot be accessed anymore
	symbol_table.erase(symbol_table.begin() + current_scope_depth);
	current_scope_depth--;
}

void ast_context::exit_function_scope() {
	exit_subroutine();
	symbol_table.erase(symbol_table.begin() + current_scope_depth);
	current_scope_depth--;
	
	//TODO: NOT SURE...By default return a 0??!??
	//Probably best to put this in when entering the function....
	
	//stream << "\tmove\t$2, $0" << std::endl;
}

int ast_context::find_variable(std::string in_id) {
	//Loop through all scopes above the current scope depth to find the variable
	for (int n = current_scope_depth; n >= 0 ; n--) {
		for (unsigned int i =0; i < symbol_table[n]->all_symbols.size(); i++) {
			if (symbol_table[n]->all_symbols.at(i)->symbol_id == in_id) {
				return symbol_table[n]->all_symbols.at(i)->reg_num;
			}
		}
	}

	//If it is not found, assume it is a global variable

	stream 	<< "\tlui	$2,%hi(" << in_id << ")"			<< std::endl
			<< "\tlw	$2,%lo(" << in_id << ")" << "($2)" 	<< std::endl;

	//If it finds here, return -2 -->always stores into $2
	return -2;

	//If nothing found return -1
	return -1;
}

std::ostream& ast_context::get_stream() {
	return stream;
}

std::string ast_context::make_label(std::string base) {
	return "$"+base+"_"+std::to_string(makeNameUnq++);
}

void ast_context::flush_parameters() {

}

void ast_context::insert_global(std::string in_type, std::string in_id, int in_reg) {
	symbol_vector* temp = new symbol_vector;
	temp->symbol_id = in_id;
	temp->symbol_type = in_type;
	temp->reg_num = in_reg;

	if ((unsigned)in_reg > global_variables.size()) {
		global_variables.push_back(temp);
	} else {
		global_variables.at(in_reg) = temp;
	}
}

void ast_context::insert_param_id(unsigned int param_num, std::string id) {
	if (param_num > 4) {
		stream << "Do not support more than four parameters" << std::endl;
		exit(EXIT_FAILURE);
	}

	parameters_ids.at(param_num) = id;
}

std::string ast_context::get_param_id(unsigned int param_num) {
	return parameters_ids.at(param_num);
}

std::string ast_context::insert_break() {
	break_number++;
	return "$Break_L"+std::to_string(break_number-1);
	break_number++;
}

std::string ast_context::get_break() {
	return "$Break_L"+std::to_string(break_number);
}

int ast_context::get_current_func() {
	return function_num;
}
