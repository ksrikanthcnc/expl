%{
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE tnode *
	#include "exprtree.h"
	#include "exprtree.c"
	int yylex(void);
	yydebug=0;
%}

%token NUM PLUS MINUS MUL DIV EQ BEG END READ WRITE ID ';'
%left PLUS MINUS
%left MUL DIV EQ

%%

start	:BEG Slist END ';'	{return $2;}
		|BEG END	';'		{return NULL;}
		;

Slist	:Slist Stmt		{$$= createTree($2,$1);}
		|Stmt 			{$$= $1;}
		;

Stmt	:InputStmt 		{$$=$1;}
		|OutputStmt 	{$$=$1;}
		|AsgStmt 		{$$=$1;}
		;
		
InputStmt	:READ '(' ID ')' ';'	{$$ = makeFunc("read",$3);}
			;

OutputStmt	:WRITE '(' E ')' ';'	{$$ = makeFunc("write",$3);}
			;
			
AsgStmt		:ID EQ E ';'	{$$ = makeOperatorNode('=',$1,$3);}
			;

E	:E PLUS E 	{$$ = makeOperatorNode('+',$1,$3);}
	|E MINUS E  {$$ = makeOperatorNode('-',$1,$3);}
	|E MUL E 	{$$ = makeOperatorNode('*',$1,$3);}
	|E DIV E 	{$$ = makeOperatorNode('/',$1,$3);}
	|'(' E ')'	{$$ = $2;}
	|ID			{$$ = $1;}
	|NUM		{$$ = $1;}
	;

%%

yyerror(char const *s)
{
	printf("yyerror %s\n",s);
	exit(0);
}

int main(void) {
	yyparse();
	return 0;
}
