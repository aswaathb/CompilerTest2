#ifndef TYPES_HPP
#define TYPES_HPP

#include "baseNode.hpp"

#include <sstream>
#include <string>
#include <vector>


enum Type_specifier {
  None          = 0x0,
  Int           = 0x1,
  Void          = 0x2,
  Char          = 0x3,
  Float         = 0x4,
  Double        = 0x5,
  LongDouble    = 0x6,
  Short         = 0x7,
  Long          = 0x8,
  LongLong      = 0x9
};


enum Storage_specifier {
  Auto          = 0x10,
  Extern        = 0x20,
  Static        = 0x30,
  Typedef       = 0x40,
  Register      = 0x50
};

enum Type_qualifier {
  //Only one option.
  Const         = 0x100,
};


class Type : public baseNode {
  mutable unsigned type   = 0x1;  // Defaulted to int
  mutable unsigned qual   = 0;    // Defaulted to none
  mutable unsigned spec   = 0;    // Defaulted to none
  mutable bool sign       = true; // Defaulted to signed value
  mutable bool ptr        = false;// Defaulted to non pointer
public:
  Type(int i);
  Type(bool b);
  
  void add(const Type* in) const;
  
  virtual unsigned getType() const;
  virtual std::string getTypename() const;
  virtual std::vector<std::string> getTypeVec() const;
  
  virtual std::string getNodeType() const { return "Type"; };
  unsigned getQ() const                   { return qual; }
  unsigned getS() const                   { return spec; }
  bool getSign() const                    { return sign; }
  int getPtr() const                      { return ptr; };
  void setPtr() const;
};

#endif

