#ifndef BINARY_OPERATORS_HPP
#define BINARY_OPERATORS_HPP

#include "base_expr.hpp"

class BinaryExpression : public Expression {
private:
  const Expression * left;
  const Expression * right;
protected:
  std::string op;
public:

  BinaryExpression(const Expression * _left, const Expression * _right, std::string * _op);

  virtual std::vector<std::string> getTypeVec() const override;

  virtual std::string getNodeType() const override;

  virtual std::string getDetails() const override;

  std::string getOp() const;

  virtual std::vector<const baseNode *> getChildren() const;

  const Expression * getLeft() const { return left;};

  const Expression * getRight()const { return right;};

  virtual Context generate_assembly(Context ctxt, int d = 2) const override;

  virtual void python_print(std::ostream& stream) const override;

};

class AssignmentExpression : public BinaryExpression {
public:
  using BinaryExpression::BinaryExpression;

  virtual std::string getNodeType() const override;

  virtual Context generate_assembly(Context ctxt, int d = 2) const override;

};


#endif