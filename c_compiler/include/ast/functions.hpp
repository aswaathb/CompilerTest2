#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "baseNode.hpp"
#include "statement.hpp"
#include "types.hpp"
#include <cmath>

// Components of a Function -> paramList and a statement
class Function : public baseNode {
private:
  const Type * type; 
  std::string id; 
  const FunctionDeclarator *declarator; 
  const CompoundStatement *statement;

public:
  virtual ~Function(){};

  Function(const Type *_type, const baseNode *_dec, const CompoundStatement *_stat);

  //! Getters
  virtual std::string getType() const;
  virtual std::string getNodeType() const;
  virtual std::string getDetails() const override;
  virtual std::vector<std::string> getParams() const;
  virtual std::string getParamString() const;
  virtual std::vector<const baseNode *> getChildren() const;
  
  virtual void setChildDefs() const override;

  //virtual void python_print(std::ostream &stream) const;
  virtual Context generate_assembly(Context ctxt, int d = 2) const;
};

#endif
