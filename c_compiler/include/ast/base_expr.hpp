#ifndef BASE_EXPR_HPP
#define BASE_EXPR_HPP

#include "baseNode.hpp"


class Statement : public baseNode {
public:
  virtual ~Statement(){};
  virtual std::string getNodeType() const = 0;
};

//! Abstract base class for expressions
class Expression : public baseNode {
public:
  virtual ~Expression(){};
  virtual std::string getNodeType() const =0;
  virtual std::vector<std::string> getTypeVec() const { return std::vector<std::string>{"Int","0x0","0x0","Signed"}; };
  virtual std::string getId() const { return "No id"; }
  virtual const Expression * add(const Expression * child) const {(void)child; return this;};
  virtual void python_print(std::ostream& stream) const override;
};

class Expression_Null : public Expression {
public: 
  Expression_Null(){};
  virtual ~Expression_Null(){};
  virtual std::string getNodeType() const override;
  virtual std::vector<const baseNode *> getChildren() const override { return {}; }
};

//! 
class TernaryExpression : public Expression {
private:
  const Expression * first;
  const Expression * second;
  const Expression * third;
public:
  ~TernaryExpression(){
    delete first;
    delete second;
    delete third;
  }
  virtual std::string getNodeType() const override;
  // virtual void print_c() const override;
  TernaryExpression(const Expression * one, const Expression * two, const Expression * three)
    : first(one), second(two), third(three) {}
  virtual std::vector<const baseNode *> getChildren() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};


#endif
