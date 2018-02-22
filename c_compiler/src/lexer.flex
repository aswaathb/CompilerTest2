%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}

DIGIT           [0-9]
LETTER          [a-zA-Z_]
HEXDIG          [a-fA-F0-9]


%%

int             { return T_INT; }
return          { return T_RETURN; }

[*]             { return T_TIMES; }
[+]             { return T_PLUS; }
[\^]            { return T_EXPONENT; }
[-]             { return T_MINUS; }
[/]             { return T_DIVIDE; }


[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
[{}             { return T_CLBRACKET; }
[}]             { return T_CRBRACKET; }
[[]             { return T_SLBRACKET; }
[]]             { return T_SRBRACKET; }

log             { return T_LOG; }
exp             { return T_EXP; }
sqrt            { return T_SQRT; }

[-]?[0-9]+([\.][0-9]*)? { yylval.number=strtod(yytext, 0); return T_NUMBER; }
[_|{LETTER}][]          { yylval.string=new std::string(yytext); return T_VARIABLE; }


[ \t\r\n]+		{;}
.               { fprintf(stderr, "Invalid token\n"); exit(1); }

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
