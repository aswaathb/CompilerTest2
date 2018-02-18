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

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
