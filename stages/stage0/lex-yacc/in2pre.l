%{
    #include <stdio.h> 
	  #include "y.tab.h"
%}

%%

[0-9a-zA-Z]+	{
		yylval=strdup(yytext);
		printf("%s",yytext);
		return CHAR;
		}
"+"	  {		printf("%s",yytext);
			return *yytext;}
"-"	  {		printf("%s",yytext);
			return *yytext;}
"*"	  {		printf("%s",yytext);
			return *yytext;}
"/"	  {		printf("%s",yytext);
			return *yytext;}
[()]	  {		printf("%s",yytext);
			return *yytext;}
[\n]	  {		printf("%s",yytext);
			return NEWLINE;}

%%

yywrap()
{
	return 1;
}
