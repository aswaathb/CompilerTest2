#include "statement.hpp"
#include "context.hpp"


/*
  GETTERS
 */

std::string CompoundStatement::getNodeType() const { 
return "CompoundStatement"; };

std::vector<const baseNode *> CompoundStatement::getChildren() const {
  return {decl, stat};
}

/*
  END OF GETTERS
 */

/*
   PRINTERS (ASSEMBLY)
 */

Context CompoundStatement::generate_assembly(Context ctxt, int d) const {

  ctxt = decl->generate_assembly(ctxt);
  
  for (auto it: stat->getChildren()){
    it->generate_assembly(ctxt,d);
  }
  return ctxt;
}


Context ExprStatement::generate_assembly(Context ctxt, int d) const {
  expr->generate_assembly(ctxt,d);
  return ctxt;
}


void ExprStatement::python_print(std::ostream& stream) const {
  stream << "Expr Statement NOT YET IMPLEMENTED"                    << std::endl;
}

void ConditionalStatement::python_print(std::ostream &stream) const {
  stream << "Conditional Statement NOT YET IMPLEMENTED"             << std::endl;
}

void CompoundStatement::python_print(std::ostream &stream) const {
  stream << "Compound Statement NOT YET IMPLEMENTED"                << std::endl;
}


const Expression *SelectionStatement::getCondition() const              { return getConditions()[0]; };

std::vector<const Expression *>SelectionStatement::getConditions() const {
  return {cond};
}

std::string IfStatement::getNodeType() const {

  return "IfStatement";
}

std::string IfElseStatement::getNodeType() const {

  return "IfElseStatement";
}

std::string SwitchStatement::getNodeType() const {
  return "SwitchStatement";
}



/*
  END OF GETTERS
 */


 /*
   PRINT (ASSEMBLY)
  */

Context SwitchStatement::generate_assembly(Context ctxt, int d) const {
  //using a temp context
  Context temp_ctxt = ctxt;
  
  std::string EndLabel = "switch_end_label" + genUniqueID();
  temp_ctxt.setBreak(EndLabel);
  
  cond->generate_assembly(temp_ctxt);
  // Print stat
  getBody()->generate_assembly(temp_ctxt);
  // break goto
  ctxt.ss() << EndLabel << ":"                                      << std::endl; 
  ctxt.ss() << "\tnop"                                              << std::endl;
  
  return ctxt;
};

Context IfElseStatement::generate_assembly(Context ctxt, int d) const {
  ctxt.ss() << "## " << getNodeType()                               << std::endl;

  std::string _ID_ = genUniqueID();
  std::string end = "$ifend" + _ID_;
  std::string start = "$ifstart" + _ID_;
  
  getCondition()->generate_assembly(ctxt);

  ctxt.ss() << "\tbne\t$2,$0," << start                             << std::endl;
  ctxt.ss() << "\tnop"                                              << std::endl;
    // exe stat2 and jump
  ctxt = stat2->generate_assembly(ctxt);
  ctxt.ss() << "\tb\t" << end                                       << std::endl;
  ctxt.ss() << "\tnop"                                              << std::endl;

  // exe stat1
  ctxt.ss() << start << ":"                                         << std::endl;
  ctxt = stat1->generate_assembly(ctxt);
  ctxt.ss() << end << ":"                                           << std::endl;
  return ctxt;
}


/*
  PRINT PYTHONN
 */

void IfStatement::python_print(std::ostream &stream) const {
    stream << "IfStatement NOT YET IMPLEMENTED"                     << std::endl;
}

void IfElseStatement::python_print(std::ostream &stream) const {
    stream << "IfElseStatement NOT YET IMPLEMENTED"                 << std::endl;
}
/*
  END OF PRINTERS
 */


/*
  GETTERS
 */
std::string JumpStatement::getNodeType() const                                      { return "JumpStatement";       }
std::string GotoStatement::getNodeType() const                                      { return "GotoStatement";       }
std::string ContinueStatement::getNodeType() const                                  { return "ContinueStatement";   }
std::string BreakStatement::getNodeType() const                                     { return "BreakStatement";      }
std::string ReturnStatement::getNodeType() const                                    { return "ReturnStatement";     }   

std::vector<const baseNode *> ReturnStatement::getChildren() const                  { return {expr}; }

/*
  END OF GETTERS
 */

/*
  PRINT ASSEMBLY
 */

Context ReturnStatement::generate_assembly(Context ctxt, int d) const{
  ctxt = expr->generate_assembly(ctxt);
  ctxt.ss() << "\tj\t" << ctxt.getF() << " # end of current func"   << std::endl;
  ctxt.ss() << "\tnop"                                              << std::endl;
  return ctxt;
}

Context BreakStatement::generate_assembly(Context ctxt, int d) const{
  
  ctxt.ss() << "\tj\t" << ctxt.getBreak() << " # end of current loop"      << std::endl;
  ctxt.ss() << "\tnop"                                              << std::endl;
  return ctxt;
}

Context ContinueStatement::generate_assembly(Context ctxt, int d) const{
  
  ctxt.ss() << "\tj\t" << ctxt.getContinue()<< " # beginning of current loop"<< std::endl;
  ctxt.ss() << "\tnop"                                              << std::endl;
  return ctxt;
}

Context GotoStatement::generate_assembly(Context ctxt, int d) const{
  
  ctxt.ss() << "\tj\t" << targetLabel << "# jump to label"          << std::endl;
  ctxt.ss() << "\tnop"                                              << std::endl;
  return ctxt;
}


/*
  PRINT PYTHONN
 */

void JumpStatement::python_print(std::ostream& stream) const {
    stream << "JUMPStatement NOT YET IMPLEMENTED"                   << std::endl;
}


