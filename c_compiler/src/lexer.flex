%option noyywrap

%{
// Avoid error 'error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
#include <string.h>

void yy_colCount();
%}

digit       [09
word        [a-zAZ+


%%




void 						{ yylval.string=new std::string("void"); 		return VOID; 	}
char 						{ yylval.string=new std::string("char"); 		return CHAR; 	}
short 				      	{ yylval.string=new std::string("short"); 		return SHORT; 	}
int 						{ yylval.string=new std::string("int"); 		return INT; 	}
long 						{ yylval.string=new std::string("long"); 		return LONG; 	}
float 				      	{ yylval.string=new std::string("float"); 		return FLOAT; 	}
double 				     	{ yylval.string=new std::string("double"); 		return DOUBLE; 	}
signed				      	{ yylval.string=new std::string("signed"); 		return SIGNED; 	}
unsigned					{ yylval.string=new std::string("unsigned"); 	return UNSIGNED;}



do                          { yylval.string=new std::string("do"); 		   return DO; 	}
while                       { yylval.string=new std::string("while"); 		return WHILE; 	}
if                          { yylval.string=new std::string("if"); 		   return IF; 	}
else                        { yylval.string=new std::string("else"); 		return ELSE; 	}
for                         { yylval.string=new std::string("for"); 		return FOR; 	}

return					    { yylval.string=new std::string("return"); 		return RETURN;	}
continue                    { yylval.string=new std::string("continue"); 		return CONTINUE; 	}
break                       { yylval.string=new std::string("break"); 		return BREAK; 	}
goto					    { yylval.string=new std::string("goto"); 		return GOTO;	}

"="							{ return EQUAL	; }
"("							{ return L_BRAC ; }
")"							{ return R_BRAC ; }
"{"							{ return L_CURLY; }
"}"							{ return R_CURLY; }
"["                         { return L_SQUARE; }
"["                         { return R_SQUARE; }
";"							{ return SEMICOLON; }
":"                         { return COLON; }
","							{ return COMMA 	; }

"*"                         { return TIMES; }
"+"                         { return PLUS; }
"\^"                        { return XOR; }
"-"                         { return MINUS; }
"/"                         { return DIVIDE; }




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
