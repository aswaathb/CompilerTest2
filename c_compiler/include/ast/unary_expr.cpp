#include "unary_expr.hpp"


std::string UnaryExpression::getNodeType() const    { return "UnaryExpression"; }
std::string PostfixExpr::getNodeType() const        { return "PostfixExpr";     }
std::string PrefixExpr::getNodeType() const         { return "PrefixExpr";      }
std::string CastExpr::getNodeType() const           { return "CastExpr";        }
std::string FunctionCall::getNodeType() const       { return "FunctionCall";    }


void FunctionCall::setParamUses() const {
  for (auto it: args->getChildren()){
    childParams.push_back(it->getId());
  }
}


Context FunctionCall::generate_assembly(Context ctxt, int d) const {

  ctxt.ss() << "\tmove\t$16,$3" << " # preserving $3"                 << std::endl;

  int i = 0;
  int j = 16;
  for (auto it: args->getChildren()){
    if (i<4){
      it->generate_assembly(ctxt);
      ctxt.ss() << "\tmove\t$" << std::to_string((i++)+4) << ",$2"    << std::endl;
    }
    else {
      it->generate_assembly(ctxt);
      ctxt.ss() << "\tsw\t$2," << (i++)*4 << "($sp)"                  << std::endl;
      j+=4;
    }
  }
  
  //Dont know what this is for, but needs to be added on...
  ctxt.ss() << "\t.option\tpic0"                                      << std::endl;
  ctxt.ss() << "\tjal\t" << getId()                                   << std::endl;
  ctxt.ss() << "\tnop"                                  << std::endl  << std::endl;
  ctxt.ss() << "\t.option\tpic2"                                      << std::endl;
  ctxt.ss() << "\tmove\t$3,$16" << " # preserving $3 "                << std::endl;
  ctxt.ss() << "\tmove\t$" << d << ",$2"                              << std::endl;

  return ctxt;
}



Context PrefixExpr::generate_assembly(Context ctxt, int d) const {
  
  int s = 1;
  if (op=="++"){
    ctxt.ss() << "#" << child->getId() << std::endl;
    Var v = ctxt.getVariable(child->getId());
    if (v.ptr){
      s = 4;
    }
    child->generate_assembly(ctxt,d);
    ctxt.ss() << "\taddu\t$" << d << ",$" << d << "," << s            << std::endl;
    
    ctxt.storeVariable(child->getId(),d);
  }

  else if (op=="--"){
    child->generate_assembly(ctxt,d);

    ctxt.ss() << "\tsub\t$" << d <<",$" << d << "," << s              << std::endl;
    ctxt.storeVariable(child->getId(),d);
  }
  else if (op=="&"){
    ctxt.getAddress(child, d);
  }
  else if (op=="*"){
    child->generate_assembly(ctxt,d);

    ctxt.ss() << "\tlw\t$" << d << ",($" << d << ")"                  << std::endl;
  }
  else if (op=="+"){
    child->generate_assembly(ctxt,d);
  }
  else if (op=="-"){
    child->generate_assembly(ctxt,d);
    ctxt.ss() << "\tsubu\t$" << d << ",$0,$" << d                     << std::endl;
  }
  else if (op=="~"){
    child->generate_assembly(ctxt,d);
    ctxt.ss() << "\tnot\t$"<< d <<",$" << d                           << std::endl;
  }
  else if (op=="!"){
    child->generate_assembly(ctxt,d);
    ctxt.ss() << "\tsgeu\t$" << d << ",$0,$" << d                     << std::endl;
  }
  
  
  else if (op=="sizeof"){
    std::string type = getT();
    int ptr = 0;
    if (type==""){
      type = ctxt.getVarType(child->getId());
      ptr = ctxt.isPtr(child->getId());
    }
    
    ctxt.ss() << "# sizeof(" << type << ")"                           << std::endl;
    s = 4;
    
    if (ptr){
      s = 4;
    }
    else if (type=="double"){
      s = 8;
    }
    else if (type=="short"){
      s = 2;
    }
    else if (type=="char" || type=="void"){
      s = 1;
    }
    else {
      s = 4;
    }
    ctxt.ss() << "\tli\t$" << d << "," << s                           << std::endl;
  }
  else {
    ctxt.ss() << "# Prefix expression, op is \'" << op << "\'"        << std::endl;
  }
  return ctxt;
}




// Context SquareOperator::generate_assembly(Context ctxt, int d) const {

//   //???ctxt = arg->generate_assembly(ctxt,8);
//   int i = 0;
//   if (arg->getNodeType()=="IntConstant"){
//     i = std::stoi(arg->getId(),0,0);
//   }
//   else{
//     ctxt = arg->generate_assembly(ctxt,8);
//   }

//   // Take offset value from frame ptr  
//   std::string variableType = ctxt.getVarType(child->getId());
//   ctxt.ss() << "\t# Square operator, vartype: " << variableType                       << std::endl;
//   ctxt.ss() << "\tlw\t$" << d << "," << ctxt.getVarOffset(child->getId()) << "($fp)"  << std::endl;
//   if (variableType=="char"){
//     ctxt.ss() << "\taddu\t$" << d << ",$8,$" << d                                     << std::endl;
//     ctxt.ss() << "\tlb\t$" << d << ",0" << "($" << d << ")"                           << std::endl;  
//   }
//   else{
//     ctxt.ss() << "\tsll\t$8,$8,2"                                                     << std::endl;
//     ctxt.ss() << "\taddu\t$" << d << ",$8,$" << d                                     << std::endl;
//     ctxt.ss() << "\tlw\t$" << d << ",0" << "($" << d << ")"                           << std::endl;
//   }
  
//   return ctxt;
// }


// Context CastExpr::generate_assembly(Context ctxt, int d) const {
  
//   return ctxt;
// }


Context PostfixExpr::generate_assembly(Context ctxt, int d) const {
  int s = 1;
  Var variable = ctxt.getVariable(child->getId());
  if (variable.ptr){
    s = 4;
  }
  if (op=="++"){
    child->generate_assembly(ctxt,d);

    ctxt.ss() << "\tadd\t$4, $" << d << "," << s                      << std::endl;
    ctxt.storeVariable(child->getId(),4);
  }
  else if (op=="--"){
    child->generate_assembly(ctxt,d);
    
    ctxt.ss() << "\tsub\t$4, $" << d << "," << s                      << std::endl;
    ctxt.storeVariable(child->getId(),4);
  }
  
  return ctxt;
}
