#include "topNode.hpp"

ast_top::ast_top() {
    save_math_op = false;
}

void ast_top::add_new(ast_base* in_base) {
	all_list.push_back(in_base);
}

void ast_top::xmlprint() const{
	for (unsigned int i =0; i < all_list.size(); i++) {
		all_list[i]->xmlprint(); 
		std::cout << std::endl;
	}
}

void ast_top::prettyprint(std::ostream &stream) const {
	for (unsigned int i =0; i < all_list.size(); i++) {
		all_list[i]->prettyprint(stream); 
		stream << std::endl;
	}
}

void ast_top::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const{
    context->get_stream()   <<  "\t.section .mdebug.abi32"    << std::endl
                            <<  "\t.previous"                 << std::endl
                            <<  "\t.nan    legacy"            << std::endl
                            <<  "\t.module fp=xx"             << std::endl
                            <<  "\t.module nooddspreg"        << std::endl
                            <<  "\t.abicalls"                 << std::endl;

    context->make_scope("Top_Level", "Top_Level", 0);
    
    
    for (unsigned int i =0; i < all_list.size(); i++) {
        all_list[i]->generate_assembly(context, registers, dest_reg); 
    }

}

void ast_top::allocate_memory(int& allocated_mem) const {
    for (unsigned int i =0; i < all_list.size(); i++) {
        all_list[i]->allocate_memory(allocated_mem); 
    }
}
