%code requires{
	#include "ast.hpp"

	#include <cassert>

	extern const baseNode *g_root; // A way of getting the AST out

	//! This is to fix problems when generating C++
	// We are declaring the functions provided by Flex, so
	// that Bison generated code can call them.
	int yylex(void);
	void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
	const baseNode 		*node;
	const Declaration 	*decl;
	const Expression 	*expr;
	const ExprStatement *exprstat;
	const Function 		*func;
	const Statement 	*stat; 
	const Type 			*type;

	std::string *literal;
}

%token PLUS MINUS TIMES DIVIDE MODULUS
%token VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED
%token RETURN DO WHILE IF ELSE FOR
%token EQUAL SEMICOLON COMMA L_BRAC R_BRAC L_CURLY R_CURLY 
//add
%token QUES_MARK COLON LOR LAND OR NEQUAL LESSEQUAL LESSTHAN GREATEQUAL GREATTHAN AND XOR L_SHIFT R_SHIFT DOT 



%type <node> ROOT TRANSLATION_UNIT DECLARATOR DIRECT_DECLARATOR INIT_DECLARATOR paramete IDENTIFIER_LIST PARAMETER_LIST STATEMENT_LIST  DECLARATION_SEQ INIT_DECLARATOR_LIST EXPRESSION_LIST

%type <decl> DECLARATION

%type <func> FUNCTION_DEFINITION

%type <expr> EXPRESSION ASSIGNMENT_EXPRESSION CONDITIONAL_EXPRESSION INITIALIZER LOGICAL_OR_EXPRESSION LOGICAL_AND_EXPRESSION INCLUSIVE_OR_EXPRESSION EXCLUSIVE_OR_EXPRESSION AND_EXPRESSION EQUALITY_EXPRESSION RELATIONAL_EXPRESSION SHIFT_EXPRESSION ADDITIVE_EXPRESSION MULTIPLCATIVE_EXPRESSION CAST_EXPRESSION PREFIX_EXPRESSION POSTFIX_EXPRESSION PRIMARY_EXPRESSION

%type <exprstat> EXPRESSION_STATEMENT

%type <stat> STATEMENT COMPOUND_STATEMENT SELECTION_STATEMENT ITERATION_STATEMENT JUMP_STATEMENT

%type <type> DECLARATION_SPECIFIER TYPE_SPECIFIER STORAGE_CLASS_SPECIFIER TYPE_QUALIFIER

%type <literal> ASSIGNMENT_OP TYPE_NAME VOID INT CHAR SHORT LONG FLOAT DOUBLE SIGNED UNSIGNED STRING ID C_CONSTANT F_CONSTANT I_CONSTANT SIZEOF UNARY_OPERATOR


%start ROOT

%%

ROOT
	: TRANSLATION_UNIT																{ g_root = (const baseNode *)$1; }

TRANSLATION_UNIT
	: EXTERNAL_DECLARATION															{ $$ = new TranslationUnit($1);}
	| TRANSLATION_UNIT EXTERNAL_DECLARATION											{ $$->add($2);}

// EXTERNAL DECLARATIONS
EXTERNAL_DECLARATION
	: DECLARATION             														{ $$ = $1;}
	| FUNCTION_DEFINITION     														{ $$ = $1;}

// FUNCTIONS - INITIALLY SMALLER TO BE MORE MANAGEABLE

FUNCTION_DEFINITION
	: DECLARATOR COMPOUND_STATEMENT													{ $$ = new FunctionDefinition($1, $2);} ///????
	//| DECLARATION-SPECIFIERS DECLARATOR COMPOUND-STATEMENT						{ $$ = new Function($1, $2, $3);}
	//| DECLARATION-SPECIFIERS DECLARATOR DECLARATION-LIST COMPOUND-STATEMENT		{ $$ = new Function($2, $3, $4);}
	//| DECLARATOR DECLARATION-LIST COMPOUND-STATEMENT								{ $$ = new ErrorStopper();} ///????


///////////////////////////////////////// STATEMENTS /////////////////////////////////////////////////////////////////////////////////

STATEMENT
	: COMPOUND_STATEMENT															{ $$ = $1;}
	| SELECTION_STATEMENT															{ $$ = $1;}
	| ITERATION_STATEMENT															{ $$ = $1;}
	| JUMP_STATEMENT																{ $$ = $1;}
	//| LABELED_STATEMENT															{ $$ = $1;}
	| EXPRESSION_STATEMENT															{ $$ = $1;}

COMPOUND_STATEMENT
	: L_CURLY R_CURLY																{ $$ = new CompoundStatement();} // needs implementation
	// | L_CURLY STATEMENT_LIST R_CURLY
	// | L_CURLY DECLARATION_SEQ R_CURLY
	// | L_CURLY DECLARATION_SEQ STATEMENT_LIST R_CURLY

