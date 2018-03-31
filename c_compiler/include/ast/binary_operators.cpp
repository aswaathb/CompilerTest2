#include "binary_operators.hpp"
#include <assert.h>
#include "context.hpp"


BinaryExpression::BinaryExpression(const Expression *_left, const Expression *_right, std::string _op)
    : left(_left), right(_right), op(*_op) {}

/* GETTERS */

std::string BinaryExpression::getNodeType() const {
  return "BinaryExpression";
}
std::string AssignmentExpression::getNodeType() const {
  return "AssignmentExpression";
}
std::string BinaryExpression::getDetails() const {
   return " op=\"" + getOp() + "\" " + Node::getDetails();
}

std::string BinaryExpression::getOp() const { return op; };
std::vector<const baseNode *> BinaryExpression::getChildren() const {
  return {left, right};
}

std::vector<std::string> BinaryExpression::getTypeVec() const {
  std::vector<std::string> valA,valB;

  valA = left->getTypeVec();
  valB = right->getTypeVec();
  for (int i = 0; i < 4; i++){
    assert(valA[i]==valB[i]);
  }
  return valA;
}


/* PRINT ASSEMBLY */

Context BinaryExpression::generate_assembly(Context ctxt, int d) const {


  std::string end = "bend" + genUniqueID();
  if (!(op=="&&" || op=="||")){
    // Compile the left into a specific register, no short circuiting required.
    getLeft()->generate_assembly(ctxt,3);

    ctxt.push(3);
    getRight()->generate_assembly(ctxt,2);
    ctxt.pop(3);
  }
  else if (op=="||"){
    // SHORT CIRCUITING-> If either side !=0, set to 1

    // LHS
    getLeft()->generate_assembly(ctxt,3);
    ctxt.ss() << "\tsltu\t$" << d << ",$0,$3" <<" # checking if left > zero"    << std::endl;
    ctxt.ss() << "\tbeq\t$"  << d << ",1," << end <<" # then short circuit"     << std::endl;
    ctxt.ss() << "\tnop"                             s                          << std::endl;

    // RHS
    ctxt.push(3);
    getRight()->generate_assembly(ctxt,2);
    ctxt.pop(3);
    ctxt.ss() << "\tsltu\t$" << d << ",$0,$2" <<" # checking if right > zero"   << std::endl;
    ctxt.ss() << "\tbeq\t$"  << d << ",1," << end << " # then short circuit"    << std::endl;
    ctxt.ss() << "\tnop"                                                        << std::endl;
    ctxt.ss() << end << ":"                                                     << std::endl;
  }
  else if (op=="&&"){
    // SHORT CIRCUITING-> If either side = 0, set to 0

    // LHS
    getLeft()->generate_assembly(ctxt,3);
    ctxt.ss() << "\txor\t$" << d << ",$3,$0"                                    << std::endl;
    ctxt.ss() << "\tsltu\t $" << d << ",$0,$3" << " # checking if left > zero"  << std::endl;
    ctxt.ss() << "\tbeq\t$"  << d << ",$0," << end << " # if=0, short circuit"  << std::endl;
    ctxt.ss() << "\tnop"                                                        << std::endl;
    ctxt.pop(3);

    // RHS
    getRight()->generate_assembly(ctxt,2);
    ctxt.pop(3);
    ctxt.ss() << "\txor\t$" << d << ",$2,$0"                                    << std::endl;
    ctxt.ss() << "\tsltu\t $" << d << ",$0,$2" << " # checking if right < 1"    << std::endl;
    ctxt.ss() << "\tbeq\t$"  << d << ",$0," << end << " # if=0, short circuit"  << std::endl;
    ctxt.ss() << "\tnop"                                                        << std::endl;
    ctxt.ss() << end << ":"                                                     << std::endl;
  }


/*
    NORMAL CASES
*/

  // Arithmetic
  if (op == "+"){
    ctxt.ss() << "\tadd\t$" << d << ",$3,$2" << " # add $3 and $2 to $" << d    << std::endl;
  } else if (op=="-"){
    ctxt.ss() << "\tsub\t$" << d << ",$3,$2" << " # sub $3-$2 to $" << d        << std::endl;
  } else if (op=="*"){
    ctxt.ss() << "\tmul\t$" << d << ",$3,$2" << " # mul $3*$2 to $" << d        << std::endl;
  } else if (op=="/"){
    ctxt.ss() << "\tdiv\t$" << d << ",$3,$2" << " # div $3/$2to $" << d         << std::endl;
  } else if (op=="%"){
    ctxt.ss() << "\tdiv\t$" << d << ",$3,$2" << " # first div $3/$2"            << std::endl;
    ctxt.ss() << "\tmfhi\t$" << d << " # get modulo component $3%$2 to $" << d  << std::endl;
  }


  // Binary
  else if (op=="^"){
    ctxt.ss() << "\txor\t$" << d << ",$3,$2" << " # $3xor$2 to $" << d          << std::endl;
  }
  else if (op=="&"){
    ctxt.ss() << "\tand\t$" << d << ",$3,$2" << " # $3and$2 to $" << d          << std::endl;
  }
  else if (op=="|"){
    ctxt.ss() << "\tor\t$" << d << ",$3,$2" << " # $3or$2 to $" << d            << std::endl;
  }


  // Relational
  else if (op=="<"){
    ctxt.ss() << "\tsltu\t $" << d << ",$3,$2"                                  << std::endl;
  }
  else if (op==">"){
    ctxt.ss() << "\tsgtu\t $" << d << ",$3,$2"                                  << std::endl;
  }
  else if (op=="<="){
    ctxt.ss() << "\tsleu\t $" << d << ",$3,$2"                                  << std::endl;
  }
  else if (op==">="){
    ctxt.ss() << "\tsgeu\t $" << d << ",$3,$2"                                  << std::endl;
  }


  // Equality
  else if (op=="=="){
    ctxt.ss() << "\txor\t $3,$3,$2" << " # left[xor]right"                      << std::endl;
    ctxt.ss() << "\tsltu\t $" << d << ",$3,1"                                   << std::endl;
  } else if (op=="!="){
    ctxt.ss() << "\txor\t $3,$3,$2" << " # xor left[xor]right"                  << std::endl;
    ctxt.ss() << "\tsltu\t $" << d << ",$0,$3"                                  << std::endl;

  } else {
    ctxt.ss() << "### INVALID OPERATOR -> \'" << op << "\' <-  CHECK AGAIN  (OR IT ISNT WORKING xD)" << std::endl;
  }


  return ctxt;
}




