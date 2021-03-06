%{
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE tnode *
	#include "exprtree.h"
	#include "exprtree.c"
	#include "lex.yy.c"
	int yylex(void);

%}

%token NUM PLUS END
%left PLUS 

%%

start : expr END	{return $1;}
		;

expr : expr PLUS expr		{$$ = makeOperatorNode('+',$1,$3);}
	 | '(' expr ')'		{$$ = $2;}
	 | NUM			{$$ = $1;}
	 ;

%%

yyerror(char const *s)
{
    printf("\nyyerror %s",s);
    exit(0);
}

