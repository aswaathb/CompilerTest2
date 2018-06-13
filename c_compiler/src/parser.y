%code requires{
	#include "ast.hpp"
	#include "ast/base_expr.hpp"
	#include "ast/baseNode.hpp"
	#include "ast/binary_operators.hpp"
	#include "ast/constant.hpp"
	#include "ast/context.hpp"
	#include "ast/declaration.hpp"
	#include "ast/functions.hpp"
	#include "ast/statement.hpp"
	#include "ast/types.hpp"
	#include "ast/variables.hpp"

	#include <string>

	

	extern const baseNode *g_root; // A way of getting the AST out

	//! This is to fix problems when generating C++
	// We are declaring the functions provided by Flex, so
	// that Bison generated code can call them.
	void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
	const baseNode 		*node;
	const CompoundStatement *compstat;
	const Declaration 	*decl;
	const Expression 	*expr;
	const ExprStatement *exprstat;
	const List			*list;
	const Statement 	*stat;
	const Type 			*type;

	std::string 		*str;
}


%token IDENTIFIER F_CONST I_CONST C_CONST

%token PLUS MINUS TIMES DIVIDE MODULUS 
%token LOR LAND OR NEQUAL LESSEQUAL LESSTHAN GREATEQUAL GREATTHAN AND XOR L_SHIFT R_SHIFT

%token MUL_ASS DIV_ASS MOD_ASS ADD_ASS SUB_ASS LL_ASS RR_ASS AND_ASS XOR_ASS OR_ASS ARROW DECR INCR

%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED CONST

%token DO WHILE IF ELSE FOR SWITCH
%token RETURN CONTINUE BREAK GOTO

%token EQUAL SEMICOLON COMMA L_BRAC R_BRAC L_CURLY R_CURLY L_SQUARE R_SQUARE

%token QUES_MARK COLON DOT STRING SIZEOF 

%token CONDITIONAL_EXPRESSION  LOGICAL_OR_EXPRESSION LOGICAL_AND_EXPRESSION INCLUSIVE_OR_EXPRESSION EXCLUSIVE_OR_EXPRESSION AND_EXPRESSION  RELATIONAL_EXPRESSION SHIFT_EXPRESSION   CAST_EXPRESSION PREFIX_EXPRESSION POSTFIX_EXPRESSION  VARIABLE_CONSTANT





%type <node> ROOT TRANSLATION_UNIT EXTERNAL_DECLARATION DECLARATOR DIRECT_DECLARATOR INIT_DECLARATOR  PARAMETER_DECLARATOR

%type <decl> DECLARATION

%type <expr> EXPRESSION ASSIGNMENT_EXPRESSION CONDITIONAL_EXPRESSION INITIALIZER LOGICAL_OR_EXPRESSION LOGICAL_AND_EXPRESSION INCLUSIVE_OR_EXPRESSION EXCLUSIVE_OR_EXPRESSION AND_EXPRESSION EQUALITY_EXPRESSION RELATIONAL_EXPRESSION SHIFT_EXPRESSION ADDITIVE_EXPRESSION MULTIPLCATIVE_EXPRESSION CAST_EXPRESSION PREFIX_EXPRESSION POSTFIX_EXPRESSION PRIMARY_EXPRESSION VARIABLE_CONSTANT

%type <exprstat> EXPRESSION_STATEMENT

%type <list> IDENTIFIER_LIST PARAMETER_LIST STATEMENT_LIST DECLARATION_SEQ INIT_DECLARATOR_LIST

%type <stat> STATEMENT  SELECTION_STATEMENT ITERATION_STATEMENT JUMP_STATEMENT

%type <compstat> COMPOUND_STATEMENT

%type <type> DECLARATION_SPECIFIER TYPE_SPECIFIER CONST


%type <str> ASSIGNMENT_OP TYPE_NAME IDENTIFIER PLUS MINUS TIMES DIVIDE MODULUS STRING C_CONST F_CONST I_CONST SIZEOF UNARY_OPERATOR  EQUAL SEMICOLON COMMA L_BRAC R_BRAC L_CURLY R_CURLY L_SQUARE R_SQUARE QUES_MARK COLON MUL_ASS DIV_ASS MOD_ASS ADD_ASS SUB_ASS LL_ASS RR_ASS AND_ASS XOR_ASS OR_ASS ARROW DECR INCR LOR LAND OR NEQUAL LESSEQUAL LESSTHAN GREATEQUAL GREATTHAN AND XOR L_SHIFT R_SHIFT





%start ROOT

%%

ROOT
	: TRANSLATION_UNIT																{ g_root = (const baseNode *)$1; }

TRANSLATION_UNIT
	: EXTERNAL_DECLARATION															{ $$ = new TranslationUnit( {$1} ); }

EXTERNAL_DECLARATION
	: DECLARATION             														{ $$ = $1;}
	| DECLARATION_SPECIFIER DECLARATOR COMPOUND_STATEMENT    						{ $$ = new Function($1, $2, $3);}

///////////////////////////////////////// STATEMENTS /////////////////////////////////////////////////////////////////////////////////

STATEMENT
	: COMPOUND_STATEMENT															{ $$ = $1;}
	| SELECTION_STATEMENT															{ $$ = $1;}
	| WHILE L_BRAC EXPRESSION R_BRAC STATEMENT										{ $$ = new WhileStatement($3, $5);}
	| RETURN EXPRESSION_STATEMENT													{ $$ = new ReturnStatement($2);}
	| EXPRESSION_STATEMENT															{ $$ = $1;}

