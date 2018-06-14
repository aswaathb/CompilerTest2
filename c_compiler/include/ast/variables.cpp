#include "variables.hpp"


/* GETTERS */

std::string Variable::getNodeType() const { return "Variable"; }
std::string Parameter::getNodeType() const { return "Parameter"; }

std::string Variable::getId() const { return id; };


/* PRNT ASSEMBLY */
Context Variable::generate_assembly(Context ctxt, int d) const {
  try{
    ctxt.loadVariable(id,d);
    //ctxt.ss() << "\tlw $" << d << "," << ctxt.getVariable(id) << "($fp)" << " # load var: " << id << std::endl;
  }
  catch(std::out_of_range& e){
    std::cerr << "error - out of range" << std::endl;
    std::terminate();
  }
  return ctxt;
}


// /* PRINT PYHTON */

// void Variable::python_print(std::ostream &stream) const {
//   stream << "VARIABLE NEEDS TO BE IMPLEMENTED" << std::endl;
// }
