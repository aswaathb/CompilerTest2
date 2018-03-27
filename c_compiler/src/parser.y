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
      const Expression *node;
      double number;
      std::string *string;
      variable_declaration *variable;
      function_definition *func;
      return_statement *ret_state;
}

%token VAR NUM
%token EQ SEMIC COMMA L_BRAC R_BRAC L_CURLY R_CURLY
%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED
%token RETURN


%type <node> ROOT TYPE_SPEC  
%type <variable>  SCOPE FACTOR DECLARATION STATEMENT 
%type <func> FUNC
%type <number> NUM 
%type <string> VAR  RETURN
%type <ret_state> RETURN_STATEMENT

%start ROOT

%%

ROOT
: TRANSLATION_UNIT									{g_root = $1;}

TRANSLATION_UNIT
: EXTERNAL_DECLARATION								{$$ = new TranslationUnit($1);}
| TRANSLATION_UNIT EXTERNAL_DECLARATION				{$$ = new TranslationUnit($1, $2);}

// EXTERNAL DECLARATIONS
EXTERNAL_DECLARATION
: DECLARATION             {$$ = $1;}
| FUNCTION_DEFINITION     {$$ = $1;}

// FUNCTIONS - INITIALLY SMALLER TO BE MORE MANAGEABLE

FUNCTION_DEFINITION
: DECLARATOR COMPOUND_STATEMENT												{$$ = new FunctionDefinition($1, $2);} // needs implementation
//| DECLARATION-SPECIFIERS DECLARATOR COMPOUND-STATEMENT						{$$ = new FunctionDefinitionSpecifier($1, $2, $3);}
//| DECLARATION-SPECIFIERS DECLARATOR DECLARATION-LIST COMPOUND-STATEMENT		{$$ = new FunctionDefinitionSpecifierList($1, $2, $3, $4);}
//| DECLARATOR DECLARATION-LIST COMPOUND-STATEMENT							{$$ = new ErrorStopper();}


///////////////////////////////////////// STATEMENTS /////////////////////////////////////////////////////////////////////////////////

STATEMENT
: COMPOUND_STATEMENT				      {$$ =$1;}
| SELECTION_STATEMENT				      {$$ =$1;}
| ITERATION_STATEMENT				      {$$ =$1;}
| JUMP_STATEMENT					        {$$ =$1;}
//| LABELED_STATEMENT				      {$$ =$1;}
| EXPRESSION_STATEMENT				    {$$ =$1;}

COMPOUND_STATEMENT
: L_CURLY R_CURLY																	              {$$ = new CompoundStatement();} // needs implementation
// | L_CURLY STATEMENT_LIST R_CURLY
// | L_CURLY DECLARATION_SEQ R_CURLY
// | L_CURLY DECLARATION_SEQ STATEMENT_LIST R_CURLY

SELECTION_STATEMENT
: IF L_BRAC EXPRESSION R_BRAC STATEMENT												  {$$ = new IfElseStatement($3, $5, new CompoundStatement());} // needs implementation
| IF L_BRAC EXPRESSION R_BRAC STATEMENT ELSE STATEMENT					{$$ = new IfElseStatement($3, $5, $7);} // needs implementation
// | SWITCH L_BRAC EXPRESSION R_BRAC STATEMENT                  { $$ = new SwitchStatement($3, $5); }

ITERATION_STATEMENT // start with one
: WHILE L_BRAC EXPRESSION R_BRAC STATEMENT											                      {$$ = new WhileStatement($3, $5);} //needs implemetation
| DO STATEMENT WHILE L_BRAC EXPRESSION R_BRAC										                      {$$ = new DoWhileStatement($2, $5);} //needs implemetation
| FOR L_BRAC EXPRESSION_STATEMENT EXPRESSION_STATEMENT EXPRESSION R_BRAC STATEMENT	  {$$ = new ES_ES_EForStatement($3, $4, $5, $7);} //needs implemetation
| FOR L_BRAC EXPRESSION_STATEMENT EXPRESSION_STATEMENT R_BRAC STATEMENT				        {$$ = new ES_ESForStatement($3, $4, $6);} //needs implemetation
| FOR L_BRAC DECLARATION EXPRESSION_STATEMENT R_BRAC STATEMENT						            {$$ = new D_ESForStatement($3, $4, $6);} //needs implemetation
| FOR L_BRAC DECLARATION EXPRESSION_STATEMENT EXPRESSION R_BRAC STATEMENT			        {$$ = new D_ES_EForStatement($3,$4,$5,$7);} //needs implemetation

JUMP_STATEMENT // just focus on return function for now
: RETURN EXPRESSION_STATEMENT			                  {$$ = new return_statement($2);} // return statement has to be changed in ast
// | GOTO IDENTIFIER SEMICOLON
// | CONTINUE SEMICOLON
// | BREAK SEMICOLON


