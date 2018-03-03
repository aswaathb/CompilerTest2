%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

//variable types
%token AUTO DOUBLE FLOAT CHAR INT UNSIGNED SIGNED

//function Types
%token FOR IF SWITCH CASE ELSE DO VOID WHILE

//supporting (Constructs?)
%token BREAK GOTO CONST DEFAULT STRUCT REGISTER TYPEDEF RETURN SIZEOF STATIC

%token T_LBRACKET T_RBRACKET T_CLBRACKET T_RLBRACKET T_SRBRACKET T_SLBRACKET

%token T_LOG T_EXP T_SQRT

%token T_NUMBER T_VARIABLE

%type <statement>
%type <number> T_NUMBER
%type <string> T_VARIABLE T_LOG T_EXP T_SQRT

%start ROOT

%%

ROOT : TRANSLATION_UNIT { g_root = $1; }

TRANSLATION_UNIT
: PROGRAM

// 1
PROGRAM
: DECLARATION_LIST


DECLARATION_LIST
: DECLARATION
| DECLARATION_LIST DECLARATION

DECLARATION
: FUNC_DECLARATION

FUNC_DECLARATION
: TYPE_SPECIFIER IDENTIFIER "(" ")" STATEMENT // GRAMMAR BELOW FOR STATEMENTS
| IDENTIFIER

TYPE_SPECIFIER
: INT
| CHAR

//STATEMENTS
STATEMENT
: EXPR_STATEMENT
| RET_STATEMENT

EXPR_STATEMENT
: EXPR ";"
| ";"


RET_STATEMENT
: RETURN ";"
| RETURN EXPR

//EXPRESSIONS
EXPR
: EXPR { //DEFINE AS SOMETHING SIMPLE TO BEGIN WITH }

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
