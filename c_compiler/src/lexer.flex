%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}

LETTER    [a-zA-Z_]
ALP_NUM   [a-zA-Z0-9_]
DIGIT     [0-9]
DEC       {DIGIT}*(\.){DIGIT}+
HEX       0[xX][a-fA-F0-9]+
OCT       0[1-7]+
NUM       [1-9]
FLOAT     (({DEC})([eE][+-]?{DIGIT}+)?)|{NUM}+[eE][+-]?{DIGIT}+
OPERATOR  "="|"=="|"!="|"+"|"-"|"*"|"/"|">"|"<"|"|"|"&"|"^"|"||"|"&&"|"<="|">="|"->"|"~"|"!"
SYNTAX    "("|")"|"{"|"}"|"["|"]"|";"|","|"."|"<<"|">>"|"\\"
F_SUFFIX  f|F|l|L
UN_SUFFIX	u|U|l|L

%%
///////////////////////////////////////////// Comments ////////////////////////////////////////////////////
"/*"			{ comment(); }
"//"      { comment(); }
////////////////////////////////////////// Variable Types /////////////////////////////////////////////////
auto                                    { count(); /* other functions */ ; return AUTO; }
double                                  { count(); /* other functions */ ; return DOUBLE; }
float                                   { count(); /* other functions */ ; return FLOAT; }
char                                    { count(); /* other functions */ ; return CHAR; }
int                                     { count(); /* other functions */ ; return INT; }
unsigned                                { count(); /* other functions */ ; return UNSIGNED; }
signed                                  { count(); /* other functions */ ; return SIGNED; }
////////////////////////////////////////// Function Types /////////////////////////////////////////////////
for                                     { count(); /* other functions */ ; return FOR; }
if                                      { count(); /* other functions */ ; return IF; }
switch                                  { count(); /* other functions */ ; return SWITCH; }
case                                    { count(); /* other functions */ ; return CASE; }
else                                    { count(); /* other functions */ ; return ELSE; }
do                                      { count(); /* other functions */ ; return DO; }
void                                    { count(); /* other functions */ ; return VOID; }
while                                   { count(); /* other functions */ ; return WHILE; }

//////////////////////////////////// Supporting (Constructs?) /////////////////////////////////////////////
break                                   { count(); /* other functions */ ; return BREAK; }
goto                                    { count(); /* other functions */ ; return GOTO; }
const                                   { count(); /* other functions */ ; return CONST; }
default                                 { count(); /* other functions */ ; return DEFAULT; }
struct                                  { count(); /* other functions */ ; return STRUCT; }
register                                { count(); /* other functions */ ; return REGISTER; }
typedef                                 { count(); /* other functions */ ; return TYPEDEF; }
return                                  { count(); /* other functions */ ; return RETURN; }
sizeof                                  { count(); /* other functions */ ; return SIZEOF; }
static                                  { count(); /* other functions */ ; return STATIC; }

/////////////////////////////////////// Constants and Strings /////////////////////////////////////////////
{LETTER}({LETTER}|{DIGIT})*		          { count(); return(check_type()); }
({HEX}|{OCT}|0){DIGIT}+{UN_SUFFIX}?		  { count(); return(CONSTANT); }
LETTER?'(\\.|[^\\'])+'	                { count(); return(CONSTANT); }
{FLOAT}{F_SUFFIX}?		                  { count(); return(CONSTANT); }
{DIGIT}*"."{FLOAT}{F_SUFFIX}?  	        { count(); return(CONSTANT); }
{DIGIT}+"."{FLOAT}{F_SUFFIX}?	          { count(); return(CONSTANT); }
LETTER?\"(\\.|[^\\"])*\"	              { count(); return(STRING_LITERAL); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}