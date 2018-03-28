#ifndef BASENODE_HPP
#define BASENODE_HPP

#include <iostream>
#include <map>
#include "tokens.hpp"
#include <vector>


class Context;

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
  //mutable std::map<std::string, int> childUses; //! Child uses easier to implement (??) (are they necessary?)
  // std::vector<std::string> parentDefs; -> need pointer to parent on each node, effort.
  
  // A list of:
  // variables used by children
  // variables defined by parents
  // variables defined by children
  // def-use analysis
public:
  virtual ~baseNode(){
    for (auto &it:getChildren()){
      std::cerr << "Deleting " << it->getNodeType() << std::endl;
      delete it;
    }
  };

  baseNode();
  //! Getters
  virtual std::string getNodeType() const;  //! Return the type of the node
  virtual std::string getDeets() const;
  virtual std::string getHeader() const;        //! Return the xml header for the node
  virtual std::string getFooter() const;        //! Return the xml footer for the node
  virtual int getPtr() const {return 0; };
  virtual std::vector<const Node *> getChildren() const { return {};}; //! If not overridden, return empty.
  virtual std::string getId() const;            //! Return the id of a variable, ideally should be pure virtual
  virtual std::vector<std::string> getChildDefs() const; //! Child defs is the most useful, especially for functions
  virtual std::vector<std::string> getChildParams() const;
  virtual void addString(std::string) const;
  virtual std::vector<std::string> getStrings() const;
  //virtual std::map<std::string> childUses() const;
  // virtual void childUses() const;
  
  //! Recursive setter:
  virtual void setChildDefs() const;
  virtual void setParamUses() const;
  //virtual void setP() const;
  //virtual int getP() const { return p; };
  
  //! Printers
  virtual void python_print(std::ostream &stream) const;    //! Print xml implicit recursive function
  // virtual void print_c() const;      //! Print cpp implicit recursive function
  virtual Context generate_assembly(Context ctxt, int d = 2) const; //! Print out mips assembly
  // virtual void print_mips() const;   //! Print ast 
  

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
  
  //! Add a child
  virtual const baseNode * add(const baseNode * child) const;
  
  //! Return the child at a particular index
  //const Node *getChild(int i) const;
  
  //! Getters
  virtual std::string getNodeType() const;
  virtual std::vector<const baseNode *> getChildren() const;
  
  //! Printers
  virtual void python_print(std::ostream &stream) const;
  // virtual void print_c() const;
};

//! TabbedList is a node of the ast that can have any number of children
//! Name chosen to be list because listes can have other listes
//! or leaves
class TabbedList : public List {
public:
  //! Initialise using brace initializer new TabbedList({arg1, arg2, arg3})
  TabbedList(std::vector<const baseNode *> _children) : List(_children) {}
  
  //! Getters
  virtual std::string getNodeType() const;
  
  //! Printers
  virtual void python_print(std::ostream &stream) const;
};



//! The root of the ast
//! It is a list because it can have any number of children
class Program : public TabbedList {
public:
  Program(std::vector<const baseNode *> _child) : TabbedList(_child) {}
  
  //! Getters
  virtual std::string getNodeType() const override;
  // virtual void print_c() const;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
};

//! Scopes have a declaration list
class DeclarationList : public List {
public:
  DeclarationList(std::vector<const baseNode *> _stems) : List(_stems)  {}
  //! Getters
  virtual std::string getNodeType() const override;
  //! Printers
  virtual void python_print(std::ostream &stream) const override;
};

//! Functions have a parameter list.
class ParameterList : public DeclarationList {
public:
  ParameterList(std::vector<const baseNode *> _stems) : DeclarationList(_stems) {}
  //! Getters
  virtual std::string getNodeType() const override;
  //! Printers
  virtual void python_print(std::ostream &stream) const override;
};

//! Points to any number of expressions separated by commas
class ExpressionList : public List, public Expression {
  //! Contains a vector of pointers to ast nodes
public:
  virtual ~ExpressionList(){};
  ExpressionList(std::vector<const baseNode *> _child) : List(_child) {}
  //! Getters
  virtual std::string getNodeType() const override;
  virtual std::vector<const baseNode *> getChildren() const override;
  virtual Context generate_assembly(Context ctxt, int d = 2) const override;
  virtual void python_print(std::ostream &stream) const override;
};


#endif
