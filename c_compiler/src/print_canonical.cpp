#include "ast.hpp"

int main()
{ std::ostream& out = std::cout;

  const baseNode *ast=parseAST();

/*
  SETTERS
*/
  ast->setChildDefs();
  ast->setParamUses();


/*
  PRINTERS
*/  
  // Print python to cout

  //
  
  // Print the assembly output to cout
  Context ctxt(&out);
  ast->generate_assembly(ctxt);

  delete ast;

  return 0;

}
