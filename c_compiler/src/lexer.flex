%option noyywrap

%{
	#include "parser.tab.hpp"
	#include <string>
	#include <cstdlib>

	
	// extern "C" int fileno(FILE *stream);
	//void yy_colCount();
%}

digit       [0-9]
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

return					    { return (RETURN); }
continue                    { return (CONTINUE); }
break                       { return (BREAK); }
goto					    { return (GOTO);	}

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




%%
/*
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
*/


void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}
