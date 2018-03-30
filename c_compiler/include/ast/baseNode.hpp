#ifndef BASENODE_HPP
#define BASENODE_HPP

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "context.hpp"

class Context;

/*
    TOKENS
*/

// GLOBAL VARIABLES USED TO MOVE VALUES //
//          LEXER <===> MAIN            //

// extern int len;
// extern int yylineno;
// extern int yylcolno;
// extern int yylsourcelino;
// extern std::string yylfile;

extern int yylex();

//! Abstract base class for ast node
class baseNode {
private:
//   static int tabcount;
//   static int changed;
  static std::vector<std::string> strings;
protected:
//   mutable int sourceline;
//   mutable int sourcecol;
//   static bool parser;
  // metadata;
  mutable std::vector<std::string> childDefs; //! Child defs and
  mutable std::vector<std::string> childParams; //! Child params
  mutable int p;

public:
  virtual ~baseNode();

  baseNode();
  //! Getters
  virtual std::string getNodeType() const;      //! Return the type of the node
  virtual std::string getDetails() const;

  virtual const baseNode * add(const baseNode * child) const;

  virtual int getPtr() const {return 0; };
  virtual std::vector<const baseNode *> getChildren() const { return {};}; //! If not overridden, return empty.
  virtual std::string getId() const;            //! Return the id of a variable, ideally should be pure virtual
  virtual std::vector<std::string> getChildDefs() const; //! Child defs is the most useful, especially for functions
  virtual std::vector<std::string> getChildParams() const;
  virtual void addString(std::string) const;
  virtual std::vector<std::string> getStrings() const;
  
  
  //! Recursive setter:
  virtual void setChildDefs() const;
  virtual void setParamUses() const;

  
  //! Printers
  virtual void python_print(std::ostream &stream) const;            //! Print python implicit recursive function
  virtual Context generate_assembly(Context ctxt, int d = 2) const; //! Print out mips assembly
  

  virtual void setPtr() const {};  

};

class List : public baseNode {
  //! Contains a vector of pointers to ast nodes
protected:
  mutable std::vector<const baseNode *> children;
public:
  //! Initialise using brace initializer new List({arg1, arg2, arg3})
  List(std::vector<const baseNode *> _children) : children(_children) {}
  
  //! Destructor for list
  virtual ~List();
  
  virtual const baseNode * add(const baseNode * child) const;
  
  
  //! Getters
  virtual std::string getNodeType() const;
  virtual std::vector<const baseNode *> getChildren() const;
  
  //! Printers
  virtual void python_print(std::ostream &stream) const;
};

//! MultiList is a node of the ast that can have any number of children
//! Name chosen to be list because listes can have other listes
//! or leaves
class MultiList : public List {
public:
  //! Initialise using brace initializer new MultiList({arg1, arg2, arg3})
  MultiList(std::vector<const baseNode *> _children) : List(_children) {}
  
  //! Getters
  virtual std::string getNodeType() const;
  
  //! Printers
  virtual void python_print(std::ostream &stream) const;
};



// The root of the ast
class TranslationUnit : public MultiList {
public:
  TranslationUnit(std::vector<const baseNode *> _child) : MultiList(_child) {}
  
  //! Getters
  virtual std::string getNodeType() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};

//! Scopes have a declaration list
class DeclarationList : public List {
public:
  DeclarationList(std::vector<const baseNode *> _branches) : List(_branches)  {}
  //! Getters
  virtual std::string getNodeType() const override;
  //! Printers
  virtual void python_print(std::ostream &stream) const override;
};

//! Functions have a parameter list.
class ParameterList : public DeclarationList {
public:
  ParameterList(std::vector<const baseNode *> _branches) : DeclarationList(_branches) {}
  //! Getters
  virtual std::string getNodeType() const override;
  //! Printers
  virtual void python_print(std::ostream &stream) const override;
};

class ExprList : public List {
public:
  virtual ~ExprList(){};
  ExprList(std::vector<const baseNode *> _child) : List(_child) {}
  //! Getters
  virtual std::string getNodeType() const override;
  virtual std::vector<const baseNode *> getChildren() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
  virtual void python_print(std::ostream &stream) const override;
};



#endif
