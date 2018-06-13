#include "baseNode.hpp"
#include "constant.hpp"
#include "declaration.hpp"
#include "statement.hpp"

/*
   GETTERS
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

// std::string baseNode::getDetails() const {
//   std::string defs = " childDefs=\"";
//   if (childDefs.size()){
//     for (auto &it : childDefs){
//       defs += it + ",";
//     }
//     // Get rid of trailing comma
//     defs = defs.substr(0, defs.size()-1);
//     defs += "\"";
//   }
//   else {
//     defs = "";
//   }
//   return "endline=\"" + std::to_string(sourceline) + "\" endcol=\"" + std::to_string(sourcecol) + "\"" + defs;
// }

std::vector<std::string> baseNode::getStrings() const {
  return strings;
}

/*
   SETTERS
 */

//!
void baseNode::addString(std::string s) const {
  strings.push_back(s);
}

//! Populate data vectors with the declarations held by the children
void baseNode::setChildDefs() const {
  // Get children
  for (auto &it : getChildren()){
    it->setChildDefs();
    std::vector<std::string> temp = it->getChildDefs(); // Sets the data by getting the childDefs of it's children
    childDefs.insert(childDefs.end(), temp.begin(), temp.end());
  }
}

//! Populate data vectors with the parameters held by the children

void baseNode::setParamUses() const {
  // Get children
  for (auto &it : getChildren()){
    it->setParamUses();
    std::vector<std::string> temp = it->getChildParams(); // Sets the data by getting the childDefs of it's children
    if (temp.size()>childParams.size()){
      childParams = temp;
    }

    //childParams.insert(childParams.end(), temp.begin(), temp.end());
  }
}

/*
   PRINTERS
 */

Context baseNode::generate_assembly(Context ctxt, int d) const {
  for (auto &it : getChildren()){
    ctxt = it->generate_assembly(ctxt, d);
  }
  return ctxt;
}

void baseNode::python_print(std::ostream &stream) const {
    for (auto &it : getChildren()){
        it->python_print(stream);
    }
}

  ///////////////////////////////////////////////////////////////////
/*
  END OF PRINTERS
*/

/*
  GETTERS
*/

std::string List::getNodeType() const               { return "List"; };
std::string MultiList::getNodeType() const          { return "Scope"; }
std::string TranslationUnit::getNodeType() const    { return "TranslationUnit"; }
std::string DeclarationList::getNodeType() const    { return "DeclarationList"; }
std::string ParameterList::getNodeType() const      { return "ParameterList"; }
std::string ExprList::getNodeType() const           { return "ExprList"; }

std::vector<const baseNode *> List::getChildren() const {
  if (!children.size()){
      std::cerr << "Does not have any children" << std::endl;
  }
  return children;
};

std::vector<const baseNode *> ExprList::getChildren() const {
  return List::getChildren();
}
/*
   END OF GETTERS
 */

/*
    COMMON FUNCTIONS
 */

List::~List() {
  for (auto &it : children)
    delete it;
  children.clear();
}

const baseNode *List::add(const baseNode *child) const {
  children.push_back(child);
  return this;
};

/*
    END OF COMMON FUNCTIONS
 */

/*
   PRINT ASSEMBLY
 */


Context TranslationUnit::generate_assembly(Context ctxt, int d) const {
    ctxt.ss() <<  "\t.section .mdebug.abi32"  << std::endl;
    ctxt.ss() <<  "\t.previous"               << std::endl;
    ctxt.ss() <<  "\t.nan	legacy"             << std::endl;
    ctxt.ss() <<  "\t.module	fp=xx"          << std::endl;
    ctxt.ss() <<  "\t.module	nooddspreg"     << std::endl;
    ctxt.ss() <<  "\t.abicalls"               << std::endl;

    // Assign string
    for (auto &it: getStrings()){
        ctxt.ss() << "# string " << it << std::endl;
        ctxt.addString(it);
  }

  ctxt.createStrings();

  for (auto &it : getChildren()){
    if (it->getNodeType()=="Declaration"){
      for (auto &it2 : it->getChildren()){

        // All function declarators are global
        if (it2->getNodeType()!="FunctionDeclarator"){
          ctxt.ss() << "# " << it2->getNodeType()                   << std::endl;
          ctxt.ss() << "\t.globl\t" << it2->getId()                 << std::endl;
          ctxt.ss() << "\t.data"                                    << std::endl;
          ctxt.ss() << "\t.align\t2"                                << std::endl;
          ctxt.ss() << "\t.type\t"  << it2->getId() << ",\t@object" << std::endl;
          ctxt.ss() << "\t.size\t"  << it2->getId() << ",\t4"       << std::endl;
          ctxt.ss() << it->getId()  << ":"                          << std::endl;
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

Context ExprList::generate_assembly(Context ctxt, int d) const{
  for (auto &it : List::getChildren()){
    it->generate_assembly(ctxt,d);
  }
  return ctxt;
}

// /*
//    PRINT PYTHON
//  */

// void List::python_print(std::ostream &stream) const {
//   for (auto &it : getChildren()){
//     it->python_print(stream);
//   }
// }

// void MultiList::python_print(std::ostream &stream) const {
//   if (getChildren().size() != 0) {
//     tab(stream);
//     tab_incr();
//     for (auto &it : getChildren()){
//       it->python_print(stream);
//     }
//     tab(stream,false);
//   } else {
//     tab_decr();
//   }
// }

// void DeclarationList::python_print(std::ostream &stream) const{
//   List::python_print(stream);
// };

// void ParameterList::python_print(std::ostream &stream) const{
//   for (auto &it : getChildren()) {
//     stream << "<Parameter id=\"" << it->getId() << "\" />" << std::endl;
//   }
// };

// void ExprList::python_print(std::ostream &stream) const{
//     List::python_print(sstream);
// };