SELECTION_STATEMENT
	: IF L_BRAC EXPRESSION R_BRAC STATEMENT											{ $$ = new IfElseStatement($3, $5, new CompoundStatement());}
	| IF L_BRAC EXPRESSION R_BRAC STATEMENT ELSE STATEMENT							{ $$ = new IfElseStatement($3, $5, $7);} 
	// | SWITCH L_BRAC EXPRESSION R_BRAC STATEMENT									{ $$ = new SwitchStatement($3, $5); }

ITERATION_STATEMENT // start with one
	: WHILE L_BRAC EXPRESSION R_BRAC STATEMENT											  { $$ = new WhileStatement($3, $5);} 
	| DO STATEMENT WHILE L_BRAC EXPRESSION R_BRAC										  { $$ = new DoWhileStatement($2, $5);} 
	| FOR L_BRAC EXPRESSION_STATEMENT EXPRESSION_STATEMENT R_BRAC STATEMENT				  { $$ = new ExprExprFor($3, $4, $6);}
	| FOR L_BRAC EXPRESSION_STATEMENT EXPRESSION_STATEMENT EXPRESSION R_BRAC STATEMENT	  { $$ = new ExprExprExprFor($3, $4, $5, $7);} 
	| FOR L_BRAC DECLARATION EXPRESSION_STATEMENT R_BRAC STATEMENT						  { $$ = new DecExprFor($3, $4, $6);} 
	| FOR L_BRAC DECLARATION EXPRESSION_STATEMENT EXPRESSION R_BRAC STATEMENT			  { $$ = new DecExprExprFor($3,$4,$5,$7);}
		
JUMP_STATEMENT // just focus on return function for now
	: RETURN EXPRESSION_STATEMENT													{ $$ = new ReturnStatement($2);}
	| GOTO IDENTIFIER SEMICOLON														{ $$ = new GotoStatement(*$2);}
	| CONTINUE SEMICOLON															{ $$ = new ContinueStatement();}
	| BREAK SEMICOLON																{ $$ = new BreakStatement();}


////////////////////////////////////////////////////// EXPRESSIONS //////////////////////////////////////////////////////////////////////

EXPRESSION_STATEMENT
	: SEMICOLON																		{ $$ = new ExprStatement(new Expression_Null());}
	| EXPRESSION SEMICOLON															{ $$ = new ExprStatement($1);}

EXPRESSION
	: ASSIGNMENT_EXPRESSION															{ $$ = $1;}
	| EXPRESSION COMMA ASSIGNMENT_EXPRESSION										{ $$ -> add($3); }

ASSIGNMENT_EXPRESSION
	: CONDITIONAL_EXPRESSION														{ $$ = $1;}
	| PREFIX_EXPRESSION ASSIGNMENT_OP ASSIGNMENT_EXPRESSION 						{ $$ = new AssignmentExpression($1, $3, $2); }


CONDITIONAL_EXPRESSION
	: LOGICAL_OR_EXPRESSION															{ $$ = $1;}
	| LOGICAL_OR_EXPRESSION QUES_MARK EXPRESSION COLON CONDITIONAL_EXPRESSION 		{ $$ = new TernaryExpression($1, $3, $5); }

LOGICAL_OR_EXPRESSION
	: LOGICAL_AND_EXPRESSION														{ $$ = $1;}
  	| LOGICAL_OR_EXPRESSION LOR LOGICAL_AND_EXPRESSION 								{ $$ = new BinaryExpression($1, $3, $2); }


LOGICAL_AND_EXPRESSION
	: INCLUSIVE_OR_EXPRESSION														{ $$ = $1;}
	| LOGICAL_AND_EXPRESSION LAND INCLUSIVE_OR_EXPRESSION							{ $$ = new BinaryExpression($1, $3, $2); }


INCLUSIVE_OR_EXPRESSION
	: EXCLUSIVE_OR_EXPRESSION														{ $$ = $1;}
	| INCLUSIVE_OR_EXPRESSION OR EXCLUSIVE_OR_EXPRESSION							{ $$ = new BinaryExpression($1, $3, $2); }

EXCLUSIVE_OR_EXPRESSION
	: AND_EXPRESSION																{ $$ = $1;}
	| EXCLUSIVE_OR_EXPRESSION XOR AND_EXPRESSION									{ $$ = new BinaryExpression($1, $3, $2); }

AND_EXPRESSION
	: EQUALITY_EXPRESSION															{ $$ = $1;}
	| AND_EXPRESSION AND EQUALITY_EXPRESSION										{ $$ = new BinaryExpression($1, $3, $2); }

EQUALITY_EXPRESSION
	: RELATIONAL_EXPRESSION															{ $$ = $1;}
	| EQUALITY_EXPRESSION EQUAL	RELATIONAL_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }
	| EQUALITY_EXPRESSION NEQUAL RELATIONAL_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }

