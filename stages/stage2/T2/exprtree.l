%{
	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>
%}

%%

[a-z]	{yylval = makeLeafID(*yytext);return ID;}
[0-9]+	{yylval = makeLeafNum(atoi(yytext)); return NUM;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"="	{return EQ;}
";"	{return *yytext;}
"read"	{return READ;}
"write"	{return WRITE;}
"begin"	{return BEG;}
"end"	{return END;}
[()]	{return *yytext;}
[ \t]	{}
[\n]	{}
.	{printf("unknown character:%c\n",*yytext);exit(1);}

%%

int yywrap(void) {
	return 1;
}

