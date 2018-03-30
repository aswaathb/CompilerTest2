#ifndef CONSTANT_HPP
#define CONSTANT_HPP

#include "base_expr.hpp"

class Constant : public Expression {
protected:
  std::string value_in;
public:
  virtual ~Constant(){};
  Constant(const std::string &_value_in);

  virtual std::string getNodeType() const override;

  virtual std::string getValue() const { return value_in; };
  virtual std::string getId() const override {return value_in;};
  virtual std::vector<const baseNode *> getChildren() const override {return {};}
  virtual void python_print(std::ostream &stream) const override;
};

class StringLiteral : public Constant {
public:
  virtual ~StringLiteral(){};
  StringLiteral(const std::string &_value_in);
  std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override; 
};

class IntConstant : public Constant {
private:
  int val;

public:
  virtual ~IntConstant(){};
  IntConstant(const std::string &_value_in);
  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override; 
};

class FloatConstant : public Constant {
private:
  float val;
public:
  virtual ~FloatConstant(){};
  FloatConstant(const std::string &_value_in);
  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override; 
};

class DoubleConstant : public Constant {
private:
  double val;
public:
  virtual ~DoubleConstant(){};
  DoubleConstant(const std::string &_value_in);
  virtual std::string getNodeType() const override;
};

class CharConstant : public Constant {
public:
  virtual ~CharConstant(){};
  CharConstant(const std::string &_value_in);
  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override; 
};

#endif