////////////////////////////////////////////////////// EXPRESSIONS //////////////////////////////////////////////////////////////////////

EXPRESSION_STATEMENT
: SEMICOLON							              {$$ = new ExpressionStatement(new EmptyExpression());} //needs implementation
| EXPRESSION SEMICOLON				        {$$ = new ExpressionStatement($1);} //needs implementation

EXPRESSION
: ASSIGNMENT_EXPRESSION				                    {$$ = $1;}
// | EXPRESSION COMMA ASSIGNMENT_EXPRESSION

ASSIGNMENT_EXPRESSION
: CONDITIONAL_EXPRESSION			{$$ = $1;}

CONDITIONAL_EXPRESSION
: LOGICAL_OR_EXPRESSION				{$$ = $1;}

LOGICAL_OR_EXPRESSION
: LOGICAL_AND_EXPRESSION			{$$ = $1;}

LOGICAL_AND_EXPRESSION
: INCLUSIVE_OR_EXPRESSION			{$$ = $1;}

INCLUSIVE_OR_EXPRESSION
: EXCLUSIVE_OR_EXPRESSION			{$$ = $1;}

EXCLUSIVE_OR_EXPRESSION
: AND_EXPRESSION					{$$ = $1;}

AND_EXPRESSION
: EQUALITY_EXPRESSION				{$$ = $1;}

EQUALITY_EXPRESSION
: RELATIONAL_EXPRESSION				{$$ = $1;}

RELATIONAL_EXPRESSION
: SHIFT_EXPRESSION					{$$ = $1;}

SHIFT_EXPRESSION
: ADDITIVE_EXPRESSION				{$$ = $1;}

ADDITIVE_EXPRESSION
: MULTIPLCATIVE_EXPRESSION			                            {$$ = $1;}
| ADDITIVE_EXPRESSION PLUS MULTIPLCATIVE_EXPRESSION
| ADDITIVE_EXPRESSION MINUS MULTIPLCATIVE_EXPRESSION

MULTIPLCATIVE_EXPRESSION
: CAST_EXPRESSION										                        {$$ = $1;}
| MULTIPLCATIVE_EXPRESSION TIMES CAST_EXPRESSION
| MULTIPLCATIVE_EXPRESSION DIVIDE CAST_EXPRESSION
| MULTIPLCATIVE_EXPRESSION MODULUS CAST_EXPRESSION

CAST_EXPRESSION
: L_BRAC TYPE_NAME R_BRAC CAST_EXPRESSION
// | PREFIX EXPRESSION
// A LOT MORE FOLLOWS THIS BUT CUT FIRST, PREFIX, POSTFIX, ARGIMENT LIST ETC

TYPE_NAME
: VOID
| CHAR
| SHORT
| INT
| LONG
| FLOAT
| DOUBLE
| SIGNED
| UNSIGNED

///////////////////////////////////////////////////////////////// DECLARATIONS ///////////////////////////////////////////////////////////////////

//DECLARATION_SEQ
//: DECLARATION
//| DECLARATION_SEQ DECLARATIONS

DECLARATION
: DECLARATION_SPECIFIER SEMICOLON
| DECLARATION_SPECIFIER INIT_DECLARATOR_LIST

DECLARATION_SPECIFIER
: TYPE_SPECIFIER
// | TYPE_SPECIFIER DECLARATION_SPECIFIER
// | TYPE_QUALIFIER
// | TYPE_QUALIFIER DECLARATION_SPECIFIER
// | STORAGE_CLASS_SPECIFIER
// | STORAGE_CLASS_SPECIFIER DECLARATION_SPECIFIER

TYPE_SPECIFIER
: VOID			          {$$ = new Type(Void);}
//| CHAR			        {$$ = new Type(Char);}
| INT			            {$$ = new Type(Int);}
//| SHORT			        {$$ = new Type(Short);}
//| LONG			        {$$ = new Type(Long);}
| FLOAT			          {$$ = new Type(Float);}
//| DOUBLE		        {$$ = new Type(Double);}
//| SIGNED		        {$$ = new Type(Signed);}
//| UNSIGNED		      {$$ = new Type(Unsigned);}

INIT_DECLARATOR_LIST
: INIT_DECLARATOR	                                  {$$ = $1;}
// | INIT_DECLARATOR_LIST COMMA INIT_DECLARATOR

INIT_DECLARATOR
: DECLARATOR		                      {$$ = $1;}
| DECLARATOR EQUAL INITIALIZER

INITIALIZER
: ASSIGNMENT_EXPRESSION

DECLARATOR
: DIRECT_DECLARATOR                                     {$$ = $1;}
| TIMES DIRECT_DECLARATOR // pointer declaration

// HAVEN'T FINISHED THE REST, NEED TO FIND A CONCISE WAY OF LINKING DECLARATORS WITH EXPRESSIONS.
DIRECT_DECLARATOR


%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
