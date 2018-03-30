#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include "baseNode.hpp"
#include "base_expr.hpp"
#include "declaration.hpp"


class ExprStatement : public Statement {
private:
  const Expression *expr;
public:
  ExprStatement(const Expression *_expr) : expr(_expr){};
  ~ExprStatement(){};

  virtual std::string getNodeType() const override { return "ExprStatement"; };
  virtual std::vector<const baseNode *> getChildren() const override { return {expr}; }
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
  virtual void python_print(std::ostream& stream) const override;
};

/*
   Condition is type Expression
   Result is type Statement
*/
class ConditionalStatement : public Statement {
protected:
  const Statement *stat1;

public:
  virtual ~ConditionalStatement() {
    delete stat1;
  };

  ConditionalStatement(const Statement *_stat1) : stat1(_stat1) {};

  virtual std::string getNodeType() const { return "ConditionalStatement"; };
  virtual void python_print(std::ostream &stream) const;

  virtual std::vector<const baseNode *> getChildren() const override { return {stat1}; }
  virtual std::vector<const Expression *> getConditions() const = 0;
  virtual const Statement *getBody() const { return stat1; };
};

/*
 x no of DecLs, x no of Stats
*/
class CompoundStatement : public Statement {
private:
  const List *decl;
  const List *stat;

public:
  virtual ~CompoundStatement() {
    delete decl;
    delete stat;
  };
  CompoundStatement() : decl(new List({}) ), stat(new List({}) ) {};
  CompoundStatement(const List *_decl, const List *_stat) : decl(_decl), stat(_stat) {};

  virtual std::string getNodeType() const override;
  virtual std::vector<const baseNode *> getChildren() const override;
  virtual void python_print(std::ostream &stream) const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};


class SelectionStatement : public ConditionalStatement {
protected:
  const Expression *cond;
public:
  SelectionStatement(const Expression *_cond, const Statement *_stat)
      : ConditionalStatement(_stat), cond(_cond) {};
  
  virtual std::string getNodeType() const { return "SelectionStatement"; };
  virtual const Expression *getCondition() const;
  virtual std::vector<const Expression *> getConditions() const;
};

/*
    If cond is true, will exe stat
*/
class IfStatement : public SelectionStatement {
public:
  virtual ~IfStatement(){};
  virtual std::string getNodeType() const override;
  IfStatement(const Expression *_cond, const Statement *_stat)
      : SelectionStatement(_cond, _stat) {};

  virtual void python_print(std::ostream &stream) const;
};

/*
    If cond true, exe stat1, if cond false, exe stat2
*/
class IfElseStatement : public IfStatement {
private:
  const Statement *stat2;

public:
  IfElseStatement(const Expression *_cond, const Statement *_stat1, const Statement *_stat2)
      : IfStatement(_cond, _stat1), stat2(_stat2) {};

  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
  virtual std::vector<const baseNode *> getChildren() const override { return {stat1,stat2}; }
  virtual void python_print(std::ostream &stream) const;
};



class SwitchStatement : public SelectionStatement {
public:
  SwitchStatement(const Expression *_cond, const Statement *_stat)
      : SelectionStatement(_cond, _stat) {};

  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};


/*
    Unconditional jump to a label
 */
class JumpStatement : public Statement {
public:
  JumpStatement(){};
  virtual ~JumpStatement(){};

  virtual std::string getNodeType() const override;
  virtual void python_print(std::ostream& stream) const override;
};


class GotoStatement : public JumpStatement {
private:
  std::string targetLabel;

public:
  GotoStatement(const std::string label) : targetLabel(label){};
  virtual ~GotoStatement(){};
  
  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};


class ContinueStatement : public JumpStatement {
public:
  ContinueStatement(){};
  virtual ~ContinueStatement(){};

  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};



class BreakStatement : public JumpStatement {
public:
  BreakStatement(){};
  virtual ~BreakStatement(){};
  
  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};

/*!
    Requires an expression
 */
class ReturnStatement : public JumpStatement {
private:
  const ExprStatement *expr;

public:
  ReturnStatement(const ExprStatement *_expr) : expr(_expr){};

  virtual std::string getNodeType() const override;
  virtual std::vector<const baseNode *> getChildren() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};

class LabeledStatement : public Statement {
private:
  std::string id;
  const Statement *stat;
public:
  virtual ~LabeledStatement(){};
  LabeledStatement(std::string *_id, const Statement *_stat) : id(*_id), stat(_stat) {};

  std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};

