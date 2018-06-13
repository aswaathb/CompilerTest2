#include "types.hpp"
#include <assert.h>

Type::Type(int i) {
  if (i<0xC){
    type = i;
  }
  else if (i<0x51){
    qual = i;
  }
  else {
    spec = i;
  }
};

Type::Type(bool b) : sign(b) {};


unsigned Type::getType() const {
  return type;
}

std::vector<std::string> Type::getTypeVec() const {
  std::vector<std::string> typeVector;
  std::stringstream ss;
  switch((Type_specifier)type){
    case None:
      typeVector.push_back("none");
      break; 
    case Int: 
      typeVector.push_back("int");
      break; 
    case Void: 
      typeVector.push_back("void");
      break; 
    case Char: 
      typeVector.push_back("char");
      break; 
    case Float: 
      typeVector.push_back("float");
      break; 
    case Double: 
      typeVector.push_back("double");
      break;
    case LongDouble: 
      typeVector.push_back("longdouble");
      break;
    case Short: 
      typeVector.push_back("short");
      break; 
    case Long: 
      typeVector.push_back("long");
      break; 
    case LongLong: 
      typeVector.push_back("longlong");
      break; 
  }
  ss << std::hex << "0x" << spec;
  ss.clear();
  ss << std::hex << "0x" << qual << std::dec;

  typeVector.push_back(ss.str());
  typeVector.push_back(ss.str());
  if (sign){
    typeVector.push_back("signed");
  } else {
    typeVector.push_back("unsigned");
  }
  return typeVector;
}

std::string Type::getTypename() const {
  std::stringstream ss;
  switch((Type_specifier)type){
    case None      :
      ss << "none";
      break; 
    case Int       : 
      ss << "int";
      break; 
    case Void      : 
      ss << "void";
      break; 
    case Char      : 
      ss << "char";
      break; 
    case Float     : 
      ss << "float";
      break; 
    case Double    : 
      ss << "double";
      break;
    case LongDouble: 
      ss << "longdouble";
      break;
    case Short     : 
      ss << "short";
      break; 
    case Long      : 
      ss << "long";
      break; 
    case LongLong  : 
      ss << "longlong";
      break; 
  }
  ss << std::hex << " 0x" << spec;
  ss << std::hex << " 0x" << qual << std::dec;
  
  if (sign){
    //Add space so strings done merge
    ss << " signed";
  } else {
    ss << " unsigned";
  }
  return ss.str();
}


void Type::add(const Type* in) const {
  unsigned type_in = in->getType();
  unsigned qual_in = in->getQ();
  unsigned spec_in = in->getS();
  bool     sign_in = in->getSign();
  
  if (sign){ // if signed, the sign_in value considered
    sign = sign_in;
  }
  if (qual_in){
    assert(qual==0);
    qual = qual_in; 
  }
  if (spec_in){
    assert(spec==0);
    spec = spec_in;
  }
  if (type==0){
    type = type_in;
  }
  
  else if (type_in>6){

    if (type==0x1){ // for int
      type = type_in;
    }
    else if (type==0x5){ //for double
      type = type_in;
    }
    else if (type == Long){
      if (type_in == Long){
        type = LongLong;
      }
    }
  }

  return;
}



void Type::setPtr() const {
  ptr = true;
}