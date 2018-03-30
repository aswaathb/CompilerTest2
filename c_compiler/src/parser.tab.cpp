/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "src/parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
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
#line 1 "src/parser.y" /* yacc.c:355  */

	#include "ast.hpp"

	#include <cassert>

	extern const baseNode *g_root; // A way of getting the AST out

	//! This is to fix problems when generating C++
	// We are declaring the functions provided by Flex, so
	// that Bison generated code can call them.
	int yylex(void);
	void yyerror(const char *);

#line 111 "src/parser.tab.cpp" /* yacc.c:355  */

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
    SIZEOF = 325
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "src/parser.y" /* yacc.c:355  */

	const baseNode 		*node;
	const Declaration 	*decl;
	const Expression 	*expr;
	const ExprStatement *exprstat;
	const Function 		*func;
	const List			*list;
	const Statement 	*stat;
	const Type 			*type;

	std::string 		*str;

#line 207 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 224 "src/parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   894

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  248

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    76,    77,    81,    82,    87,    96,    97,
      98,    99,   101,   104,   105,   106,   107,   110,   111,   114,
     115,   116,   119,   120,   121,   122,   123,   124,   127,   128,
     129,   130,   136,   137,   140,   141,   144,   145,   149,   150,
     153,   154,   158,   159,   163,   164,   167,   168,   171,   172,
     175,   176,   177,   180,   181,   182,   183,   184,   187,   188,
     189,   192,   193,   194,   197,   198,   199,   200,   203,   204,
     208,   209,   210,   211,   212,   213,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   228,   229,   230,   232,   233,
     234,   235,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   249,   250,   251,   254,   255,   256,   257,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   276,
     277,   280,   281,   284,   285,   286,   287,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   301,   302,   305,   312,
     313,   316,   319,   320,   321,   322,   323,   324,   325,   328,
     329
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "F_CONST", "I_CONST",
  "C_CONST", "PLUS", "MINUS", "TIMES", "DIVIDE", "MODULUS", "LOR", "LAND",
  "OR", "NEQUAL", "LESSEQUAL", "LESSTHAN", "GREATEQUAL", "GREATTHAN",
  "AND", "XOR", "L_SHIFT", "R_SHIFT", "MUL_ASS", "DIV_ASS", "MOD_ASS",
  "ADD_ASS", "SUB_ASS", "LL_ASS", "RR_ASS", "AND_ASS", "XOR_ASS", "OR_ASS",
  "ARROW", "DECR", "INCR", "VOID", "CHAR", "SHORT", "INT", "LONG", "FLOAT",
  "DOUBLE", "SIGNED", "UNSIGNED", "CONST", "DO", "WHILE", "IF", "ELSE",
  "FOR", "SWITCH", "RETURN", "CONTINUE", "BREAK", "GOTO", "EQUAL",
  "SEMICOLON", "COMMA", "L_BRAC", "R_BRAC", "L_CURLY", "R_CURLY",
  "L_SQUARE", "R_SQUARE", "QUES_MARK", "COLON", "DOT", "STRING", "SIZEOF",
  "$accept", "ROOT", "TRANSLATION_UNIT", "EXTERNAL_DECLARATION",
  "FUNCTION_DEFINITION", "STATEMENT", "COMPOUND_STATEMENT",
  "STATEMENT_LIST", "SELECTION_STATEMENT", "ITERATION_STATEMENT",
  "JUMP_STATEMENT", "EXPRESSION_STATEMENT", "EXPRESSION",
  "ASSIGNMENT_EXPRESSION", "CONDITIONAL_EXPRESSION",
  "LOGICAL_OR_EXPRESSION", "LOGICAL_AND_EXPRESSION",
  "INCLUSIVE_OR_EXPRESSION", "EXCLUSIVE_OR_EXPRESSION", "AND_EXPRESSION",
  "EQUALITY_EXPRESSION", "RELATIONAL_EXPRESSION", "SHIFT_EXPRESSION",
  "ADDITIVE_EXPRESSION", "MULTIPLCATIVE_EXPRESSION", "CAST_EXPRESSION",
  "PREFIX_EXPRESSION", "UNARY_OPERATOR", "POSTFIX_EXPRESSION", "TYPE_NAME",
  "PRIMARY_EXPRESSION", "VARIABLE_CONSTANT", "ASSIGNMENT_OP",
  "DECLARATION_SEQ", "DECLARATION", "DECLARATION_SPECIFIER",
  "TYPE_SPECIFIER", "INIT_DECLARATOR_LIST", "INIT_DECLARATOR",
  "DECLARATOR", "IDENTIFIER_LIST", "DIRECT_DECLARATOR", "PARAMETER_LIST", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325
};
# endif

