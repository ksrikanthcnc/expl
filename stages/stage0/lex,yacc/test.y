%{

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int yydebug=0;
int ifs=0;
int t=0;
%}

%token DIGIT IF ELSE CHAR
%nonassoc '=' '#' 
%left '+' '-'
%left '*' '/'

%%

start : st '\n'		{printf("\nSyntax matched\n");exit(1);}
      ;

expr: expr '+' expr     {printf("%d+%d\n",$1,$3);}
    | expr '*' expr     {printf("%d*%d\n",$1,$3);}
    | expr '-' expr     {printf("%d-%d\n",$1,$3);}
    | expr '/' expr     {printf("%d/%d\n",$1,$3);}
    | expr '=' expr     {t=ifs;while(t!=0){t--;printf("\t");}printf("CONDITION ");printf("%d==%d\n",$1,$3);}
	| '(' expr ')'
    | DIGIT             
    | CHAR 				
    ;

st	: IF {t=ifs;while(t!=0){t--;printf("\t");}puts("IF");}'('expr')' '('st')' ELSE {t=ifs;while(t!=0){t--;printf("\t");}puts("ELSE");} '('st')' ';' {t=ifs;while(t!=0){t--;printf("\t");}puts("\t---if ended--");}	
	| CHAR {t=ifs;while(t!=0){t--;printf("\t");}printf("%c=",$1);} '#' expr		
	;

%%
/*
i(4=5) (a#2+2) e (i(4=5) (i(3=2) (s#5+6) e (a#2+3);) e (q#5+7););

*/
yyerror(char const *s)
{
    printf("yyerror %s\n",s);
}

yylex(){
    char c;
    c = getchar();
    if(isdigit(c)){
//printf("~%c\n",c);
        yylval = c - '0';
        return DIGIT;
    }
    else if(c == 'i'){
//puts("~i");
		ifs++;
    	return IF;
    }
    else if(c == 'e'){
//puts("~e");
    	return ELSE;
    }
    else if(c == ' '){
//puts("~ ");
        yylex();         /*This is to ignore whitespaces in the input*/
    }
    else if(isalpha(c)){
//printf("~%c\n",c);		
			yylval = c;
			return CHAR;
	}
	else{
//printf("~%c\n",c);
		if(c==';')
			ifs--;
		yylval = c;
        return c;
    }
}

int main()
{	
	yyparse();
	return 1;
}

