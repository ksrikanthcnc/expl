%{
	#include <stdio.h>
	#include <stdlib.h>
%}

%token num IF ELSE
%left ';'
%left '+' '-'
%left '*' '/'

%%

start	:	st				{exit(1);}
		;

st		:	IF '(' expr ')' st	ELSE st		{printf("IF()ELSE\n");}
		|	expr							{printf("expr\n");}
		;

expr	:	expr '+' expr	{printf("+");}
		|	expr '-' expr	{printf("-");}
		|	expr '*' expr	{printf("*");}
		|	expr '/' expr	{printf("/");}
		|	num				{printf("%d ",$1);}
		;


%%

yyerror(char const *s)
{
    printf("\nyyerror %s\n",s);
}

yylex(){
    char c;
    c=getchar();
    printf("%c",c);
	if(c=='i')
		return IF;
	else if(c=='e')
		return ELSE;
    else if(c==' '||c=='\n')
        yylex();         /*This is to ignore whitespaces in the input*/
	else if(1)
        return num;
	else
		puts("here");
}


int main()
{
	yyparse();
	return 1;
}
