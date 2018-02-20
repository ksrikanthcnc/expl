%option noyywrap

%{
  #include<stdlib.h>
  #include<stdio.h>
  int integers,floats;
%}

number  [0-9]+
float [0-9]*[.][0-9]+

%%

{number} {integers++;printf("INT:%d->%s\n",integers,yytext);}
{float}	{floats++;printf("\tFLO:%d->%s\n",floats,yytext);}
.	{;}

%%

int main(){
	integers=0;
	floats=0;
	yyin=fopen("file1","r");
	yylex();
	printf("integers=%d\n",integers);
	printf("floats=%d\n",floats);
}
