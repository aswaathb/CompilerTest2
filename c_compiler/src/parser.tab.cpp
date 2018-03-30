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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   895

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

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
       0,    73,    73,    76,    77,    82,    83,    94,    95,    96,
      97,    99,   102,   103,   104,   105,   108,   109,   112,   113,
     114,   117,   118,   119,   120,   121,   122,   125,   126,   127,
     128,   134,   135,   138,   139,   142,   143,   147,   148,   151,
     152,   156,   157,   161,   162,   165,   166,   169,   170,   173,
     174,   175,   178,   179,   180,   181,   182,   185,   186,   187,
     190,   191,   192,   195,   196,   197,   198,   201,   202,   206,
     207,   208,   209,   210,   211,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   226,   227,   228,   230,   231,   232,
     233,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     247,   248,   249,   252,   253,   254,   255,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   274,   275,
     278,   279,   282,   283,   284,   285,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   299,   300,   303,   304,   307,
     310,   311,   314,   317,   318,   319,   320,   321,   322,   323,
     326,   328,   331
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
  "STATEMENT", "COMPOUND_STATEMENT", "STATEMENT_LIST",
  "SELECTION_STATEMENT", "ITERATION_STATEMENT", "JUMP_STATEMENT",
  "EXPRESSION_STATEMENT", "EXPRESSION", "ASSIGNMENT_EXPRESSION",
  "CONDITIONAL_EXPRESSION", "LOGICAL_OR_EXPRESSION",
  "LOGICAL_AND_EXPRESSION", "INCLUSIVE_OR_EXPRESSION",
  "EXCLUSIVE_OR_EXPRESSION", "AND_EXPRESSION", "EQUALITY_EXPRESSION",
  "RELATIONAL_EXPRESSION", "SHIFT_EXPRESSION", "ADDITIVE_EXPRESSION",
  "MULTIPLCATIVE_EXPRESSION", "CAST_EXPRESSION", "PREFIX_EXPRESSION",
  "UNARY_OPERATOR", "POSTFIX_EXPRESSION", "TYPE_NAME",
  "PRIMARY_EXPRESSION", "VARIABLE_CONSTANT", "ASSIGNMENT_OP",
  "DECLARATION_SEQ", "DECLARATION", "DECLARATION_SPECIFIER",
  "TYPE_SPECIFIER", "INIT_DECLARATOR_LIST", "INIT_DECLARATOR",
  "INITIALIZER", "DECLARATOR", "IDENTIFIER_LIST", "DIRECT_DECLARATOR",
  "PARAMETER_LIST", "PARAMETER_DECLARATOR", YY_NULLPTR
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

