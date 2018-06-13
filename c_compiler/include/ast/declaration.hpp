
#ifndef DECLARATION_HPP
#define DECLARATION_HPP


#include "baseNode.hpp"
#include "types.hpp"
#include "base_expr.hpp"


class DeclaratorBase : public baseNode {};


class Declarator : public DeclaratorBase {
const baseNode * child;
mutable int ptr = 0;
public:
  Declarator(const baseNode * _child) : child(_child) {};
  
  virtual ~Declarator(){};

  virtual std::string getNodeType() const override;
  virtual std::string getId() const override { return child->getId(); };
  virtual void setPtr() const { ptr = 1; }
  virtual int getPtr() const override { return ptr; }
  virtual void setChildDefs() const override;
  virtual void python_print(std::ostream &stream) const override;
  virtual std::vector<const baseNode *> getChildren() const override { return {child}; }
  virtual const List * getParams() const { return new List({}); }
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};

class InitDeclarator : public Declarator {
const Expression * expr;
public:
  InitDeclarator(const baseNode * _child, const Expression * _expr) : Declarator(_child), expr(_expr) {};
  virtual std::string getNodeType() const override;
  std::vector<const baseNode *> getChildren() const;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};

class ArrayDeclarator : public Declarator {
const Expression * expr;
public:
  ArrayDeclarator(const baseNode * _child, const Expression * _expr) : Declarator(_child), expr(_expr) { setPtr(); };
  virtual std::string getNodeType() const override;
  virtual void setChildDefs() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};

class FunctionDeclarator : public Declarator {
const List * func;
public:
  FunctionDeclarator(const baseNode * _child, const List * _func) : Declarator(_child), func(_func) {};
  virtual std::string getNodeType() const override;
  virtual const List * getParams() const override;
  virtual void python_print(std::ostream &stream) const override;
};

class Declaration : public DeclaratorBase {
private:
  const Type * type;
  const List * list;
public:
  Declaration(const Type * _type, const List * _list) : type(_type), list(_list){};
  virtual std::string getNodeType() const override;
  virtual std::string getTypename() const;
  virtual std::vector<std::string> getTypeVec() const;
  
  virtual const Type * getType() const { return type; };
  virtual std::string getId() const;
  virtual std::vector<const baseNode *> getChildren() const override;
  virtual std::vector<std::string> getChildDefs() const override;
  virtual void setChildDefs() const override;
  
  virtual void python_print(std::ostream &streams) const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};

#endif
