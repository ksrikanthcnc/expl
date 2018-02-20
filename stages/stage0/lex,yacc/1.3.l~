%option noyywrap

%{
  #include<stdlib.h>
  #include<stdio.h>
%}

%%

[A][a-zA-Z][a-zA-Z][ |\n|\t] {printf("\n\t\t\t%s\n",yytext);}
. {printf("%s",yytext);}

%%

int main(){
	yyin=fopen("file1","r");
	yylex();
	return 1;
}