RELATIONAL_EXPRESSION
	: SHIFT_EXPRESSION																{ $$ = $1;}
	| RELATIONAL_EXPRESSION LESSTHAN SHIFT_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }
	| RELATIONAL_EXPRESSION LESSEQUAL SHIFT_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }
	| RELATIONAL_EXPRESSION GREATTHAN SHIFT_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }
	| RELATIONAL_EXPRESSION GREATEQUAL SHIFT_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }

SHIFT_EXPRESSION
	: ADDITIVE_EXPRESSION															{ $$ = $1;}
	| SHIFT_EXPRESSION L_SHIFT ADDITIVE_EXPRESSION									{ $$ = new BinaryExpression($1, $3, $2); }
	| SHIFT_EXPRESSION R_SHIFT ADDITIVE_EXPRESSION									{ $$ = new BinaryExpression($1, $3, $2); }

ADDITIVE_EXPRESSION
	: MULTIPLCATIVE_EXPRESSION			                            				{ $$ = $1;}
	| ADDITIVE_EXPRESSION PLUS MULTIPLCATIVE_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }
	| ADDITIVE_EXPRESSION MINUS MULTIPLCATIVE_EXPRESSION							{ $$ = new BinaryExpression($1, $3, $2); }

MULTIPLCATIVE_EXPRESSION
	: CAST_EXPRESSION										                        { $$ = $1;}
	| MULTIPLCATIVE_EXPRESSION TIMES CAST_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }
	| MULTIPLCATIVE_EXPRESSION DIVIDE CAST_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }
	| MULTIPLCATIVE_EXPRESSION MODULUS CAST_EXPRESSION								{ $$ = new BinaryExpression($1, $3, $2); }

CAST_EXPRESSION
	: L_BRAC TYPE_NAME R_BRAC CAST_EXPRESSION										{ $$ = new CastExpr($4, $2); }
	| PREFIX_EXPRESSION																{ $$ = $1; }


PREFIX_EXPRESSION
	: POSTFIX_EXPRESSION 															{ $$ = $1; }
	| INCR PREFIX_EXPRESSION 														{ $$ = new PrefixExpr($2, $1); }
	| DECR PREFIX_EXPRESSION 														{ $$ = new PrefixExpr($2, $1); }
	| UNARY_OPERATOR CAST_EXPRESSION 												{ $$ = new PrefixExpr($2, $1); }
	| SIZEOF L_BRAC PREFIX_EXPRESSION R_BRAC										{ $$ = new PrefixExpr($3, $1); }
	| SIZEOF L_BRAC TYPE_NAME R_BRAC 												{ $$ = new PrefixExpr($3, $1); }


UNARY_OPERATOR
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'

POSTFIX_EXPRESSION
	: PRIMARY_EXPRESSION 															{$$ = $1;}
	| POSTFIX_EXPRESSION L_SQUARE EXPRESSION R_SQUARE 								{ $$ = new SquareOperator($1, $3); }
	| POSTFIX_EXPRESSION L_BRAC R_BRAC 												{ $$ = new FunctionCall($1); }
	//| POSTFIX_EXPRESSION L_BRAC EXPRESSION_LIST L_BRAC 							{ $$ = new FunctionCall($1, $3); } // needs to be implemented in grammar
	| POSTFIX_EXPRESSION DOT ID 													{ $$ = new DotOperator($1, $3); }
	| POSTFIX_EXPRESSION ARROW ID 													{ $$ = new ArrowOperator($1, $3); }
	| POSTFIX_EXPRESSION INCR 														{ $$ = new PostfixExpr($1, $2); }
	| POSTFIX_EXPRESSION DECR 														{ $$ = new PostfixExpr($1, $2); }

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

PRIMARY_EXPRESSION
	: VAR_CONST																		{ $$ = $1;}
	| STRING																		{ $$ = new StringLiteral(*$1);}
	| L_BRAC EXPRESSION R_BRAC														{ $$ = $2;}

VAR_CONST
	: IDENTIFIER																	{ $$ = new Variable($1);}
	| I_CONSTANT																	{ $$ = new IntConstant(*$1);}
	| F_CONSTANT																	{ $$ = new FloatConstant(*$1);}
	| C_CONSTANT 																	{ $$ = new CharConstant(*$1); }

ASSIGNMENT_OP
	: EQUAL 																		{ $$ = $1; }
	| MUL_ASS  																		{ $$ = $1; }
	| DIV_ASS 																		{ $$ = $1; }
	| MOD_ASS 																		{ $$ = $1; }
	| ADD_ASS 																		{ $$ = $1; }
	| SUB_ASS 																		{ $$ = $1; }
	| LL_ASS 																		{ $$ = $1; }
	| RR_ASS 																		{ $$ = $1; }
	| AND_ASS 																		{ $$ = $1; }
	| XOR_ASS 																		{ $$ = $1; }
	| OR_ASS 																		{ $$ = $1; }


