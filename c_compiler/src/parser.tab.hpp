/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y" /* yacc.c:1909  */

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

#line 69 "src/parser.tab.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    F_CONST = 259,
    I_CONST = 260,
    C_CONST = 261,
    PLUS = 262,
    MINUS = 263,
    TIMES = 264,
    DIVIDE = 265,
    MODULUS = 266,
    LOR = 267,
    LAND = 268,
    OR = 269,
    NEQUAL = 270,
    LESSEQUAL = 271,
    LESSTHAN = 272,
    GREATEQUAL = 273,
    GREATTHAN = 274,
    AND = 275,
    XOR = 276,
    L_SHIFT = 277,
    R_SHIFT = 278,
    MUL_ASS = 279,
    DIV_ASS = 280,
    MOD_ASS = 281,
    ADD_ASS = 282,
    SUB_ASS = 283,
    LL_ASS = 284,
    RR_ASS = 285,
    AND_ASS = 286,
    XOR_ASS = 287,
    OR_ASS = 288,
    ARROW = 289,
    DECR = 290,
    INCR = 291,
    VOID = 292,
    CHAR = 293,
    SHORT = 294,
    INT = 295,
    LONG = 296,
    FLOAT = 297,
    DOUBLE = 298,
    SIGNED = 299,
    UNSIGNED = 300,
    CONST = 301,
    DO = 302,
    WHILE = 303,
    IF = 304,
    ELSE = 305,
    FOR = 306,
    SWITCH = 307,
    RETURN = 308,
    CONTINUE = 309,
    BREAK = 310,
    GOTO = 311,
    EQUAL = 312,
    SEMICOLON = 313,
    COMMA = 314,
    L_BRAC = 315,
    R_BRAC = 316,
    L_CURLY = 317,
    R_CURLY = 318,
    L_SQUARE = 319,
    R_SQUARE = 320,
    QUES_MARK = 321,
    COLON = 322,
    DOT = 323,
    STRING = 324,
    SIZEOF = 325,
    CONDITIONAL_EXPRESSION = 326,
    LOGICAL_OR_EXPRESSION = 327,
    LOGICAL_AND_EXPRESSION = 328,
    INCLUSIVE_OR_EXPRESSION = 329,
    EXCLUSIVE_OR_EXPRESSION = 330,
    AND_EXPRESSION = 331,
    RELATIONAL_EXPRESSION = 332,
    SHIFT_EXPRESSION = 333,
    CAST_EXPRESSION = 334,
    PREFIX_EXPRESSION = 335,
    POSTFIX_EXPRESSION = 336,
    VARIABLE_CONSTANT = 337
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "src/parser.y" /* yacc.c:1909  */

	const baseNode 		*node;
	const CompoundStatement *compstat;
	const Declaration 	*decl;
	const Expression 	*expr;
	const ExprStatement *exprstat;
	const List			*list;
	const Statement 	*stat;
	const Type 			*type;

	std::string 		*str;

#line 177 "src/parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
