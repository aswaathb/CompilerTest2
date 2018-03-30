
#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <map>
#include <stdio.h>
#include "baseNode.hpp"

extern int UNIQUE_ID;

class baseNode;

std::string makeLabel(std::string base);
std::string genUniqueID();

struct Var {
  int reg;
  std::string type;
  int offset;
  bool global;
  bool pointer;

};

class Context {
private:
  std::map<std::string, Var> bindings;
  std::map<std::string, std::string> string_bindings;
  std::ostream *out;
  int offset = 0;
  std::string f = "";
  std::string b = "";
  std::string c = "";

public:
  Context(std::ostream *stream) { out = stream; };
  std::ostream& ss();

  void assignVariable(std::string id, std::string type);
  void assignVariable(std::string id, std::string type, int offin);
  void assignVariable(std::string id, std::string type, bool global);
  void assignVariable(std::string id, std::string type, bool global, bool pointer);
  void setVarPtr(std::string id);
  int isPtr(std::string id);

  Var  getVariable(std::string id);
  void loadVariable(std::string id, int d);
  void storeVariable(std::string id, int d = 2);
  void storeVariable(std::string id, int s, int d);
  std::string getVarType(std::string id);
  int getVarOffset(std::string id);

  void addString(std::string s);
  std::string getString(std::string s);
  void createStrings();

  // Control flow statements - hacky but robust and quick solution
  // Return
  void setF(std::string fname){ f = fname; }
  std::string getF(){ return f; }
  // Break
  void setBreak(std::string exitlabel) { b = exitlabel; }
  std::string getBreak() { return b; }
  // Continue
  void setContinue(std::string startlabel) { c = startlabel; }
  std::string getContinue() { return c; }
  // Set offset
  void setOffset(int i){ offset = i;}
  int getOffset() { return offset; }
  int getAddress(const baseNode * in, int d =2);


  void push(int reg);
  void pop(int reg);
};



#endif
