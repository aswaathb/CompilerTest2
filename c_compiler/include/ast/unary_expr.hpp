
#ifndef UNARY_EXPR_HPP
#define UNARY_EXPR_HPP

#include "baseNode.hpp"


class UnaryExpression : public Expression {
protected:
  const Expression * child;
  std::string op;
public:
  virtual ~UnaryExpression(){
    delete child;
  }
  UnaryExpression(const Expression * _child, std::string* _op) : child(_child), op(*_op) {};
  UnaryExpression(const Expression * _child) : child(_child) { op = ""; };
  UnaryExpression(std::string* _op) : op(*_op) {child = NULL ;  };
  virtual std::vector<const baseNode *> getChildren() const override { return {child}; }
  virtual std::string getNodeType() const override;
};


class PostfixExpr : public UnaryExpression {
public:
  PostfixExpr(const Expression * _child, std::string* _op) : UnaryExpression(_child,_op) {};
  PostfixExpr(const Expression * _child) : UnaryExpression(_child) {};
  
  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};



class PrefixExpr : public UnaryExpression {
std::string t;
public:
  PrefixExpr(const Expression * _child, std::string* _op) : UnaryExpression(_child,_op) { t = ""; };
  PrefixExpr(const Expression * _child) : UnaryExpression(_child) { t = ""; };
  PrefixExpr(std::string* _op) : UnaryExpression(_op) { t = ""; };
  PrefixExpr(std::string* _t, std::string* _op) : UnaryExpression(_op), t(*_t) {};

  std::string getT() const { return t; }
  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};


class CastExpr : public PrefixExpr {
public:
  CastExpr(const Expression * _child, std::string* _op) : PrefixExpr(_child,_op) {};
  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};


class FunctionCall : public PostfixExpr {
private:
  const ExprList * args;
public:
  FunctionCall(const Expression * _expr) : PostfixExpr(_expr), args(new ExprList({})) {};
  FunctionCall(const Expression * _expr, const List * _args) : PostfixExpr(_expr), args((const ExprList *)_args) {};

  virtual std::string getNodeType() const override;
  virtual std::string getId() const { return child->getId(); };
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
  virtual void setParamUses() const override;
};


class SquareOperator : public PostfixExpr {
private:
  const Expression * arg;
public:
  SquareOperator(const Expression * _expr) : PostfixExpr(_expr) {};
  SquareOperator(const Expression * _expr, const Expression * _arg) : PostfixExpr(_expr), arg(_arg) {};
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
  virtual std::string getNodeType() const override { return "SquareOperator";} ;
  virtual std::vector<const baseNode *> getChildren() const override { return {child,arg};}
  virtual std::string getId() const override { return child->getId(); };
};


class StructOperator : public PostfixExpr {
private:
  std::string id;
public:
  StructOperator(const Expression * _expr, std::string *_id) : PostfixExpr(_expr), id(*_id) {};
};


class DotOperator : public StructOperator {
public:
  DotOperator(const Expression * _expr, std::string *_id) : StructOperator(_expr,_id) {};
};



class ArrowOperator : public StructOperator {
public:
  ArrowOperator(const Expression * _expr, std::string *_id) : StructOperator(_expr,_id) {};
};


#endif
