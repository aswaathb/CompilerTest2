#ifndef VARIABLES_HPP
#define VARIABLES_HPP

#include "base_expr.hpp"
#include "types.hpp"
#include <sstream>

class Variable : public Expression {
private:
  std::string id;
  mutable int ptr = 0;
public:
  virtual ~Variable(){};

  Variable(const std::string* _id) : id(*_id) {};
  Variable(const std::string* _id, bool _ptr) : id(*_id), ptr(_ptr) { };
  
  virtual std::string getNodeType() const override;
  virtual std::string getId() const override;
  void setPtr() const { ptr++; }
  int getPtr() const { return ptr; }
  virtual void python_print(std::ostream &stream) const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};

class Parameter : public Variable {
public:
  virtual ~Parameter(){};
  Parameter(const std::string* _id) : Variable(_id) {}
  virtual std::string getNodeType() const override;
};


#endif

