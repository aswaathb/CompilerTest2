#include "base_expr.hpp"


std::string Expression_Null::getNodeType() const    { return "Expression_Null"; };
std::string TernaryExpression::getNodeType() const  { return "TernaryExpression"; };

std::vector<const baseNode *> TernaryExpression::getChildren() const{
  return {first,second,third};
}


Context TernaryExpression::generate_assembly(Context ctxt, int d) const {
    std::string ID = genUniqueID();
    std::string 3true  = "ternary_true"  + ID;
    std::string 3false = "ternary_false" + ID;
    std::string 3end   = "ternary_end"   + ID;

    ctxt = first->generate_assembly(ctxt,d);
    // If cond=0, goto false
    ctxt.ss() << "\tbeq\t$0,$" << d << "," << 3false  << std::endl;
    // If cond=0, exe true
    ctxt = second->generate_assembly(ctxt,d);

    ctxt.ss() << "\tj\t" << 3end                      << std::endl;
    ctxt.ss() << "\tnop"                              << std::endl;
    ctxt.ss() << 3false  << ":"                       << std::endl;
    // exe false clause
    ctxt = third->generate_assembly(ctxt,d);
    // end label
    ctxt.ss() << 3end  << ":"                         << std::endl;
    return ctxt;
}

void Expression::python_print(std::ostream& stream) const {
  if (!parser) {
    baseNode::python_print(stream);
  }
}
