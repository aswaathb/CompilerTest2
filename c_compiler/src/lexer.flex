%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

//#include necessary header files here
%}

%%

char_low  [a-z]
char_high [A-Z]
digit   [0-9]

identifier [a-zA-Z]\w*


%%

[(]             { return T_BRA_L; }
[)]             { return T_BRA_R; }
[{]             { return T_CURLYBRA_L; }
[}]             { return T_CURLYBRA_R; }
[[]             { return T_SQBRA_L; }
[]]             { return T_SQBRA_R; }

[,]				{ return T_COMMA; }
[.]				{ return T_PERIOD; }
[;]				{ return T_SEMICOLON; }

//types
int             { return T_INT; }

return          { return T_RETURN; }

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
