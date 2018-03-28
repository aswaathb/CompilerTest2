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

%token EQUAL SEMICOLON COMMA L_BRAC R_BRAC L_CURLY R_CURLY
%token PLUS MINUS TIMES DIVIDE MODULUS
%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED
%token RETURN




%type <baseNode> ROOT

%type <variable>  SCOPE FACTOR DECLARATION STATEMENT
%type <func> FUNC
%type <number> NUM
%type <string> VAR  RETURN
%type <ret_state> RETURN_STATEMENT



%type <declarationVal>          DECLARATION
%type <astNodeVal>              DECLARATION-SPECIFIERS TYPE-SPECIFIER
%type <astNodeVal>              INIT-DECLARATOR-LIST DIRECT-DECLARATOR DECLARATOR INITIALIZER EXTERNAL-DECLARATION COMPOUND-STATEMENT
%type <stringVal>               IDENTIFIER T_ASSIGN


%type <astNode> TRANSLATION-UNIT

%type <declaration>

%type <statement> STATEMENT
%type <statement> COMPOUND_STATEMENT SELECTION_STATEMENT ITERATION_STATEMENT JUMP_STATEMENT EXPRESSION_STATEMENT

%type <expression> EXPRESSION
%type <expression> ASSIGNMENT_EXPRESSION CONDITIONAL_EXPRESSION LOGICAL_OR_EXPRESSION LOGICAL_AND_EXPRESSION INCLUSIVE_OR_EXPRESSION EXCLUSIVE_OR_EXPRESSION AND_EXPRESSION EQUALITY_EXPRESSION RELATIONAL_EXPRESSION SHIFT_EXPRESSION ADDITIVE_EXPRESSION MULTIPLCATIVE_EXPRESSION CAST_EXPRESSION PREFIX_EXPRESSION POSTFIX_EXPRESSION PRIMARY_EXPRESSION

%start ROOT

%%

ROOT
: TRANSLATION_UNIT																{g_root = $1;}

TRANSLATION_UNIT
: EXTERNAL_DECLARATION															{$$ = new TranslationUnit($1);}
| TRANSLATION_UNIT EXTERNAL_DECLARATION											{$$ = new TranslationUnit($1, $2);}

// EXTERNAL DECLARATIONS
EXTERNAL_DECLARATION
: DECLARATION             {$$ = $1;}
| FUNCTION_DEFINITION     {$$ = $1;}

// FUNCTIONS - INITIALLY SMALLER TO BE MORE MANAGEABLE

FUNCTION_DEFINITION
: DECLARATOR COMPOUND_STATEMENT													{$$ = new FunctionDefinition($1, $2);} // needs implementation
//| DECLARATION-SPECIFIERS DECLARATOR COMPOUND-STATEMENT						{$$ = new FunctionDefinitionSpecifier($1, $2, $3);}
//| DECLARATION-SPECIFIERS DECLARATOR DECLARATION-LIST COMPOUND-STATEMENT		{$$ = new FunctionDefinitionSpecifierList($1, $2, $3, $4);}
//| DECLARATOR DECLARATION-LIST COMPOUND-STATEMENT								{$$ = new ErrorStopper();}


///////////////////////////////////////// STATEMENTS /////////////////////////////////////////////////////////////////////////////////

STATEMENT
: COMPOUND_STATEMENT															{$$ = $1;}
| SELECTION_STATEMENT															{$$ = $1;}
| ITERATION_STATEMENT															{$$ = $1;}
| JUMP_STATEMENT																{$$ = $1;}
//| LABELED_STATEMENT															{$$ = $1;}
| EXPRESSION_STATEMENT															{$$ = $1;}

COMPOUND_STATEMENT
: L_CURLY R_CURLY																{$$ = new CompoundStatement();} // needs implementation
// | L_CURLY STATEMENT_LIST R_CURLY
// | L_CURLY DECLARATION_SEQ R_CURLY
// | L_CURLY DECLARATION_SEQ STATEMENT_LIST R_CURLY

SELECTION_STATEMENT
: IF L_BRAC EXPRESSION R_BRAC STATEMENT											{$$ = new IfElseStatement($3, $5, new CompoundStatement());} // needs implementation
| IF L_BRAC EXPRESSION R_BRAC STATEMENT ELSE STATEMENT							{$$ = new IfElseStatement($3, $5, $7);} // needs implementation
// | SWITCH L_BRAC EXPRESSION R_BRAC STATEMENT									{ $$ = new SwitchStatement($3, $5); }

ITERATION_STATEMENT // start with one
: WHILE L_BRAC EXPRESSION R_BRAC STATEMENT											  {$$ = new WhileStatement($3, $5);} //needs implemetation
| DO STATEMENT WHILE L_BRAC EXPRESSION R_BRAC										  {$$ = new DoWhileStatement($2, $5);} //needs implemetation
| FOR L_BRAC EXPRESSION_STATEMENT EXPRESSION_STATEMENT EXPRESSION R_BRAC STATEMENT	  {$$ = new ES_ES_EForStatement($3, $4, $5, $7);} //needs implemetation
| FOR L_BRAC EXPRESSION_STATEMENT EXPRESSION_STATEMENT R_BRAC STATEMENT				  {$$ = new ES_ESForStatement($3, $4, $6);} //needs implemetation
| FOR L_BRAC DECLARATION EXPRESSION_STATEMENT R_BRAC STATEMENT						  {$$ = new D_ESForStatement($3, $4, $6);} //needs implemetation
| FOR L_BRAC DECLARATION EXPRESSION_STATEMENT EXPRESSION R_BRAC STATEMENT			  {$$ = new D_ES_EForStatement($3,$4,$5,$7);} //needs implemetation

