
%{
  #include <stdio.h>
  
  int yyerror();
  yydebug=0;
%}

%token DIGIT

%%

start : pair 		{printf("\nComplete"); exit(1); }
	;

pair: num ',' num	{ printf("pair(%d,%d)",$1,$3); }
  ;
num: DIGIT			{ $$=$1; }
  ;

%%

int yyerror()
{
	printf("Error");
}

int main()
{
	yyparse();
	return 1;
}