Context AssignmentExpression::generate_assembly(Context ctxt, int d) const {
  if (op == "=") {
    getRight()->generate_assembly(ctxt);
    if (getLeft()->getNodeType()=="SquareOperator"){
      ctxt.ss() << "\tmove\t$11,$" << 2                     << std::endl;
      getLeft()->getChildren()[1]->generate_assembly(ctxt,8);
      ctxt.storeVariable(getLeft()->getId(),8,11);
    }
    else {
      ctxt.storeVariable(getLeft()->getId(), 2);
    }
    return ctxt;
  } else {
    // Store left in $3
    getLeft()->generate_assembly(ctxt,3);
    ctxt.push(3);
    // Store right in $2
    getRight()->generate_assembly(ctxt,2);
    ctxt.pop(3);
  }

  if (op == "*=") {
    ctxt.ss() << "\tmul\t$2,$3,$2" << " # mul $3*$2"        << std::endl;
  } else if (op == "/=") {
    ctxt.ss() << "\tdiv\t$2,$3,$2" << " # div $3/$2"        << std::endl;
  } else if (op == "%=") {
    ctxt.ss() << "\tmod\t$2,$3,$2" << " # mod $3%$2"        << std::endl;
  } else if (op == "+=") {
    ctxt.ss() << "\tadd\t$2,$3,$2" << " # add $3+$2"        << std::endl;
  } else if (op == "-=") {
    ctxt.ss() << "\tsub\t$2,$3,$2" << " # sub $3-$2"        << std::endl;
  } else if (op == "&=") {
    ctxt.ss() << "\tand\t$2,$3,$2" << " # and $3&$2"        << std::endl;
  } else if (op == "|=") {
    ctxt.ss() << "\tor\t$2,$3,$2" << " # or $3|$2"          << std::endl;
  } else if (op == "^=") {
    ctxt.ss() << "\txor\t$2,$3,$2" << " # xor $3^$2"        << std::endl;
  } else if (op == "<<=") {
    ctxt.ss() << "\tlsl\t$2,$3,$2" << " # << $3<<$2"        << std::endl;
  } else    (op == ">>=") {
    ctxt.ss() << "\tasr\t$2,$3,$2" << " # >> $3>>$2"        << std::endl;
  }
  ctxt.storeVariable(getLeft()->getId(), 2);
  return ctxt;
}

void BinaryExpression::python_print(std::ostream &stream) const {
    std::cout << left->python_print(stream); << op << right->python_print(stream); endline
};
