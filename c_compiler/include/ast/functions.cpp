#include "functions.hpp"


Function::Function(const baseNode *_type, const baseNode *_dec, const baseNode *_stat)
    : type((const Type *)_type), declarator((const FunctionDeclarator *)_dec), statement((const CompoundStatement *)_stat) {
        id = declarator->getId(); //! Returns id of first child, won't have declaration lists of functions
      };

/*
   GETTERS
 */
std::vector<const baseNode *> Function::getChildren() const{
  return {statement};
}

std::string Function::getType() const { return type->getTypename(); }

std::string Function::getHeader() const {
  return "<" + getNodeType() + " id=\"" + id + "\" type=\"" + type->getTypename() + "\" " + getDetails() + " >";
}

std::string Function::getDetails() const {
  std::string params = getParamString();
  if (params!=""){
    params = "params=\"" + params + "\" ";
  }
  return params + baseNode::getDetails();
}

std::vector<std::string> Function::getParams() const {
  std::vector<std::string> out;
  for (auto it: declarator->getParams()->getChildren()){
    out.push_back(it->getId());
  }
  return out;
}

std::string Function::getParamString() const {
  std::string out;
  for (auto it: getParams()){
    out += it + ",";
  }
  if (out!=""){
    out = out.substr(0, out.size()-1);
  }
  return out;
}


void Function::setChildDefs() const {
  baseNode::setChildDefs();
}


/*
   END OF GETTERS
*/


/* 
    PRINT ASSEMBLY 
*/

Context Function::generate_assembly(Context ctxt, int d) const{
  Context return_ctxt = ctxt;
  std::vector<std::string> vars = getChildDefs();
  int i = 0;
  std::vector<std::string> args = getChildParams();
  int args_size = 16;
  if (args.size()>0){
    for (auto &it: args){
      if (i>3){
        args_size+=4;
      }
      i++;
    }
  }
  
  int variableSize = vars.size()*4 + getParams().size()*4;
  int pad = 0;
  int total_size = args_size+variableSize + 8;
  if (total_size%8 != 0){pad = 4; }
  
  
  int local_offset = total_size+8-variableSize;
  ctxt.setOffset(local_offset);

  i = 0;
  for (auto &it : getParams()){
    if (i==4){
      ctxt.setOffset(total_size+8+pad+16);
    }
    ctxt.ss() << "# param " << i << ": " << it << std::endl;
    ctxt.assignVariable(it,"int");
    if (i<4){
      local_offset = ctxt.getOffset();
    }
    i++;
  }

  ctxt.setOffset(local_offset);
  std::string fname = id;
  
  ctxt.ss() << "\t.globl\t" << fname	              << std::endl;
  ctxt.ss() << "\t.set\tnomips16"                   << std::endl;
  ctxt.ss() << "\t.set\tnomicromips"                << std::endl;
  ctxt.ss() << "\t.ent\t" << fname	                << std::endl;
  ctxt.ss() << "\t.type\t" << fname <<", @function" << std::endl;
  ctxt.setF(fname);
  
  
  // Label for the function
  ctxt.ss() << fname << ":" << std::endl;
  ctxt.ss() << "\t.frame\t$fp,"<< total_size+8+pad << ",$31\t\t# vars= "<< variableSize <<", regs= 1/0, args= " << args_size << ", gp= 0" << std::endl;
  
  // .mask for size of int?
  ctxt.ss() << "\t.mask\t0x40000000,-4" << std::endl;
  // .fmask for sixe of float?
  ctxt.ss() << "\t.fmask\t0x00000000,0" << std::endl;
  // additional lines that is required
  ctxt.ss() << "\t.set\tnoreorder"      << std::endl;
  ctxt.ss() << "\t.set\tnomacro"        << std::endl;
  
  // Reserve space on the stack for the frame
  ctxt.ss() << "\taddiu\t$sp,$sp,-" << total_size+8+pad << std::endl;
  
  // Store return address
  ctxt.ss() << "\tsw\t$31,"<< total_size+4-variableSize << "($sp)" << std::endl;
  
  // Store frame ptr
  ctxt.ss() << "\tsw\t$fp,"<< total_size-variableSize << "($sp)" << std::endl;
  
  // Store result
  ctxt.ss() << "\tsw\t$16,"<< total_size-4-variableSize << "($sp)" << std::endl;
  
  // FPtr==SPtr
  ctxt.ss() << "\tmove\t$fp,$sp" << std::endl;
  
  
  i = 4;
  for (auto &it : getParams()){
    if (i<8){
      ctxt.ss() << "\tmove\t$2,$" << std::to_string(i++) << std::endl;
      ctxt.storeVariable(it);
    }
    // Rest of params will already be on stack so no need to store it.
  }
  

  ctxt = baseNode::generate_assembly(ctxt);
  
/* 
    ENDING BLOCK
*/
  ctxt.ss() << fname << "the_end:"                                  << std::endl;
  // Move FPtr->SPtr
  ctxt.ss() << "\tmove $sp,$fp"                                     << std::endl;
  // Load return address
  ctxt.ss() << "\tlw\t$31," << total_size+4-variableSize <<"($sp)"  << std::endl;
  // Load frame ptr
  ctxt.ss() << "\tlw\t$fp," << total_size-variableSize <<"($sp)"    << std::endl;
  // Load value in $16
  ctxt.ss() << "\tlw\t$16," << total_size-4-variableSize <<"($sp)"  << std::endl;
  // Unallocate frame
  ctxt.ss() << "\taddiu\t$sp,$sp," << total_size+8+pad              << std::endl;
  ctxt.ss() << "\tj\t$31\n\tnop"                       << std::endl << std::endl;
  
  ctxt.ss() << "\t.set\tmacro"                                      << std::endl;
  ctxt.ss() << "\t.set\treorder"                                    << std::endl;
  ctxt.ss() << "\t.end\t" << fname                                  << std::endl;
  ctxt.ss() << "\t.size\t" << fname << ", .-" << fname              << std::endl;

  return return_ctxt;
}

/* 
    PRINT PYTHON 
*/
void Function::python_print(std::ostream &stream) const {
    stream << " FUNCTION NEEDS TO BE IMPLEMENTED" << std::endl; 

}