class Case : public Statement {
private:
  const Expression *expr;
  const Statement *stat;

public:
  virtual ~Case(){};
  Case(const Expression *_expr, const Statement *_stat) : expr(_expr), stat(_stat){};

  std::string getNodeType() const override;    
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};


class Default : public Statement {
private: 
  const Statement *stat;
public:
  virtual ~Default(){};
  Default(const Statement *_stat) : stat(_stat) {};
  
  virtual std::string getNodeType() const override { return "Default";};
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};



class Iteration : public ConditionalStatement {
public:
  virtual ~Iteration(){};
  virtual std::string getNodeType() const;
  // virtual std::vector<const baseNode *> getChildren() const;
  // virtual std::vector<const Expression*> getConditions() const = 0;

  Iteration(const Statement *_stat) : ConditionalStatement(_stat) {}
  virtual std::vector<const baseNode *> getChildren() const = 0;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};


/*!
    exe stat as long as cond (type expression) is true
 */
class WhileStatement : public Iteration {
private:
  const Expression *cond;
public:
  virtual ~WhileStatement(){};
  
  virtual std::string getNodeType() const override;
  virtual std::vector<const Expression*> getConditions() const override { return {cond}; };

  WhileStatement(const Expression *_cond, const Statement *_stat)
      : Iteration(_stat), cond(_cond) {};
  virtual std::vector<const baseNode *> getChildren() const override;
  //virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};


/*
    exe stat  while ( cond(type expression) = true )
 */
class DoWhileStatement : public WhileStatement {
public:
  virtual ~DoWhileStatement(){};
  virtual std::string getNodeType() const override;

  DoWhileStatement(const Expression *_cond, const Statement *_stat) : WhileStatement(_cond, _stat) {};
  //virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};



class ForStatementBase : public Iteration {
protected:
  const ExprStatement *cond1;
public:
  virtual std::string getNodeType() const override;
  ForStatementBase(const ExprStatement *c1, const Statement *s1)
      : Iteration(s1), cond1(c1)  {};
  virtual std::vector<const Expression*> getConditions() const override {
    return {(const Expression*)cond1};
  };
  virtual std::vector<const baseNode *> getChildren() const override;
  // virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};

class ExprExprFor : public ForStatementBase {
protected:
  const ExprStatement *cond2;
public:
  virtual std::string getNodeType() const override;
  ExprExprFor(const ExprStatement *_cond1, const ExprStatement *_cond2, const Statement *_stat1)
      : ForStatementBase(_cond1, _stat1), cond2(_cond2) {};
  
  virtual std::vector<const Expression*> getConditions() const override {
    return {(const Expression*)cond2, (const Expression*)cond1 };
  };
  virtual std::vector<const baseNode *> getChildren() const override;
};

class ExprExprExprFor : public ExprExprFor {
private:
  const Expression *cond3;
public:
  virtual std::string getNodeType() const override;
  ExprExprExprFor(const ExprStatement *_cond1, const ExprStatement *_cond2, const Expression *_cond3, const Statement *_stat1)
      : ExprExprFor(_cond1, _cond2, _stat1), cond3(_cond3)  {};
  
  virtual std::vector<const Expression*> getConditions() const override {
    return {(const Expression*)cond2, cond3, (const Expression*)cond1 };
  };
  virtual std::vector<const baseNode *> getChildren() const override;
};

class DecExprFor : public ForStatementBase {
protected:
  const Declaration *decl;
public:
  virtual std::string getNodeType() const override;
  DecExprFor(const Declaration *_decl, const ExprStatement *_cond1, const Statement *_stat1)
      :  ForStatementBase(_cond1, _stat1), decl(_decl)  {};
  
  virtual std::vector<const Expression*> getConditions() const override {
    return {(const Expression*)cond1};
  };
  virtual std::vector<const baseNode *> getChildren() const override;
  //virtual void python_print(std::ostream& stream) const override;
};

class DecExprExprFor : public DecExprFor {
private:
  const Expression *cond2;
public:
  virtual std::string getNodeType() const override;
  DecExprExprFor(const Declaration *_decl, const ExprStatement *_cond1, const Expression *_cond2, const Statement *_stat1)
      : DecExprFor(_decl, _cond1, _stat1), cond2(_cond2)  {};

  virtual std::vector<const Expression*> getConditions() const override {
    return {(const Expression*)cond1, cond2};
  };
  virtual std::vector<const baseNode *> getChildren() const override;
  // virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};


#endif