/*
  GETTERS
 */
std::string LabeledStatement::getNodeType() const                                   { return "LabeledStatement"; }
std::string Case::getNodeType() const                                               { return "Case"; }
std::string Default::getNodeType() const                                            { return "Default"; }

/*
  END OF GETTERS
 */

/*
  PRINT ASSEMBLY
 */

// Return statement has an expression (or not expression if void function)
Context LabeledStatement::generate_assembly(Context ctxt, int d) const{
  ctxt.ss() << id << ": # label before labelled statement"          << std::endl;
  
  ctxt = stat->generate_assembly(ctxt);
  return ctxt;
}


Context Case::generate_assembly(Context ctxt, int d) const {

  std::string caseLabel = "case" + genUniqueID();
  // Evaluate expression.
  ctxt.push(2);
  ctxt = expr->generate_assembly(ctxt,3);

  ctxt.pop(2);
  
  // $2!=$3? goto caseLabel
  ctxt.ss() << "\tbne\t$2,$3," << caseLabel                         << std::endl;
  ctxt = stat->generate_assembly(ctxt);

  // if expression is not equal to 
  ctxt.ss() << caseLabel << ": # unique case label just in case"    << std::endl;
  
  return ctxt;
}

Context Default::generate_assembly(Context ctxt, int d) const {
  std::string dLabel = "default" + genUniqueID();

  ctxt.ss() << dLabel << ": # unique default label just in case"    << std::endl;
  ctxt = stat->generate_assembly(ctxt);

  return ctxt;
}




std::string Iteration::getNodeType() const { 
  return "Iteration"; 
}

std::string ForStatementBase::getNodeType() const { 
  return "ForStatementBase"; 
}

std::string WhileStatement::getNodeType() const { 
  return "WhileStatement"; 
}

std::string DoWhileStatement::getNodeType() const { 
  return "DoWhileStatement"; 
}


std::string ExprExprFor::getNodeType() const                        { return "ExprExprFor"; }
std::string DecExprFor::getNodeType() const                         { return "DecExprFor"; }
std::string ExprExprExprFor::getNodeType() const                    { return "ExprExprExprFor"; }
std::string DecExprExprFor::getNodeType() const                     { return "DecExprExprFor"; }



/*
   GETTERS
 */

std::vector<const baseNode*> WhileStatement::getChildren() const {
  return {cond,stat1};
}

std::vector<const baseNode*> ForStatementBase::getChildren() const {
  return {cond1,stat1};
}

std::vector<const baseNode*> ExprExprFor::getChildren() const {
  return {cond1,cond2,stat1};
}

std::vector<const baseNode*> ExprExprExprFor::getChildren() const {
  return {cond1,cond2,cond3,stat1};
}

std::vector<const baseNode*> DecExprFor::getChildren() const {
  return {decl,cond1,stat1};
}

std::vector<const baseNode*> DecExprExprFor::getChildren() const {
  return {decl,cond1,cond2,stat1};
}

/*
   END OF GETTERS
 */

/*
   PRINTERS
 */

Context loop_print(Context ctxt, const Iteration * in, const Statement * stat1){
  // Create labels
  std::string _ID_ = genUniqueID();
  std::string cond       = "$cond"       + _ID_;
  std::string whilestart = "$whilestart" + _ID_;
  std::string whilend    = "$whilend"    + _ID_;
  
  std::string type = in->getNodeType();
  if (type=="ExprExprFor" || type=="ExprExprExprFor"){
    ctxt = in->getChildren().at(0)->generate_assembly(ctxt,2);
  }

  //Using a temp context
  Context temp_ctxt = ctxt;
  if (type=="DecExprFor" || type=="DecExprExprFor"){
    temp_ctxt = in->getChildren().at(0)->generate_assembly(temp_ctxt,2);
  }
  
  temp_ctxt.setBreak(whilend);
  temp_ctxt.setContinue(cond);
  
  if (type=="DoWhileStatement"){
    // Loop once 
    ctxt.ss() << "\tb\t" << whilestart                              << std::endl;
  }
  // label for condition
  ctxt.ss() << cond << ":"                                          << std::endl;
  if (type=="ExprExprExprFor" || type=="DecExprExprFor"){
    in->getConditions().at(1)->generate_assembly(temp_ctxt,2);
  }
  in->getConditions().at(0)->generate_assembly(temp_ctxt,2);
  // If cond=0, goto whilend
  ctxt.ss() << "\tbeq\t$2,$0," << whilend                           << std::endl;
  ctxt.ss() << "\tnop"                                              << std::endl;
  // exe statment
  ctxt.ss() << whilestart << ":"                                    << std::endl;
  stat1->generate_assembly(temp_ctxt);

  ctxt.ss() << "\tb\t" << cond                                      << std::endl;
  ctxt.ss() << "\tnop"                                              << std::endl;
  ctxt.ss() << whilend << ":"                                       << std::endl;

  return ctxt;
}

Context Iteration::generate_assembly(Context ctxt, int d) const {
  loop_print(ctxt, this, stat1);

  return ctxt;
}


Context WhileStatement::generate_assembly(Context ctxt, int d) const {
  loop_print(ctxt, this, stat1);

  return ctxt;
}

Context DoWhileStatement::generate_assembly(Context ctxt, int d) const {
  loop_print(ctxt, this, stat1);

  return ctxt;
}

Context ForStatementBase::generate_assembly(Context ctxt, int d) const {
  
  return loop_print(ctxt, this, stat1);
}

Context DecExprExprFor::generate_assembly(Context ctxt, int d) const {
  return loop_print(ctxt, this, stat1);
}



/*
   END OF PRINTERS
 */