#define YYPACT_NINF -129

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-129)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     106,  -129,    16,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,    94,     4,    27,   106,  -129,  -129,  -129,    13,
      94,   -24,   -30,   -30,  -129,    15,   -29,  -129,  -129,  -129,
     -44,  -129,  -129,  -129,   186,  -129,    17,   -20,  -129,  -129,
    -129,    15,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,   788,   788,   458,   -11,    14,
      26,    60,   680,    68,    72,   139,  -129,   594,  -129,  -129,
     105,  -129,  -129,   322,  -129,  -129,  -129,  -129,    -7,  -129,
    -129,    11,   165,   167,   164,   177,    22,    23,    44,    73,
      74,  -129,   524,   824,    93,  -129,  -129,   254,  -129,  -129,
    -129,    15,   126,   -26,  -129,  -129,   824,  -129,  -129,   153,
     824,   824,   526,   824,  -129,  -129,  -129,   144,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,    55,   142,   637,
    -129,  -129,  -129,   824,   824,   824,   824,   824,   824,   824,
     824,   824,   824,   824,   824,   824,   824,   824,   824,   824,
     824,   824,   824,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,   824,  -129,  -129,   202,  -129,  -129,
     147,   824,   206,  -129,   390,  -129,  -129,  -129,    94,  -129,
     150,    58,    62,   680,   680,    95,  -129,  -129,   824,   151,
     152,  -129,   165,   -38,   167,   164,   177,    22,    23,    23,
      44,    44,    44,    44,    73,    73,    74,    74,  -129,  -129,
    -129,  -129,  -129,  -129,   -34,  -129,  -129,    15,   824,   458,
     458,   716,   752,   458,  -129,  -129,  -129,   824,  -129,  -129,
     101,  -129,   161,   458,   110,   458,   111,  -129,  -129,  -129,
     458,  -129,   458,  -129,   458,  -129,  -129,  -129
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   143,     0,   127,   128,   130,   129,   131,   132,   133,
     134,   135,   124,     0,     0,     2,     3,     6,     5,     0,
     123,     0,   139,   140,   126,     0,     0,     1,     4,   121,
       0,   136,   138,   125,     0,     7,     0,     0,   144,   142,
     122,     0,   104,   106,   105,   107,    79,    80,    78,    84,
      82,    77,    81,    76,    83,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,    13,   102,
       0,    17,     8,     0,     9,    10,    11,    12,     0,    34,
      36,    38,    40,    42,    44,    46,    48,    50,    53,    58,
      61,    64,    69,     0,    70,    85,   101,     0,   119,   141,
     146,     0,     0,     0,   145,   137,     0,    72,    71,     0,
       0,     0,     0,     0,    28,    30,    31,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
      15,    18,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   108,     0,    73,    69,     0,    91,    90,
       0,     0,     0,    14,     0,   120,   149,   148,     0,   147,
       0,     0,     0,     0,     0,     0,    29,   103,     0,     0,
       0,    35,    41,     0,    43,    45,    47,    49,    52,    51,
      55,    54,    57,    56,    59,    60,    62,    63,    65,    66,
      67,    37,    89,    87,     0,    88,    16,     0,     0,     0,
       0,     0,     0,     0,    68,    74,    75,     0,    86,   150,
       0,    22,    19,     0,     0,     0,     0,    21,    39,    23,
       0,    24,     0,    26,     0,    20,    25,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,   199,  -129,   -56,   194,   119,  -129,  -129,
    -129,   -59,   -63,  -128,    -9,  -129,    83,    84,    82,    98,
     104,    33,   -32,    29,    34,   -82,   -47,  -129,  -129,   116,
    -129,  -129,  -129,  -129,    10,   -10,  -129,  -129,   209,   -13,
    -129,   245,  -129
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,    16,    17,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,   128,
      95,    96,   164,    97,    18,    19,    20,    30,    31,    21,
     102,    22,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,   109,    24,   114,   127,   191,    32,     1,   107,   108,
      33,   165,    38,     2,    40,    41,     1,   131,     1,     1,
      99,   133,     2,   134,     2,   133,   101,    27,    32,   227,
      36,   228,    39,   178,    37,   179,   211,   140,    34,   142,
     143,   144,   145,   127,    98,   104,   166,   181,   182,   110,
     185,   132,   133,   183,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    25,   146,   147,   208,   209,
     210,    29,   193,    13,   111,    13,    13,   135,   100,   141,
     148,   149,   189,   150,   151,   152,   112,   166,   176,   166,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   224,   175,   214,     1,
     200,   201,   202,   203,   133,     2,   187,   133,   131,   219,
     113,   133,   184,   220,   221,   222,   115,   167,   168,   169,
     116,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   166,   117,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,   170,   133,   230,   223,   171,   234,   236,
     133,   172,   239,   231,   232,   129,    13,   237,   217,   133,
     133,   242,   244,   198,   199,   204,   205,   241,   136,   243,
     166,   137,   206,   207,   245,   138,   246,   177,   247,    42,
      43,    44,    45,    46,    47,    48,    49,   139,    50,    51,
      52,   180,   186,   188,   229,   212,    53,    54,   213,   215,
     218,   240,   225,   226,    28,    35,   174,   192,   238,   195,
     194,    55,    56,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    57,    58,    59,   196,    60,    61,    62,
      63,    64,    65,   197,    66,   190,    67,    23,    34,    68,
     105,     0,     0,     0,     0,    69,    70,    42,    43,    44,
      45,    46,    47,    48,    49,     0,    50,    51,    52,     0,
       0,     0,     0,     0,    53,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    57,    58,    59,     0,    60,    61,    62,    63,    64,
      65,     0,    66,     0,    67,     0,    34,   173,     0,     0,
       0,     0,     0,    69,    70,    42,    43,    44,    45,    46,
      47,    48,    49,     0,    50,    51,    52,     0,     0,     0,
       0,     0,    53,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      58,    59,     0,    60,    61,    62,    63,    64,    65,     0,
      66,     0,    67,     0,    34,   130,     0,     0,     0,     0,
       0,    69,    70,    42,    43,    44,    45,    46,    47,    48,
      49,     0,    50,    51,    52,     0,     0,     0,     0,     0,
      53,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    58,    59,
       0,    60,    61,    62,    63,    64,    65,     0,    66,     0,
      67,     0,    34,   216,     0,     0,     0,     0,     0,    69,
      70,    42,    43,    44,    45,    46,    47,    48,    49,     0,
      50,    51,    52,     0,     0,     0,     0,     0,    53,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    58,    59,     0,    60,
      61,    62,    63,    64,    65,     0,    66,     0,    67,     0,
      34,     0,     0,     0,     0,     0,     0,    69,    70,    42,
      43,    44,    45,    46,    47,    48,    49,     0,    50,    51,
      52,     0,     0,     0,     0,     0,    53,    54,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,     0,     0,
       0,    55,    56,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     0,
       0,   163,     0,     0,    66,     0,    67,     0,     0,     0,
       0,     0,     0,     0,     0,    69,    70,    42,    43,    44,
      45,    46,    47,    48,    49,     0,    50,    51,    52,     0,
       0,     0,     0,     0,    53,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,   118,   119,   120,   121,   122,   123,   124,   125,   126,
      42,    43,    44,    45,    46,    47,    48,    49,     0,    50,
      51,    52,     0,     0,    67,     0,     0,    53,    54,     0,
       0,     0,     0,    69,    70,     0,     0,     0,     0,     0,
       0,     0,    55,    56,   118,   119,   120,   121,   122,   123,
     124,   125,   126,    42,    43,    44,    45,    46,    47,    48,
      49,     0,    50,    51,    52,     0,     0,   106,     0,     0,
      53,    54,     0,     0,     0,     0,    69,    70,     0,     0,
       0,     0,     0,     0,     0,    55,    56,     0,     0,    42,
      43,    44,    45,    46,    47,    48,    49,     0,    50,    51,
      52,     0,     0,     0,     0,     0,    53,    54,    66,     0,
      67,     0,     0,     0,     0,     0,     0,     0,     0,    69,
      70,    55,    56,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,     0,    50,    51,    52,     0,     0,     0,
       0,     0,    53,    54,     0,     0,    67,   233,     0,     0,
       0,     0,     0,     0,     0,    69,    70,    55,    56,     0,
       0,    42,    43,    44,    45,    46,    47,    48,    49,     0,
      50,    51,    52,     0,     0,     0,     0,     0,    53,    54,
       0,     0,    67,   235,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    55,    56,     0,     0,    42,    43,    44,
      45,    46,    47,    48,    49,     0,    50,    51,    52,     0,
       0,     0,     0,     0,    53,    54,     0,     0,   106,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70
};

