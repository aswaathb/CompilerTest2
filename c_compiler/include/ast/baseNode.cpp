#include "baseNode.hpp"
#include "tokens.hpp"
#include "declaration.hpp"
#include "constant.hpp"
#include "jump_statement.hpp"//////////////////////////////////

baseNode::baseNode() : sourceline(yylsourcelino), sourcecol(yylcolno) {};

/*
 * GETTERS
 */

std::string baseNode::getNodeType() const {
  return "baseNode";
}


//! Return the id of a variable, ideally should be pure virtual
std::string baseNode::getId() const { return getNodeType();}

//! Populate metadata vectors with the declarations held by the children
std::vector<std::string> baseNode::getChildDefs() const {
  return childDefs;
}

//! Populate metadata vectors with the declarations held by the children
std::vector<std::string> baseNode::getChildParams() const {
  return childParams;
}

std::string baseNode::getDeets() const { 
  std::string defs = " childDefs=\"";
  if (childDefs.size()){
    for (auto &it : childDefs){
      defs += it + ",";
    }
    // Get rid of trailing comma
    defs = defs.substr(0, defs.size()-1);
    defs += "\"";
  }
  else {
    defs = "";
  }
  return "endline=\"" + std::to_string(sourceline) + "\" endcol=\"" + std::to_string(sourcecol) + "\"" + defs;
}

std::vector<std::string> baseNode::getStrings() const {
  return strings;
}

/*
 * SETTERS
 */

//!
void baseNode::addString(std::string s) const {
  strings.push_back(s);
}

//! Populate metadata vectors with the declarations held by the children
void baseNode::setChildDefs() const {
  // Get all the children
  for (auto &it : getChildren()){
    it->setChildDefs();
    std::vector<std::string> tmp = it->getChildDefs(); // Sets the metadata by getting the childDefs of it's children
    childDefs.insert(childDefs.end(), tmp.begin(), tmp.end());
  }
}

//
//void baseNode::setP() const {
//  // Get all the children
//  for (auto &it : getChildren()){
//    it->setP();
//    if (it->getP()>p){
//      p = it->getP()>p;
//    }
//  }
//}

//! Populate metadata vectors with the parameters held by the children

void baseNode::setParamUses() const {
  // Get all the children
  for (auto &it : getChildren()){
    it->setParamUses();
    std::vector<std::string> tmp = it->getChildParams(); // Sets the metadata by getting the childDefs of it's children
    if (tmp.size()>childParams.size()){
      childParams = tmp;
    }
    
    //childParams.insert(childParams.end(), tmp.begin(), tmp.end());
  }
}


void baseNode::tab(std::ostream &stream, bool open){
 if (!open) {
   tabcount--;
   stream << std::string(tabcount, '\t');
 } else {
   stream << std::string(tabcount, '\t');
   tabcount++;
 }
}

/*
 * PRINTERS
 */

Context baseNode::generate_assembly(Context ctxt, int d) const {
  //ctxt.ss() << "# print asm for " << getNodeType() << "'s children" << std::endl;
  for (auto &it : getChildren()){
    //ctxt.ss() << "# hi " << it->getNodeType() << std::endl;
    // If we are passing by value, siblings aren't away of context changes
    ctxt = it->generate_assembly(ctxt, d);
  }
  return ctxt;
  // ctxt.ss() << "# " << getNodeType() << " not implemented yet" << std::endl;
}

// void baseNode::python_print(std::ostream &stream) const {
//   tab(stream);
//   stream << getHeader() << std::endl;
//   tab_incr();
//   for (auto &it : getChildren()){
//     it->python_print(stream);
//   }
//   tab_decr();
//   tab(stream);
//   stream << getFooter() << std::endl;

  ///////////////////////////////////////////////////////////////////

  /*
 * GETTERS
 */

std::string List::getNodeType() const { return "List"; };
std::string TabbedList::getNodeType() const { return "Scope"; }
std::string Program::getNodeType() const { return "Program"; }
std::string DeclarationList::getNodeType() const { return "DeclarationList"; }
std::string ParameterList::getNodeType() const { return "ParameterList"; }
std::string ExpressionList::getNodeType() const { return "ExpressionList"; }