#define YYPACT_NINF -76

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-76)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     120,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     120,    20,   120,   -76,   -76,    56,   120,   -76,   -76,   -76,
     -76,     6,   -76,    52,   -30,   -76,   -39,   -34,   -76,   -34,
      47,   -25,   -76,    47,   789,   187,   -76,     3,   -26,   -76,
     -76,   -76,    10,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   825,   825,   595,   -76,
      35,   -76,   -76,     2,    44,    89,    94,    90,    -3,    83,
      29,    55,    22,   -76,   123,   789,    62,   -76,   -76,   -76,
     459,    77,   107,   108,   128,   681,    70,    84,   174,   -76,
     -76,   -76,   -76,   323,   -76,   -76,   -76,   -76,    65,   -76,
     255,   -76,    56,   -76,   -76,    47,   122,   -24,   -76,   789,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,    -1,   137,   638,   789,   789,   789,   789,   789,   789,
     789,   789,   789,   789,   789,   789,   789,   789,   789,   789,
     789,   789,   789,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   789,   -76,   -76,   201,   -76,   -76,
     145,   789,   206,   162,   789,   789,   527,   789,   -76,   -76,
     -76,   153,   -76,   -76,   -76,   789,   -76,   391,   -76,   -76,
     -76,   120,   -76,   -76,   789,   151,   152,    44,   -43,    89,
      94,    90,    -3,    83,    83,    29,    29,    29,    29,    55,
      55,    22,    22,   -76,   -76,   -76,   -76,   -76,   -76,   -40,
     -76,   154,    45,    58,   681,   681,    68,   -76,   -76,   -76,
      47,   -76,   -76,   -76,   -76,   789,   -76,   789,   459,   459,
     717,   753,   459,   -76,   -76,    82,   -76,   165,   459,   117,
     459,   125,   -76,   -76,   459,   -76,   459,   -76,   459,   -76,
     -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   126,   127,   129,   128,   130,   131,   132,   133,   134,
     123,     0,     2,     3,     5,     0,   122,   125,     1,     4,
     144,     0,   120,     0,     0,   135,   137,   140,   124,   141,
       0,     0,   121,     0,     0,     0,     6,     0,     0,   145,
     143,   136,   137,   103,   105,   104,   106,    78,    79,    77,
      83,    81,    76,    80,    75,    82,     0,     0,     0,   101,
       0,   139,    35,    37,    39,    41,    43,    45,    47,    49,
      52,    57,    60,    63,    68,     0,    69,    84,   100,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      12,    16,     7,     0,     8,     9,    10,    11,     0,    33,
       0,   118,     0,   142,   147,     0,     0,     0,   146,     0,
      71,    70,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   107,     0,    72,    68,     0,    90,    89,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    29,
      30,     0,    14,    17,    32,     0,    13,     0,   119,   150,
     149,     0,   148,   102,     0,     0,     0,    40,     0,    42,
      44,    46,    48,    51,    50,    54,    53,    56,    55,    58,
      59,    61,    62,    64,    65,    66,    36,    88,    86,     0,
      87,     0,     0,     0,     0,     0,     0,    28,    34,    15,
       0,   151,    67,    73,    74,     0,    85,     0,     0,     0,
       0,     0,     0,   152,    38,     0,    21,    18,     0,     0,
       0,     0,    20,    22,     0,    23,     0,    25,     0,    19,
      24,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   204,   -59,   191,   118,   -76,   -76,   -76,
     -75,   -56,   -29,    -6,   -76,    96,    95,   110,   116,   119,
     -10,     0,     8,    64,   -48,   -53,   -76,   -76,   129,   -76,
     -76,   -76,   -76,   -28,     1,   -76,   -76,   213,   -76,   -15,
     -76,   230,   -76,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    91,    92,    93,    94,    95,    96,
      97,    98,    99,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,   122,    77,
      78,   154,   100,    14,   102,    16,    24,    25,    79,    42,
     106,    27,   107,   221
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    15,   121,   110,   111,    61,   103,   101,    31,    20,
     168,    17,   130,    15,   124,    39,   175,    28,    34,   175,
      18,   163,   156,    35,   225,   226,    37,   155,    32,    33,
      38,   140,   141,   142,   173,   181,    40,   182,   105,   108,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      20,   136,   137,   121,   131,    20,    21,   126,   175,    20,
     183,    21,   138,   139,   104,    21,    23,    34,   125,   188,
     185,   156,   178,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     179,   214,   203,   204,   205,   123,   157,   158,   159,   132,
     133,   134,   135,   127,   175,   209,   228,    23,   212,   213,
     129,   216,    23,    30,    22,   128,    23,   175,   173,   229,
     193,   194,   160,   174,   175,   206,   161,   175,   169,   232,
     162,   156,   195,   196,   197,   198,   222,   164,   215,   230,
     231,   175,   170,   243,   199,   200,   218,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     1,     2,     3,
       4,     5,     6,     7,     8,     9,    10,   165,   166,   236,
     237,   235,   156,   242,   239,   241,   175,   171,   246,   245,
     153,   247,   220,   180,   175,   249,   248,   250,   167,   251,
      43,    44,    45,    46,    47,    48,    49,    50,   184,    51,
      52,    53,   201,   202,   207,   233,   208,    54,    55,   210,
     211,   217,   223,   224,   227,   244,    19,    36,   177,   234,
     187,   189,    56,    57,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    80,    81,    82,   190,    83,    84,
      85,    86,    87,    88,   191,    89,    41,    58,   192,    35,
      90,    29,   186,     0,     0,     0,    59,    60,    43,    44,
      45,    46,    47,    48,    49,    50,     0,    51,    52,    53,
       0,     0,     0,     0,     0,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    80,    81,    82,     0,    83,    84,    85,    86,
      87,    88,     0,    89,     0,    58,     0,    35,   176,     0,
       0,     0,     0,     0,    59,    60,    43,    44,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,     0,     0,
       0,     0,     0,    54,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,    81,    82,     0,    83,    84,    85,    86,    87,    88,
       0,    89,     0,    58,     0,    35,   172,     0,     0,     0,
       0,     0,    59,    60,    43,    44,    45,    46,    47,    48,
      49,    50,     0,    51,    52,    53,     0,     0,     0,     0,
       0,    54,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,     0,    83,    84,    85,    86,    87,    88,     0,    89,
       0,    58,     0,    35,   219,     0,     0,     0,     0,     0,
      59,    60,    43,    44,    45,    46,    47,    48,    49,    50,
       0,    51,    52,    53,     0,     0,     0,     0,     0,    54,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,    81,    82,     0,
      83,    84,    85,    86,    87,    88,     0,    89,     0,    58,
       0,    35,     0,     0,     0,     0,     0,     0,    59,    60,
      43,    44,    45,    46,    47,    48,    49,    50,     0,    51,
      52,    53,     0,     0,     0,     0,     0,    54,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,    57,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,    59,    60,    43,    44,
      45,    46,    47,    48,    49,    50,     0,    51,    52,    53,
       0,     0,     0,     0,     0,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    43,    44,    45,    46,    47,    48,    49,    50,     0,
      51,    52,    53,     0,     0,    58,     0,     0,    54,    55,
       0,     0,     0,     0,    59,    60,     0,     0,     0,     0,
       0,     0,     0,    56,    57,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    43,    44,    45,    46,    47,    48,
      49,    50,     0,    51,    52,    53,     0,     0,   109,     0,
       0,    54,    55,     0,     0,     0,     0,    59,    60,     0,
       0,     0,     0,     0,     0,     0,    56,    57,     0,     0,
      43,    44,    45,    46,    47,    48,    49,    50,     0,    51,
      52,    53,     0,     0,     0,     0,     0,    54,    55,    89,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
      59,    60,    56,    57,     0,     0,    43,    44,    45,    46,
      47,    48,    49,    50,     0,    51,    52,    53,     0,     0,
       0,     0,     0,    54,    55,     0,     0,    58,   238,     0,
       0,     0,     0,     0,     0,     0,    59,    60,    56,    57,
       0,     0,    43,    44,    45,    46,    47,    48,    49,    50,
       0,    51,    52,    53,     0,     0,     0,     0,     0,    54,
      55,     0,     0,    58,   240,     0,     0,     0,     0,     0,
       0,     0,    59,    60,    56,    57,     0,     0,    43,    44,
      45,    46,    47,    48,    49,    50,     0,    51,    52,    53,
       0,     0,     0,     0,     0,    54,    55,     0,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,    59,    60,
      56,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    60
};

