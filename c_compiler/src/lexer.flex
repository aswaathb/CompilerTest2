%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
void yy_colCount();
%}

LETTER    [a-zA-Z_]
ALP_NUM   [a-zA-Z0-9_]
DIGIT     [0-9]
DEC       {DIGIT}*(\.){DIGIT}+
HEX       0[xX][a-fA-F0-9]+
OCT       0[1-7]+
NUM       [1-9]
FLOAT     (({DEC})([eE][+-]?{DIGIT}+)?)|{NUM}+[eE][+-]?{DIGIT}+
SYNTAX    ">>="|"<<="|"+="|"-="|"*="|"/="|"%="|"&="|"^="|"|="|">>"|"<<"|"++"|"--"|"->"|"&&"|"||"|"<="|">="|"=="|"..."|";"|"{"|"}"|","|":"|"("|")"|"["|"]"|"."|"="|"&"|"!"|"~"|"-"|"+"|"*"|"/"|"%"|"<"|">"|"^"|"|"|"?"
//F_SUFFIX  f|F|l|L
//UN_SUFFIX	u|U|l|L

%%
///////////////////////////////////////////// Comments ////////////////////////////////////////////////////
"/*"			                              { comment()?; }
"//"                                    { comment()?; }
////////////////////////////////////////// Variable Types /////////////////////////////////////////////////
auto                                      { yy_colCount(); /* other functions */ ; return AUTO; }
double                                    { yy_colCount(); /* other functions */ ; return DOUBLE; }
float    		                          { yy_colCount(); /* other functions */ ; return FLOAT; }
char            	                      { yy_colCount(); /* other functions */ ; return CHAR; }
int                 	                  { yy_colCount(); /* other functions */ ; return INT; }
unsigned                	              { yy_colCount(); /* other functions */ ; return UNSIGNED; }
signed                      	          { yy_colCount(); /* other functions */ ; return SIGNED; }
long									  { yy_colCount(); /* other functions */ ; return LONG; }
short									  { yy_colCount(); /* other functions */ ; return SHORT; }
									  
////////////////////////////////////////// Function Types /////////////////////////////////////////////////
for                             	      { yy_colCount(); /* other functions */ ; return FOR; }
if                                  	  { yy_colCount(); /* other functions */ ; return IF; }
switch                                    { yy_colCount(); /* other functions */ ; return SWITCH; }
case  		                              { yy_colCount(); /* other functions */ ; return CASE; }
else        	                          { yy_colCount(); /* other functions */ ; return ELSE; }
do              	                      { yy_colCount(); /* other functions */ ; return DO; }
void                	                  { yy_colCount(); /* other functions */ ; return VOID; }
while                   	              { yy_colCount(); /* other functions */ ; return WHILE; }

//////////////////////////////////// Supporting (Constructs?) /////////////////////////////////////////////
break                       	          { yy_colCount(); /* other functions */ ; return BREAK; }
goto                            	      { yy_colCount(); /* other functions */ ; return GOTO; }
const                               	  { yy_colCount(); /* other functions */ ; return CONST; }
default                                   { yy_colCount(); /* other functions */ ; return DEFAULT; }
struct		                              { yy_colCount(); /* other functions */ ; return STRUCT; }
register                                  { yy_colCount(); /* other functions */ ; return REGISTER; }
typedef                                   { yy_colCount(); /* other functions */ ; return TYPEDEF; }
return                                    { yy_colCount(); /* other functions */ ; return RETURN; }
sizeof                                    { yy_colCount(); /* other functions */ ; return SIZEOF; }
static                                    { yy_colCount(); /* other functions */ ; return STATIC; }