static const yytype_int16 yycheck[] =
{
      13,    57,    12,    62,    67,   133,    19,     3,    55,    56,
      20,    93,    25,     9,    58,    59,     3,    73,     3,     3,
       3,    59,     9,    12,     9,    59,    36,     0,    41,    67,
      60,    65,    61,    59,    64,    61,   164,    15,    62,    16,
      17,    18,    19,   106,    34,    65,    93,   110,   111,    60,
     113,    58,    59,   112,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    60,    61,    22,    23,   150,   151,
     152,    58,   135,    60,    60,    60,    60,    66,    61,    57,
       7,     8,   129,     9,    10,    11,    60,   134,   101,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   188,    97,   171,     3,
     142,   143,   144,   145,    59,     9,    61,    59,   174,    61,
      60,    59,   112,    61,   183,   184,    58,    34,    35,    36,
      58,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,   188,     3,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    60,    59,   218,    61,    64,   221,   222,
      59,    68,    61,   219,   220,    60,    60,   223,   178,    59,
      59,    61,    61,   140,   141,   146,   147,   233,    13,   235,
     227,    14,   148,   149,   240,    21,   242,    61,   244,     3,
       4,     5,     6,     7,     8,     9,    10,    20,    12,    13,
      14,    48,    58,    61,   217,     3,    20,    21,    61,     3,
      60,    50,    61,    61,    15,    21,    97,   134,   227,   137,
     136,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,   138,    51,    52,    53,
      54,    55,    56,   139,    58,   129,    60,     2,    62,    63,
      41,    -1,    -1,    -1,    -1,    69,    70,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    51,    52,    53,    54,    55,
      56,    -1,    58,    -1,    60,    -1,    62,    63,    -1,    -1,
      -1,    -1,    -1,    69,    70,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    49,    -1,    51,    52,    53,    54,    55,    56,    -1,
      58,    -1,    60,    -1,    62,    63,    -1,    -1,    -1,    -1,
      -1,    69,    70,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      -1,    51,    52,    53,    54,    55,    56,    -1,    58,    -1,
      60,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    69,
      70,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,    51,
      52,    53,    54,    55,    56,    -1,    58,    -1,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    20,    21,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    58,    -1,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    -1,    60,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,    -1,    60,    -1,    -1,
      20,    21,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    20,    21,    58,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    35,    36,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    20,    21,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    70,    35,    36,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,    21,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    35,    36,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    60,    72,    73,    74,    75,   105,   106,
     107,   110,   112,   112,   106,    61,   110,     0,    74,    58,
     108,   109,   110,   106,    62,    77,    60,    64,   110,    61,
      58,    59,     3,     4,     5,     6,     7,     8,     9,    10,
      12,    13,    14,    20,    21,    35,    36,    47,    48,    49,
      51,    52,    53,    54,    55,    56,    58,    60,    63,    69,
      70,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   101,   102,   104,   105,     3,
      61,   106,   111,   113,    65,   109,    60,    97,    97,    76,
      60,    60,    60,    60,    82,    58,    58,     3,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    83,   100,    60,
      63,    76,    58,    59,    12,    66,    13,    14,    21,    20,
      15,    57,    16,    17,    18,    19,    22,    23,     7,     8,
       9,    10,    11,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    57,   103,    96,    97,    34,    35,    36,
      60,    64,    68,    63,    78,   105,   110,    61,    59,    61,
      48,    83,    83,    82,   105,    83,    58,    61,    61,    97,
     100,    84,    87,    83,    88,    89,    90,    91,    92,    92,
      93,    93,    93,    93,    94,    94,    95,    95,    96,    96,
      96,    84,     3,    61,    83,     3,    63,   106,    60,    61,
      61,    82,    82,    61,    96,    61,    61,    67,    65,   110,
      83,    76,    76,    61,    83,    61,    83,    76,    85,    61,
      50,    76,    61,    76,    61,    76,    76,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    75,    76,    76,
      76,    76,    76,    77,    77,    77,    77,    78,    78,    79,
      79,    79,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    89,    89,    90,    90,
      91,    91,    91,    92,    92,    92,    92,    92,    93,    93,
      93,    94,    94,    94,    95,    95,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   101,   101,   102,   102,   102,   102,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   105,   105,   106,   106,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   108,   109,   110,
     110,   111,   112,   112,   112,   112,   112,   112,   112,   113,
     113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     3,     3,     4,     1,     2,     5,
       7,     5,     5,     6,     6,     7,     6,     7,     2,     3,
       2,     2,     1,     2,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     4,     1,
       1,     2,     2,     2,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     1,     3,     1,     3,     3,     3,     4,     4,     2,
       4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 73 "src/parser.y" /* yacc.c:1646  */
    { g_root = (const baseNode *)(yyvsp[0].node); }
#line 1628 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 76 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TranslationUnit( {(yyvsp[0].node)} ); }
#line 1634 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 77 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node)->add((yyvsp[0].node));}
#line 1640 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 81 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].decl);}
#line 1646 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 82 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].func);}
#line 1652 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 87 "src/parser.y" /* yacc.c:1646  */
    { (yyval.func) = new FunctionDefinition((yyvsp[-1].node), (yyvsp[0].stat));}
#line 1658 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 96 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = (yyvsp[0].stat);}
#line 1664 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 97 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = (yyvsp[0].stat);}
#line 1670 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 98 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = (yyvsp[0].stat);}
#line 1676 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 99 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = (yyvsp[0].stat);}
#line 1682 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 101 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = (yyvsp[0].exprstat);}
#line 1688 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 104 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new CompoundStatement();}
#line 1694 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 105 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new CompoundStatement( (yyvsp[-1].list), new List({}) ); }
#line 1700 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 106 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new CompoundStatement( new List({}), (yyvsp[-1].list)); }
#line 1706 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 107 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new CompoundStatement( (yyvsp[-2].list), (yyvsp[-1].list) ); }
#line 1712 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 110 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) = new List({(yyvsp[0].stat)}); }
#line 1718 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 111 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) -> add((yyvsp[0].stat)); }
#line 1724 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 114 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new IfElseStatement((yyvsp[-2].expr), (yyvsp[0].stat), new CompoundStatement());}
#line 1730 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 115 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new IfElseStatement((yyvsp[-4].expr), (yyvsp[-2].stat), (yyvsp[0].stat));}
#line 1736 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 116 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new SwitchStatement((yyvsp[-2].expr), (yyvsp[0].stat)); }
#line 1742 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 119 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new WhileStatement((yyvsp[-2].expr), (yyvsp[0].stat));}
#line 1748 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 120 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new DoWhileStatement((yyvsp[-4].stat), (yyvsp[-1].expr));}
#line 1754 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 121 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new ExprExprFor((yyvsp[-3].exprstat), (yyvsp[-2].exprstat), (yyvsp[0].stat));}
#line 1760 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 122 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new ExprExprExprFor((yyvsp[-4].exprstat), (yyvsp[-3].exprstat), (yyvsp[-2].expr), (yyvsp[0].stat));}
#line 1766 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 123 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new DecExprFor((yyvsp[-3].decl), (yyvsp[-2].exprstat), (yyvsp[0].stat));}
#line 1772 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 124 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new DecExprExprFor((yyvsp[-4].decl),(yyvsp[-3].exprstat),(yyvsp[-2].expr),(yyvsp[0].stat));}
#line 1778 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 127 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new ReturnStatement((yyvsp[0].exprstat));}
#line 1784 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 128 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new GotoStatement(*(yyvsp[-1].str));}
#line 1790 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 129 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new ContinueStatement();}
#line 1796 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 130 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new BreakStatement();}
#line 1802 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 136 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprstat) = new ExprStatement(new Expression_Null());}
#line 1808 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 137 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprstat) = new ExprStatement((yyvsp[-1].expr));}
#line 1814 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 140 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1820 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 141 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) -> add((yyvsp[0].expr)); }
#line 1826 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 144 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1832 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 145 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignmentExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1838 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 149 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1844 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 150 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TernaryExpression((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1850 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 153 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1856 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 154 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1862 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 158 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1868 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 159 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1874 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 163 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1880 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 164 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1886 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 167 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1892 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 168 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1898 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 171 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1904 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 172 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1910 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 175 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1916 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 176 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1922 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 177 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1928 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 180 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1934 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 181 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1940 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1946 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 183 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1952 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 184 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1958 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 187 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1964 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 188 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1970 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 189 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1976 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 192 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1982 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1988 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 194 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1994 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 197 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2000 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2006 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 199 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2012 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 200 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2018 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 203 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CastExpr((yyvsp[0].expr), (yyvsp[-2].str)); }
#line 2024 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 204 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2030 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 208 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2036 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 209 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PrefixExpr((yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2042 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 210 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PrefixExpr((yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2048 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PrefixExpr((yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2054 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PrefixExpr((yyvsp[-1].expr), (yyvsp[-3].str)); }
#line 2060 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 213 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PrefixExpr((yyvsp[-1].str), (yyvsp[-3].str)); }
#line 2066 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 228 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2072 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 229 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new SquareOperator((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2078 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 230 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FunctionCall((yyvsp[-2].expr)); }
#line 2084 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 232 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DotOperator((yyvsp[-2].expr), (yyvsp[0].str)); }
#line 2090 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 233 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrowOperator((yyvsp[-2].expr), (yyvsp[0].str)); }
#line 2096 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 234 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixExpr((yyvsp[-1].expr), (yyvsp[0].str)); }
#line 2102 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 235 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixExpr((yyvsp[-1].expr), (yyvsp[0].str)); }
#line 2108 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 249 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2114 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 250 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new StringLiteral(*(yyvsp[0].str));}
#line 2120 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 251 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr);}
#line 2126 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 254 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Variable((yyvsp[0].str));}
#line 2132 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 255 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntConstant(*(yyvsp[0].str));}
#line 2138 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 256 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FloatConstant(*(yyvsp[0].str));}
#line 2144 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 257 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CharConstant(*(yyvsp[0].str)); }
#line 2150 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 260 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2156 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 261 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2162 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 262 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2168 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 263 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2174 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 264 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2180 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 265 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2186 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 266 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2192 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 267 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2198 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 268 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2204 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 269 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2210 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 270 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2216 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 276 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) = new DeclarationList((yyvsp[0].decl));}
#line 2222 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 277 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) -> add((yyvsp[0].decl)); }
#line 2228 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 280 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl) = new Declaration((yyvsp[-1].type),( new List({}) ) ); }
#line 2234 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 281 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl) = new Declaration((yyvsp[-2].type), (yyvsp[-1].list)); }
#line 2240 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 284 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type) ; }
#line 2246 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 285 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(const) ; }
#line 2252 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 286 "src/parser.y" /* yacc.c:1646  */
    { (yyvsp[0].type)->add((yyvsp[-1].type)); (yyval.type) = (yyvsp[0].type); delete (yyvsp[-1].type); }
#line 2258 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 287 "src/parser.y" /* yacc.c:1646  */
    { (yyvsp[0].type)->add(new Type(const) ); (yyval.type) = (yyvsp[0].type); delete (yyvsp[-1].type); }
#line 2264 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 290 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Void);}
#line 2270 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 291 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Char);}
#line 2276 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 292 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Int);}
#line 2282 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 293 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Short);}
#line 2288 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 294 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Long);}
#line 2294 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 295 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Float);}
#line 2300 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 296 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Double);}
#line 2306 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Signed);}
#line 2312 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 298 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Unsigned);}
#line 2318 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 301 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) = new DeclarationList((yyvsp[0].node)); }
#line 2324 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 302 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) -> add((yyvsp[0].node)); }
#line 2330 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 305 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2336 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 312 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2342 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 313 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); ((const Declarator *)(yyval.node)) -> setPtr();}
#line 2348 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 316 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) = new List({new Variable((yyvsp[0].str))}); }
#line 2354 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 319 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2360 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 320 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Variable((yyvsp[0].str));}
#line 2366 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 321 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].str); }
#line 2372 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 322 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ArrayDeclarator((yyvsp[-2].node), new Constant("-1")); }
#line 2378 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 323 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionDeclarator((yyvsp[-2].node),( new List({}) ) ); }
#line 2384 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 324 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionDeclarator((yyvsp[-3].node), (yyvsp[-1].list)); }
#line 2390 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 325 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionDeclarator((yyvsp[-3].node), (yyvsp[-1].list)); }
#line 2396 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 328 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) = new ParameterList({ new Declaration((yyvsp[-1].type), new DeclarationList({ (yyvsp[0].node) }) ) }); }
#line 2402 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 329 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) -> add(new Declaration((yyvsp[-3].list), new DeclarationList({(yyvsp[-2].str)}) ) ); }
#line 2408 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2412 "src/parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 333 "src/parser.y" /* yacc.c:1906  */


const baseNode *g_root; 

const baseNode *parseAST()
{
	g_root=0;
	yyparse();
	return g_root;
}
