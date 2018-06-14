
#include "constant.hpp"
#include <iostream>
#include <bitset>
#include <sstream>


Constant::Constant(const std::string &_value_in) : value_in(_value_in){};

IntConstant::IntConstant(const std::string &_value_in) : Constant(_value_in) {
  val = std::stoi(_value_in);
};

CharConstant::CharConstant(const std::string &_value_in) : Constant(_value_in) {
}

FloatConstant::FloatConstant(const std::string &_value_in) : Constant(_value_in) {
  float val = std::stof(_value_in);
  union FloatInt
  {
      float myfloat;
      int myint;
  };

  FloatInt fi;
  fi.myfloat = val;
  std::bitset<32> second(fi.myint);
  std::stringstream ss;
  ss << std::hex << "0x" << fi.myint;
  value_in = ss.str();
};

DoubleConstant::DoubleConstant(const std::string &_value_in) : Constant(_value_in) {
  val = std::stod(_value_in);
};

StringLiteral::StringLiteral(const std::string &_value_in) : Constant(_value_in){
  baseNode::addString(_value_in);
};

/* 
  GETTERS 
*/

std::string Constant::getNodeType() const       { return "Constant"; }
std::string StringLiteral::getNodeType() const  { return "StringLiteral"; }
std::string FloatConstant::getNodeType() const  { return "FloatConstant"; }
std::string DoubleConstant::getNodeType() const { return "DoubleConstant"; }
std::string IntConstant::getNodeType() const    { return "IntConstant"; }
std::string CharConstant::getNodeType() const   { return "CharConstant"; }


/* 
  PRINT ASSEMBLY 
*/
Context IntConstant::generate_assembly(Context ctxt, int d) const {
  ctxt.ss() << "\tli $" << d <<"," << getValue() << " # Loading into an active register"   << std::endl;
  return ctxt;
}

Context CharConstant::generate_assembly(Context ctxt, int d) const {
  ctxt.ss() << "\tli $" << d <<"," << getValue() << " # Loading into an active register"   << std::endl;
  return ctxt;
}

Context FloatConstant::generate_assembly(Context ctxt, int d) const {
  ctxt.ss() << "\tli $" << d <<"," << getValue() << " # Loading into an active register"   << std::endl;
  return ctxt;
}

Context StringLiteral::generate_assembly(Context ctxt, int d) const {
  std::string strloc = ctxt.getString(getValue());
  ctxt.ss() << "\tlui $" << d <<",%hi(" << strloc << ") # Loading into an active register" << std::endl;
  ctxt.ss() << "\taddiu\t$" << d << ",$" << d << ",%lo(" << strloc <<  ")"                 << std::endl;
  return ctxt;
}

// /* 
//   PRINT PYTHON 
// */
// void Constant::python_print(std::ostream &stream) const {
//   stream << "NEEDS IMPLEMENTATION" << std::endl;
// }

