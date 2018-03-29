
#include "declaration.hpp"
#include "context.hpp"
#include "variable.hpp"

/*
   GETTERS
 */
std::string Declarator::getNodeType() const         { return "Declarator"; };
std::string InitDeclarator::getNodeType() const     { return "InitDeclarator"; };
std::string ArrayDeclarator::getNodeType() const    { return "ArrayDeclarator"; };
std::string FunctionDeclarator::getNodeType() const { return "FunctionDeclarator"; };
std::string Declaration::getNodeType() const        { return "Declaration"; };

std::string Declaration::getId() const {
  return dlist->getChildren()[0]->getId();
}

std::string Declaration::getTypename() const {
  return type->getTypename();
};

std::vector<std::string> Declaration::getTypeVec() const {
  return type->getTypeVec();
};


std::vector<const baseNode *> InitDeclarator::getChildren() const {
  std::vector<const baseNode *> vec = Declarator::getChildren();
  vec.push_back(expr);
  return vec;
}

std::vector<const baseNode *> Declaration::getChildren () const {
  return list->getChildren();
}

void Declarator::setChildDefs() const {
  childDefs.push_back(getId());
}

std::vector<std::string> Declaration::getChildDefs() const {
 return childDefs;
}

const List * FunctionDeclarator::getParams() const {
  return func;
}

/*
    END OF GETTERS
 */


void Declaration::setChildDefs() const {
  for (auto &it : getChildren()){
    it->setChildDefs();
    std::vector<std::string> temp = it->getChildDefs(); 
    childDefs.insert(childDefs.end(), temp.begin(), temp.end());
  }
}

void ArrayDeclarator::setChildDefs() const {
  std::string id = getId();
  childDefs.push_back(id);
  if (expr->getNodeType()=="IntConstant"){
    int val = std::stoi(expr->getId(),0,0);
    for (int i = 0; i<val;i++){
      childDefs.push_back(id+"["+std::to_string(i)+"]");
    }
  }
}

/*
   PRINT ASSEMBLY
 */

Context Declaration::generate_assembly(Context ctxt, int d) const{
  if (list->getChildren().size()){
    for (auto &it : list->getChildren()){
      std::string id = it->getId();
      ctxt.ss() << "## " << it->getNodeType() << ", " << id << ", " << it->getPtr() << std::endl;
      ctxt.ss() << "# assign the variable " << id                                   << std::endl;
      
      if (it->getPtr() || getPtr()){
        ctxt.ss() << " is a pointer"                                                << std::endl;
        ctxt.assignVariable(id, type->getTypeVec()[0],0,1);
      }
      else{
        ctxt.ss() << " is not a pointer"                                            << std::endl;
        ctxt.assignVariable(id, type->getTypeVec()[0]);
      } 
      ctxt = it->generate_assembly(ctxt);  
    }
  }
  return ctxt;
}

Context ArrayDeclarator::generate_assembly(Context ctxt, int d) const{

  int offset = ctxt.getVarOffset(getId());
  //Need to add 4 to the offset
  ctxt.ss() << "\taddiu\t$8,$fp," << offset + 4 << std::endl;
  ctxt.ss() << "\tsw\t$8," << offset << "($fp)" << std::endl;
  int size = std::stoi(expr->getId(),0,0);
  ctxt.setOffset(ctxt.getOffset() + 4*size);
  return ctxt;
}

Context Declarator::generate_assembly(Context ctxt, int d) const{
  return ctxt;
}

Context InitDeclarator::generate_assembly(Context ctxt, int d) const{
  expr->generate_assembly(ctxt);
  if (getPtr()){
    ctxt.setVarPtr(getId());
  }
  ctxt.storeVariable(getId());
  return ctxt;
}

/* 
    PRINT PYTHON
*/
void Declarator::python_print(std::ostream &stream) const{
    stream << " DECLARATOR NEEDS TO BE IMPLEMENTED"         << std::endl; 
}

void FunctionDeclarator::python_print(std::ostream &stream) const {
    stream << " FUNCTION_DECARATION NEEDS TO BE IMPLEMENTED"<< std::endl; 

};

void Declaration::python_print(std::ostream &stream) const{
    stream << " DECARATION NEEDS TO BE IMPLEMENTED"         << std::endl; 
  }
};