/////////////////////////////////////// Constants and Strings /////////////////////////////////////////////
//({HEX}|{OCT}|0){DIGIT}+{UN_SUFFIX}?	    { yy_colCount(); return(CONSTANT); }
//LETTER?'(\\.|[^\\'])+'	                { yy_colCount(); return(CONSTANT); }
//{FLOAT}{F_SUFFIX}?		                { yy_colCount(); return(CONSTANT); }
//{DIGIT}*"."{FLOAT}{F_SUFFIX}?  	        { yy_colCount(); return(CONSTANT); }
//{DIGIT}+"."{FLOAT}{F_SUFFIX}?	            { yy_colCount(); return(CONSTANT); }
LETTER?\"(\\.|[^\\"])*\"	              { yy_colCount(); return(STRING_LITERAL); }

///////////////////////////////////////////// Operations //////////////////////////////////////////////////
">>="		    	                      { yy_colCount(); return(RIGHT_AGN); }
"<<="			                          { yy_colCount(); return(LEFT_AGN); }
"+="			                          { yy_colCount(); return(ADD_AGN); }
"-="			                          { yy_colCount(); return(SUB_AGN); }
"*="			                          { yy_colCount(); return(MUL_AGN); }
"/="			                          { yy_colCount(); return(DIV_AGN); }
"%="			                          { yy_colCount(); return(MOD_AGN); }
"&="			                          { yy_colCount(); return(AND_AGN); }
"^="			                          { yy_colCount(); return(XOR_AGN); }
"|="			                          { yy_colCount(); return(OR_AGN); }
">>"			                          { yy_colCount(); return(RIGHT_OPR); }
"<<"			                          { yy_colCount(); return(LEFT_OPR); }
"++"			                          { yy_colCount(); return(INC_OPR); }
"--"			                          { yy_colCount(); return(DEC_OPR); }
"->"			                          { yy_colCount(); return(PTR_OPR); }
"&&"			                          { yy_colCount(); return(AND_OPR); }
"||"			                          { yy_colCount(); return(OR_OPR); }
"<="			                          { yy_colCount(); return(LE_OPR); }
">="			                          { yy_colCount(); return(GE_OPR); }
"=="			                          { yy_colCount(); return(EQ_OPR); }
"!="			                          { yy_colCount(); return(NE_OPR); }
"..."			                          { yy_colCount(); return(ELLIPSIS); }
";"		  	                              { yy_colCount(); return(';'); }
"{"   		                              { yy_colCount(); return('{'); }
"}" 		                              { yy_colCount(); return('}'); }
","	  		                              { yy_colCount(); return(','); }
":"	  		                              { yy_colCount(); return(':'); }
"("	  		                              { yy_colCount(); return('('); }
")"	  		                              { yy_colCount(); return(')'); }
"["		                                  { yy_colCount(); return('['); }
"]"		                                  { yy_colCount(); return(']'); }
"." 			                          { yy_colCount(); return('.'); }
"="	  		                              { yy_colCount(); return('='); }
"&"		  	                              { yy_colCount(); return('&'); }
"!"	  		                              { yy_colCount(); return('!'); }
"~"	  		                              { yy_colCount(); return('~'); }
"-"	  		                              { yy_colCount(); return('-'); }
"+"	  		                              { yy_colCount(); return('+'); }
"*"	  		                              { yy_colCount(); return('*'); }
"/"	  		                              { yy_colCount(); return('/'); }
"%"	  		                              { yy_colCount(); return('%'); }
"<"	  		                              { yy_colCount(); return('<'); }
">"	  		                              { yy_colCount(); return('>'); }
"^"	  		                              { yy_colCount(); return('^'); }
"|"		  	                              { yy_colCount(); return('|'); }
"?"		  	                              { yy_colCount(); return('?'); }

////////////////////////////////////////// Clean up ///////////////////////////////////////////////////////
[ \t\v\n\f]		                          { yy_colCount(); }
.			                              { return("INVALID"); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////
%%

int col = 0;

void yy_colCount(){
  for (int i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			col = 0;
		else if (yytext[i] == '\t')
			col += 8 - (col % 8);
		else
			col++;
	ECHO;
}

void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}