%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

[a-z]	{yylval = makeLeafID(*yytext);return ID;}
[0-9]+	{yylval = makeLeafNum(atoi(yytext)); return NUM;}
"+"		{return PLUS;}
"-"		{return MINUS;}
"*"		{return MUL;}
"/"		{return DIV;}
"="		{return EQ;}
";"		{return *yytext;}
"<"		{return LT;}
">"		{return GT;}
"<="	{return LE;}
">="	{return GE;}
"!="	{return NE;}
"=="	{return EE;}
"if"	{return IF;}
"then"	{return THEN;}
"else"	{return ELSE;}
"endif"	{return ENDIF;}
"while"	{return WHILE;}
"do"	{return DO;}
"endwhile"	{return ENDWHILE;}
"read"	{return READ;}
"write"	{return WRITE;}
"begin"	{return BEG;}
"end"	{return END;}
"break"	{return BREAK;}
"continue"	{return CONTINUE;}
[()]	{return *yytext;}
[ \t]	{}
[\n]	{}
.	{printf("unknown character:%c\n",*yytext);exit(1);}

%%

int yywrap(void) {
	return 1;
}