std::vector<const baseNode *> List::getChildren() const { 
  if (!children.size()){
    //std::cerr << "No children" << std::endl;
  }
  return children; 
};

std::vector<const baseNode *> ExpressionList::getChildren() const {
  return List::getChildren();
}
/*
 * END OF GETTERS
 */

/*
 *  COMMON FUNCTIONS
 */

List::~List() {
  for (auto &it : children)
    delete it;
  children.clear();
}

const baseNode *List::add(const baseNode *child) const {
  sourceline = yylsourcelino;
  sourcecol = yylcolno;
  children.push_back(child);
  return this;
};

/*
 *  END OF COMMON FUNCTIONS
 */

/*
 * PRINT ASM
 */


Context Program::generate_assembly(Context ctxt, int d) const {
  ctxt.ss() <<
   "\t.section .mdebug.abi32\n
    \t.previous\n
    \t.nan	legacy\n
    \t.module	fp=xx\n
    \t.module	nooddspreg\n
    \t.abicalls\n";
  // Assign strings
  for (auto &it: getStrings()){
    ctxt.ss() << "# string " << it << std::endl;
    ctxt.addString(it);
  }
  
  ctxt.createStrings();
  
  for (auto &it : getChildren()){
    if (it->getNodeType()=="Declaration"){
      for (auto &it2 : it->getChildren()){
        // All function declarators are globl, don't want to do it for these
        if (it2->getNodeType()!="FunctionDeclarator"){
          ctxt.ss() << "# " << it2->getNodeType() << std::endl;
          ctxt.ss() << "\t.globl\t" << it2->getId() << std::endl;
          ctxt.ss() << "\t.data" << std::endl;
          ctxt.ss() << "\t.align\t2" << std::endl;
          ctxt.ss() << "\t.type\t" << it2->getId() << ",\t@object" <<std::endl;
          ctxt.ss() << "\t.size\t" << it2->getId() << ",\t4" <<std::endl;
          ctxt.ss() << it->getId() << ":" << std::endl;
          // SO UGLY
          if (it2->getNodeType()=="InitDeclarator")
            ctxt.ss() << "\t.word\t" << ((const Constant *)(((const InitDeclarator *)it2)->getChildren().back()))->getValue() << std::endl;
        }
        //else {
        ctxt.assignVariable(it->getId(), ((const Declaration * )it)->getTypename(),true);
        //}
      }
    }
  }
  
  ctxt.ss() << "\t.text\n";
  for (auto &it : getChildren()){
    if (it->getNodeType()!="Declaration"){
      ctxt = it->generate_assembly(ctxt, d);
    }
  }
  return ctxt;
}

//! Need to override this because it's an ambiguous base
Context ExpressionList::generate_assembly(Context ctxt, int d) const{
  //ctxt.ss() << "# print asm for " << getNodeType() << "'s children" << std::endl;
  for (auto &it : List::getChildren()){
    // ctxt.ss() << "# " << it->getNodeType() << std::endl;
    it->generate_assembly(ctxt,d);
  }
  return ctxt;
} //! Print out mips assembly

/*
 *  PRINT XML
 */

void List::python_print(std::ostream &stream) const {
  for (auto &it : getChildren()){
    it->python_print(stream);
  }
}

void TabbedList::python_print(std::ostream &stream) const {
  if (getChildren().size() != 0) {
    tab(stream);
    stream << getHeader() << std::endl;
    tab_incr();
    for (auto &it : getChildren()){
      it->python_print(stream);
    }
    tab(stream,false);
    stream << getFooter() << std::endl;
  } else {
    tab_decr();
  }
}

void DeclarationList::python_print(std::ostream &stream) const{
  List::python_print(stream);
};

void ExpressionList::python_print(std::ostream &stream) const{
  List::python_print(stream);
};

void ParameterList::python_print(std::ostream &stream) const{
  for (auto &it : getChildren()) {
    stream << "<Parameter id=\"" << it->getId() << "\" />" << std::endl;
  }
};

/*
 * END OF PRINT XML
 */