JUMP_STATEMENT // just focus on return function for now
: RETURN EXPRESSION_STATEMENT													{$$ = new return_statement($2);} // return statement has to be changed in ast
// | GOTO IDENTIFIER SEMICOLON
// | CONTINUE SEMICOLON
// | BREAK SEMICOLON


////////////////////////////////////////////////////// EXPRESSIONS //////////////////////////////////////////////////////////////////////

EXPRESSION_STATEMENT
: SEMICOLON																		{$$ = new ExpressionStatement(new EmptyExpression());} //needs implementation
| EXPRESSION SEMICOLON															{$$ = new ExpressionStatement($1);} //needs implementation

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
| PREFIX_EXPRESSION

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

| PREFIX_EXPRESSION
: POSTFIX_EXPRESSION { $$ = $1; }
//| INCR PREFIX_EXPRESSION { $$ = new PrefixExpression($2, $1); }
//| DECR PREFIX_EXPRESSION { $$ = new PrefixExpression($2, $1); }
//| UNARY_OPERATOR CAST_EXPRESSION { $$ = new PrefixExpression($2, $1); }
//| SIZEOF '(' PREFIX_EXPRESSION ')' { $$ = new PrefixExpression($3, $1); }
//| SIZEOF '(' TYPE_NAME ')' { $$ = new PrefixExpression($3, $1); }

//UNARY_OPERATOR
//: '&'
//| '*'
//| '+'
//| '-'
//| '~'
//| '!'

POSTFIX_EXPRESSION
: PRIMARY_EXPRESSION {$$ = $1;}
//| POSTFIX_EXPRESSION '[' expression ']' { $$ = new SquareOperator($1, $3); }
//| POSTFIX_EXPRESSION '(' ')' { $$ = new FunctionCall($1); }
//| POSTFIX_EXPRESSION '(' argument-expression-list ')' { $$ = new FunctionCall($1, $3); }
//| POSTFIX_EXPRESSION '.' ID { $$ = new DotOperator($1, $3); }
//| POSTFIX_EXPRESSION ARROW ID { $$ = new ArrowOperator($1, $3); }
//| POSTFIX_EXPRESSION INCR { $$ = new PostfixExpression($1, $2); }
//| POSTFIX_EXPRESSION DECR { $$ = new PostfixExpression($1, $2); }

PRIMARY_EXPRESSION
: VAR_CONST																		{$$ = $1;}
| STRING																		{$$ = new StringLiteral(*$1);}
| L_BRAC EXPRESSION R_BRAC														{$$ = $2;}

VAR_CONST
: IDENTIFIER																	{$$ = new Variable($1);}
| I_CONSTANT																	{$$ = new IntConstant(*$1);}
| F_CONSTANT																	{$$ = new FloatConstant(*$1);}
//| C_CONSTANT { $$ = new CharConstant(*$1); }

//ASSIGNMENT OP					//NECESSARY WHEN (COMPOUND) ASSIGNMENT EXPRESSION IMPLEMENTED
//: EQUAL { $$ = $1; }
//| MUL_ASS  { $$ = $1; }
//| DIV_ASS { $$ = $1; }
//| MOD_ASS { $$ = $1; }
//| ADD_ASS { $$ = $1; }
//| SUB_ASS { $$ = $1; }
//| LL_ASS { $$ = $1; }
//| RR_ASS { $$ = $1; }
//| AND_ASS { $$ = $1; }
//| XOR_ASS { $$ = $1; }
//| OR_ASS { $$ = $1; }


///////////////////////////////////////////////////////////////// DECLARATIONS ///////////////////////////////////////////////////////////////////

//DECLARATION_SEQ
//: DECLARATION
//| DECLARATION_SEQ DECLARATIONS								// Required for more than one declaration

DECLARATION
: DECLARATION_SPECIFIER SEMICOLON
| DECLARATION_SPECIFIER INIT_DECLARATOR_LIST SEMICOLON

DECLARATION_SPECIFIER
: TYPE_SPECIFIER
// | TYPE_SPECIFIER DECLARATION_SPECIFIER						// Alternate more complex types of declarations
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

DIRECT_DECLARATOR
: L_BRAC DECLARATOR R_BRAC
| IDENTIFIER																	{$$ = new Variable($1);}
| L_BRAC R_BRAC DECLARATOR
// | DIRECT_DECLARATOR L_SQUARE R_SQUARE						// Array without size specified
// | DIRECT_DECLARATOR L_SQUARE CONSTANT_EXPRESSION R_SQUARE	// Array with fixed size
// | DIRECT_DECLARATOR L_BRAC R_BRAC							// Function with no arguments
// | DIRECT_DECLARATOR L_BRAC PARAMETER_LIST R_BRAC				// Function declaration with parameter list
// | DIRECT_DECLARATOR L_BRAC IDENTIFIER LIST R_BRAC			// Function declaration with id list, must be followed by declaration list

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
	g_root=0;
	yyparse();
	return g_root;
}