static const yytype_int16 yycheck[] =
{
      15,     0,    58,    56,    57,    34,     3,    35,    23,     3,
      85,    10,    15,    12,    12,    30,    59,    16,    57,    59,
       0,    80,    75,    62,    67,    65,    60,    75,    58,    59,
      64,     9,    10,    11,    93,    59,    61,    61,    37,    65,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       3,    22,    23,   109,    57,     3,     9,    13,    59,     3,
      61,     9,     7,     8,    61,     9,    60,    57,    66,   125,
     123,   124,   100,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     105,   166,   140,   141,   142,    60,    34,    35,    36,    16,
      17,    18,    19,    14,    59,   161,    61,    60,   164,   165,
      20,   167,    60,    61,    58,    21,    60,    59,   177,    61,
     130,   131,    60,    58,    59,   154,    64,    59,    58,    61,
      68,   184,   132,   133,   134,   135,   184,    60,   166,   214,
     215,    59,    58,    61,   136,   137,   175,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    60,    60,   228,
     229,   227,   225,   232,   230,   231,    59,     3,    61,   238,
      57,   240,   181,    61,    59,   244,    61,   246,    60,   248,
       3,     4,     5,     6,     7,     8,     9,    10,    61,    12,
      13,    14,   138,   139,     3,   220,    61,    20,    21,     3,
      48,    58,    61,    61,    60,    50,    12,    26,   100,   225,
     124,   126,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,   127,    51,    52,
      53,    54,    55,    56,   128,    58,    33,    60,   129,    62,
      63,    21,   123,    -1,    -1,    -1,    69,    70,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    51,    52,    53,    54,
      55,    56,    -1,    58,    -1,    60,    -1,    62,    63,    -1,
      -1,    -1,    -1,    -1,    69,    70,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    -1,    51,    52,    53,    54,    55,    56,
      -1,    58,    -1,    60,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    69,    70,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    -1,    58,
      -1,    60,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      69,    70,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    -1,    58,    -1,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    14,    -1,    -1,    60,    -1,    -1,    20,    21,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    -1,    60,    -1,
      -1,    20,    21,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    20,    21,    58,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    70,    35,    36,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    20,    21,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    35,    36,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    20,
      21,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    35,    36,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    72,    73,    74,   104,   105,   106,   105,     0,    74,
       3,     9,    58,    60,   107,   108,   110,   112,   105,   112,
      61,   110,    58,    59,    57,    62,    76,    60,    64,   110,
      61,   108,   110,     3,     4,     5,     6,     7,     8,     9,
      10,    12,    13,    14,    20,    21,    35,    36,    60,    69,
      70,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,   100,   101,   109,
      47,    48,    49,    51,    52,    53,    54,    55,    56,    58,
      63,    75,    76,    77,    78,    79,    80,    81,    82,    83,
     103,   104,   105,     3,    61,   105,   111,   113,    65,    60,
      96,    96,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    82,    99,    60,    12,    66,    13,    14,    21,    20,
      15,    57,    16,    17,    18,    19,    22,    23,     7,     8,
       9,    10,    11,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    57,   102,    95,    96,    34,    35,    36,
      60,    64,    68,    75,    60,    60,    60,    60,    81,    58,
      58,     3,    63,    75,    58,    59,    63,    77,   104,   110,
      61,    59,    61,    61,    61,    96,    99,    86,    82,    87,
      88,    89,    90,    91,    91,    92,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    95,    83,     3,    61,    82,
       3,    48,    82,    82,    81,   104,    82,    58,    83,    63,
     105,   114,    95,    61,    61,    67,    65,    60,    61,    61,
      81,    81,    61,   110,    84,    82,    75,    75,    61,    82,
      61,    82,    75,    61,    50,    75,    61,    75,    61,    75,
      75,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    75,    75,    75,
      75,    75,    76,    76,    76,    76,    77,    77,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      80,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    90,    91,    91,    91,    91,    91,    92,    92,    92,
      93,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   100,   101,   101,   101,   101,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   103,   103,
     104,   104,   105,   105,   105,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   107,   107,   108,   108,   109,
     110,   110,   111,   112,   112,   112,   112,   112,   112,   112,
     113,   113,   114
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     2,     3,     3,     4,     1,     2,     5,     7,
       5,     5,     6,     6,     7,     6,     7,     2,     3,     2,
       2,     1,     2,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     4,     1,     1,
       2,     2,     2,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     3,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     2,     1,     3,     1,     3,     3,     3,     4,     4,
       2,     3,     2
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
#line 1632 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 76 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new TranslationUnit( {(yyvsp[0].node)} ); }
#line 1638 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 77 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node)->add((yyvsp[0].node));}
#line 1644 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].decl);}
#line 1650 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 83 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Function((yyvsp[-2].type), (yyvsp[-1].node), (yyvsp[0].stat));}
#line 1656 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 94 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = (yyvsp[0].stat);}
#line 1662 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 95 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = (yyvsp[0].stat);}
#line 1668 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 96 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = (yyvsp[0].stat);}
#line 1674 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 97 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = (yyvsp[0].stat);}
#line 1680 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 99 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = (yyvsp[0].exprstat);}
#line 1686 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 102 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new CompoundStatement();}
#line 1692 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 103 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new CompoundStatement( (yyvsp[-1].list), new List({}) ); }
#line 1698 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 104 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new CompoundStatement( new List({}), (yyvsp[-1].list)); }
#line 1704 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 105 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new CompoundStatement( (yyvsp[-2].list), (yyvsp[-1].list) ); }
#line 1710 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 108 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) = new List({(yyvsp[0].stat)}); }
#line 1716 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 109 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) -> add((yyvsp[0].stat)); }
#line 1722 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 112 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new IfElseStatement((yyvsp[-2].expr), (yyvsp[0].stat), new CompoundStatement());}
#line 1728 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 113 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new IfElseStatement((yyvsp[-4].expr), (yyvsp[-2].stat), (yyvsp[0].stat));}
#line 1734 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 114 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new SwitchStatement((yyvsp[-2].expr), (yyvsp[0].stat)); }
#line 1740 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 117 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new WhileStatement((yyvsp[-2].expr), (yyvsp[0].stat));}
#line 1746 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 118 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new DoWhileStatement((yyvsp[-1].expr), (yyvsp[-4].stat));}
#line 1752 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 119 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new ExprExprFor((yyvsp[-3].exprstat), (yyvsp[-2].exprstat), (yyvsp[0].stat));}
#line 1758 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new ExprExprExprFor((yyvsp[-4].exprstat), (yyvsp[-3].exprstat), (yyvsp[-2].expr), (yyvsp[0].stat));}
#line 1764 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 121 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new DecExprFor((yyvsp[-3].decl), (yyvsp[-2].exprstat), (yyvsp[0].stat));}
#line 1770 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 122 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new DecExprExprFor((yyvsp[-4].decl),(yyvsp[-3].exprstat),(yyvsp[-2].expr),(yyvsp[0].stat));}
#line 1776 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 125 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new ReturnStatement((yyvsp[0].exprstat));}
#line 1782 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 126 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new GotoStatement(*(yyvsp[-1].str));}
#line 1788 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 127 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new ContinueStatement();}
#line 1794 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 128 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stat) = new BreakStatement();}
#line 1800 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 134 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprstat) = new ExprStatement(new Expression_Null());}
#line 1806 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 135 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprstat) = new ExprStatement((yyvsp[-1].expr));}
#line 1812 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 138 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1818 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 139 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) -> add((yyvsp[0].expr)); }
#line 1824 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 142 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1830 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 143 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new AssignmentExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1836 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 147 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1842 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 148 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new TernaryExpression((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1848 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 151 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1854 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 152 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1860 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 156 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1866 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 157 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1872 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 161 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1878 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 162 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1884 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 165 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1890 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 166 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1896 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 169 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1902 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 170 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1908 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 173 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1914 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 174 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1920 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 175 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1926 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 178 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1932 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 179 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1938 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 180 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1944 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 181 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1950 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1956 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 185 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1962 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 186 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1968 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 187 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1974 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 190 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1980 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 191 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1986 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 192 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 1992 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 195 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 1998 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2004 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 197 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2010 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new BinaryExpression((yyvsp[-2].expr), (yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2016 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 201 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CastExpr((yyvsp[0].expr), (yyvsp[-2].str)); }
#line 2022 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 202 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2028 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 206 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2034 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 207 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PrefixExpr((yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2040 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 208 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PrefixExpr((yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2046 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 209 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PrefixExpr((yyvsp[0].expr), (yyvsp[-1].str)); }
#line 2052 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 210 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PrefixExpr((yyvsp[-1].expr), (yyvsp[-3].str)); }
#line 2058 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PrefixExpr((yyvsp[-1].str), (yyvsp[-3].str)); }
#line 2064 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 226 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expr) = (yyvsp[0].expr);}
#line 2070 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 227 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new SquareOperator((yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2076 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 228 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FunctionCall((yyvsp[-2].expr)); }
#line 2082 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 230 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new DotOperator((yyvsp[-2].expr), (yyvsp[0].str)); }
#line 2088 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 231 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new ArrowOperator((yyvsp[-2].expr), (yyvsp[0].str)); }
#line 2094 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 232 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixExpr((yyvsp[-1].expr), (yyvsp[0].str)); }
#line 2100 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 233 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new PostfixExpr((yyvsp[-1].expr), (yyvsp[0].str)); }
#line 2106 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 247 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr);}
#line 2112 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 248 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new StringLiteral(*(yyvsp[0].str));}
#line 2118 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 249 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr);}
#line 2124 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 252 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new Variable((yyvsp[0].str));}
#line 2130 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 253 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new IntConstant(*(yyvsp[0].str));}
#line 2136 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 254 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new FloatConstant(*(yyvsp[0].str));}
#line 2142 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 255 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new CharConstant(*(yyvsp[0].str)); }
#line 2148 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 258 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2154 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 259 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2160 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 260 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2166 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 261 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2172 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 262 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2178 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 263 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2184 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 264 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2190 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 265 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2196 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 266 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2202 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 267 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2208 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 268 "src/parser.y" /* yacc.c:1646  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2214 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 274 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) = new DeclarationList({(yyvsp[0].decl)});}
#line 2220 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 275 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) -> add((yyvsp[0].decl)); }
#line 2226 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 278 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl) = new Declaration((yyvsp[-1].type),( new List({}) ) ); }
#line 2232 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 279 "src/parser.y" /* yacc.c:1646  */
    { (yyval.decl) = new Declaration((yyvsp[-2].type), (yyvsp[-1].list)); }
#line 2238 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 282 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[0].type) ; }
#line 2244 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 283 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Const) ; }
#line 2250 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 284 "src/parser.y" /* yacc.c:1646  */
    { (yyvsp[0].type)->add((yyvsp[-1].type)); (yyval.type) = (yyvsp[0].type); delete (yyvsp[-1].type); }
#line 2256 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 285 "src/parser.y" /* yacc.c:1646  */
    { (yyvsp[0].type)->add(new Type(Const) ); (yyval.type) = (yyvsp[0].type); delete (yyvsp[-1].type); }
#line 2262 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 288 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Void);}
#line 2268 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 289 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Char);}
#line 2274 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 290 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Int);}
#line 2280 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 291 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Short);}
#line 2286 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 292 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Long);}
#line 2292 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 293 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Float);}
#line 2298 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 294 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(Double);}
#line 2304 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 295 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(1);}
#line 2310 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 296 "src/parser.y" /* yacc.c:1646  */
    { (yyval.type) = new Type(0);}
#line 2316 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 299 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) = new DeclarationList({(yyvsp[0].node)}); }
#line 2322 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 300 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) -> add((yyvsp[0].node)); }
#line 2328 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 303 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2334 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 304 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new InitDeclarator((yyvsp[-2].node),(yyvsp[0].expr)); if ((yyvsp[-2].node)->getPtr()){(yyval.node)->setPtr();} }
#line 2340 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 307 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2346 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 310 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2352 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 311 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); ((const Declarator *)(yyval.node)) -> setPtr();}
#line 2358 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 314 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) = new List({new Variable((yyvsp[0].str))}); }
#line 2364 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 317 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2370 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 318 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Variable((yyvsp[0].str));}
#line 2376 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 319 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2382 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 320 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ArrayDeclarator((yyvsp[-2].node), new Constant("-1")); }
#line 2388 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 321 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionDeclarator((yyvsp[-2].node),( new List({}) ) ); }
#line 2394 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 322 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionDeclarator((yyvsp[-3].node), (yyvsp[-1].list)); }
#line 2400 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 323 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new FunctionDeclarator((yyvsp[-3].node), (yyvsp[-1].list)); }
#line 2406 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 326 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) = new ParameterList({ new Declaration((yyvsp[-1].type), new DeclarationList({ (yyvsp[0].node) }) ) }); }
#line 2412 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 328 "src/parser.y" /* yacc.c:1646  */
    { (yyval.list) -> add((yyvsp[0].node)); }
#line 2418 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 331 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Declaration((yyvsp[-1].type), new DeclarationList({(yyvsp[0].node)}) ); }
#line 2424 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2428 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 336 "src/parser.y" /* yacc.c:1906  */


const baseNode *g_root; 

const baseNode *parseAST()
{
	g_root=0;
	yyparse();
	return g_root;
}
