%option noyywrap

%{
	#include "parser.tab.hpp"
	#include <string>
	#include <cstdlib>
	void col_inc();
	void store(char * yytext);

	// extern "C" int fileno(FILE *stream);
	void yy_colCount();
%}

digit       [0-9]
letter		[a-zA-Z]
word        [a-zA-Z]+
alphanum	[a-zA-Z0-9]+


%%

void 						{ return (VOID);	}
char 						{ return (CHAR);	}
short 				      	{ return (SHORT); }
int 						{ return (INT); }
long 						{ return (LONG); }
float 				      	{ return (FLOAT); }
double 				     	{ return (DOUBLE); }
signed				      	{ return (SIGNED); }
unsigned					{ return (UNSIGNED); }

do                          { return (DO); }
while                       { return (WHILE); }
if                          { return (IF); }
else                        { return (ELSE); }
for                         { return (FOR); }
switch						{ return (SWITCH); }

return					    { return (RETURN); }
continue                    { return (CONTINUE); }
break                       { return (BREAK); }
goto					    { return (GOTO);	}

string 						{ return (STRING); }
sizeof 						{ return (SIZEOF); }


"="							{ return (EQUAL); }
"("							{ return (L_BRAC); }
")"							{ return (R_BRAC); }
"{"							{ return (L_CURLY); }
"}"							{ return (R_CURLY); }
"["                         { return (L_SQUARE); }
"["                         { return (R_SQUARE); }
";"							{ return (SEMICOLON); }
":"                         { return (COLON); }
","							{ return (COMMA); }

"*"                         { return (TIMES); }
"+"                         { return (PLUS); }
"\^"                        { return (XOR); }
"-"                         { return (MINUS); }
"/"                         { return (DIVIDE); }
"?"							{ return (QUES_MARK); }
":"							{ return (COLON); }
"."							{ return (DOT); }

"||"  						{ return LOR; }
"&&"  						{ return LAND; }
"<="  						{ return LESSEQUAL; }
">="  						{ return GREATEQUAL; }
"!="  						{ return NEQUAL; }
">"   						{ return GREATTHAN; }
"<"   						{ return LESSTHAN; }

"->"  						{ return ARROW; }
"++"  						{ return INCR; }
"--"  						{ return DECR; }
">>=" 						{ return RR_ASS; }
"<<=" 						{ return LL_ASS; }
"+="  						{ return ADD_ASS; }
"-="  						{ return SUB_ASS; }
"*="  						{ return MUL_ASS; }
"/="  						{ return DIV_ASS; }
"%="  						{ return MOD_ASS; }
"&="  						{ return AND_ASS; }
"^="  						{ return XOR_ASS; }
"|="  						{ return OR_ASS; }

{letter}{alphanum}*        	{ return (IDENTIFIER); }

%%

int col = 0;

void yy_colCount(){
  for (int i = 0; yytexti != '\0'; i++)
		if (yytexti == '\n')
			col = 0;
		else if (yytexti == '\t)
			col += 8 - (col % 8);
		else
			col++;
	ECHO;
}


void col_inc(){
  yylcolno += len;
}

void store(char * yytext){
  yylval.raw = new std::string(yytext);
  len = yyleng;
}

void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}