COMPOUND_STATEMENT
	: L_CURLY R_CURLY																{ $$ = new CompoundStatement();}
	// | L_CURLY DECLARATION_SEQ R_CURLY												{ $$ = new CompoundStatement( $2, new List({}) ); } 
	| L_CURLY STATEMENT_LIST R_CURLY												{ $$ = new CompoundStatement( new List({}), $2); }
	// | L_CURLY DECLARATION_SEQ STATEMENT_LIST R_CURLY								{ $$ = new CompoundStatement( $2, $3 ); }

STATEMENT_LIST
	: STATEMENT 																	{ $$ = new List({$1}); }
	| STATEMENT_LIST STATEMENT 														{ $$ -> add($2); }

SELECTION_STATEMENT
	: IF L_BRAC EXPRESSION R_BRAC STATEMENT											{ $$ = new IfElseStatement($3, $5, new CompoundStatement());}
	| IF L_BRAC EXPRESSION R_BRAC STATEMENT ELSE STATEMENT							{ $$ = new IfElseStatement($3, $5, $7);} 

////////////////////////////////////////////////////// EXPRESSIONS //////////////////////////////////////////////////////////////////////

EXPRESSION_STATEMENT
	: SEMICOLON																		{ $$ = new ExprStatement(new Expression_Null());}
	| EXPRESSION SEMICOLON															{ $$ = new ExprStatement($1);}

EXPRESSION
	: ASSIGNMENT_EXPRESSION															{ $$ = $1;}
	| EXPRESSION COMMA ASSIGNMENT_EXPRESSION										{ $$ -> add($3); }

ASSIGNMENT_EXPRESSION
	: EQUALITY_EXPRESSION															{ $$ = $1;}
	| PRIMARY_EXPRESSION ASSIGNMENT_OP ASSIGNMENT_EXPRESSION 						{ $$ = new AssignmentExpression($1, $3, $2); }

EQUALITY_EXPRESSION
	: ADDITIVE_EXPRESSION																{ $$ = $1;}
	| EQUALITY_EXPRESSION EQUAL	RELATIONAL_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }

ADDITIVE_EXPRESSION
	: MULTIPLCATIVE_EXPRESSION			                            				{ $$ = $1;}
	| ADDITIVE_EXPRESSION PLUS MULTIPLCATIVE_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }
	| ADDITIVE_EXPRESSION MINUS MULTIPLCATIVE_EXPRESSION							{ $$ = new BinaryExpression($1, $3, $2); }

MULTIPLCATIVE_EXPRESSION
	: CAST_EXPRESSION										                        { $$ = $1;}
	| MULTIPLCATIVE_EXPRESSION TIMES PRIMARY_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }
	| MULTIPLCATIVE_EXPRESSION DIVIDE PRIMARY_EXPRESSION							{ $$ = new BinaryExpression($1, $3, $2); }
	| MULTIPLCATIVE_EXPRESSION MODULUS PRIMARY_EXPRESSION							{ $$ = new BinaryExpression($1, $3, $2); }

PRIMARY_EXPRESSION
	: IDENTIFIER																	{ $$ = new Variable($1);}
	| STRING																		{ $$ = new StringLiteral(*$1);}
	| L_BRAC EXPRESSION R_BRAC														{ $$ = $2;}

ASSIGNMENT_OP
	: EQUAL 																		{ $$ = $1; }
	| MUL_ASS  																		{ $$ = $1; }
	| DIV_ASS 																		{ $$ = $1; }
	| ADD_ASS 																		{ $$ = $1; }
	| SUB_ASS 																		{ $$ = $1; }

///////////////////////////////////////////////////////////////// DECLARATIONS ///////////////////////////////////////////////////////////////////

DECLARATION_SEQ
 	: DECLARATION																	{ $$ = new DeclarationList({$1});}
 	| DECLARATION_SEQ DECLARATION													{ $$ -> add($2); }

DECLARATION
	: DECLARATION_SPECIFIER SEMICOLON												{ $$ = new Declaration($1,( new List({}) ) ); }
	| DECLARATION_SPECIFIER INIT_DECLARATOR_LIST SEMICOLON							{ $$ = new Declaration($1, $2); }

DECLARATION_SPECIFIER	
	: VOID			          														{ $$ = new Type(0x2);}
	// | CHAR			        														{ $$ = new Type(Char);}
	| INT			            													{ $$ = new Type(0x1);}
	// FLOAT			          														{ $$ = new Type(0x4);}
	// | DOUBLE		        														{ $$ = new Type(Double);}

INIT_DECLARATOR_LIST
	: INIT_DECLARATOR	                                  							{ $$ = new DeclarationList({$1}); }

INIT_DECLARATOR
	: DECLARATOR		                      										{ $$ = $1; }
	| DECLARATOR EQUAL INITIALIZER													{ $$ = new InitDeclarator($1,$3); if ($1->getPtr()){$$->setPtr();} } //TOO HARD!!!!

INITIALIZER
	: ASSIGNMENT_EXPRESSION															{ $$ = $1; }

DECLARATOR
	: DIRECT_DECLARATOR                                     						{ $$ = $1; }

IDENTIFIER_LIST
	: IDENTIFIER																	{ $$ = new List({new Variable($1)}); }

DIRECT_DECLARATOR
	: IDENTIFIER																	{ $$ = new Variable($1);}

/////////////////////////////////////////////////////////////////// END OF GRAMMAR RULES /////////////////////////////////////////////////////////////////////////

%%

const baseNode *g_root; 

const baseNode *parseAST()
{
	g_root=0;
	yyparse();
	return g_root;
}