///////////////////////////////////////////////////////////////// DECLARATIONS ///////////////////////////////////////////////////////////////////

DECLARATION_SEQ
	: DECLARATION																	{ $$ = new DeclarationList($1);}
	| DECLARATION_SEQ DECLARATIONS													{ $$ -> add($2); }

DECLARATION
	: DECLARATION_SPECIFIER SEMICOLON												{ $$ = new Declaration($1,( new List({}) ) ); }
	| DECLARATION_SPECIFIER INIT_DECLARATOR_LIST SEMICOLON							{ $$ = new Declaration($1, $2); }

DECLARATION_SPECIFIER	
	: TYPE_SPECIFIER																{ $$ = $1 ; }
	| TYPE_QUALIFIER																{ $$ = $1 ; }
	| STORAGE_CLASS_SPECIFIER														{ $$ = $1 ; }
	| TYPE_SPECIFIER DECLARATION_SPECIFIER											{ $2->add($1); $$ = $2; delete $1; }
	| TYPE_QUALIFIER DECLARATION_SPECIFIER											{ $2->add($1); $$ = $2; delete $1; }
	| STORAGE_CLASS_SPECIFIER DECLARATION_SPECIFIER									{ $2->add($1); $$ = $2; delete $1; }

TYPE_SPECIFIER
	: VOID			          														{ $$ = new Type(Void);}
	| CHAR			        														{ $$ = new Type(Char);}
	| INT			            													{ $$ = new Type(Int);}
	| SHORT			        														{ $$ = new Type(Short);}
	| LONG			        														{ $$ = new Type(Long);}
	| FLOAT			          														{ $$ = new Type(Float);}
	| DOUBLE		        														{ $$ = new Type(Double);}
	| SIGNED		        														{ $$ = new Type(Signed);}
	| UNSIGNED		      															{ $$ = new Type(Unsigned);}

INIT_DECLARATOR_LIST
	: INIT_DECLARATOR	                                  							{ $$ = new DeclarationList($1); }
	| INIT_DECLARATOR_LIST COMMA INIT_DECLARATOR									{ $$ -> add($3); }

INIT_DECLARATOR
	: DECLARATOR		                      										{ $$ = $1; }
	//| DECLARATOR EQUAL INITIALIZER													{ $$ = new InitDeclarator($1,$3); if ($1->getPtr()){$$->setPtr();} } //TOO HARD!!!!

INITIALIZER
	: ASSIGNMENT_EXPRESSION															{ $$ = $1; }

DECLARATOR
	: DIRECT_DECLARATOR                                     						{ $$ = $1; }
	| TIMES DIRECT_DECLARATOR 														{ $$ = $2; ((const Declarator *)$$) -> setPtr();} //Think this rule will work

IDENTIFIER_LIST
	: ID 																			{ $$ = new List({new Variable($1)}); }

DIRECT_DECLARATOR
	: L_BRAC DECLARATOR R_BRAC														{ $$ = $2; }
	| IDENTIFIER																	{ $$ = new Variable($1);}
	| L_BRAC R_BRAC DECLARATOR														{ $$ = $2; }
	| DIRECT_DECLARATOR L_SQUARE R_SQUARE											{ $$ = new ArrayDeclarator($1, new Constant("-1")); } 	// Undefined Array 
	| DIRECT_DECLARATOR L_SQUARE CONSTANT_EXPRESSION R_SQUARE						{ $$ = new ArrayDeclarator($1, $3); }   				// Defined Array 
	| DIRECT_DECLARATOR L_BRAC R_BRAC												{ $$ = new FunctionDeclarator($1,( new List({}) ) ); } 	// Nullary Function
	| DIRECT_DECLARATOR L_BRAC PARAMETER_LIST R_BRAC				                { $$ = new FunctionDeclarator($1, $3); } 				// Unary|Binary Function 
	| DIRECT_DECLARATOR L_BRAC IDENTIFIER_LIST R_BRAC								{ $$ = new FunctionDeclarator($1, $3); } 	//ExtraHard // Complex Unary|Binary Function 

PARAMETER_LIST 
	: PARAMETER_DECLARATION 														{ $$ = new ParameterList({$1}); }
	| PARAMETER_LIST COMMA DECLARATION_SPECIFIER DECLARATOR							{ $$ -> add(new Declaration($1, new DeclarationList({$2}) ) ); }

/////////////////////////////////////////////////////////////////// END OF GRAMMAR RULES /////////////////////////////////////////////////////////////////////////

%%

const baseNode *g_root; 

const baseNode *parseAST()
{
	g_root=0;
	yyparse();
	return g_root;
}
