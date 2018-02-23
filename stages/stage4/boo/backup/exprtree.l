%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

[0-9]+		{yylval = makeLeafNum(atoi(yytext)); return NUM;}
[a-z]+		{yylval = makeLeafID(*yytext);return ID;}
"+"			{return PLUS;}
"-"			{return MINUS;}
"*"			{return MUL;}
"/"			{return DIV;}
"="			{return EQ;}
";"			{return *yytext;}
"<"			{return LT;}
">"			{return GT;}
"<="		{return LE;}
">="		{return GE;}
"!="		{return NE;}
"=="		{return EE;}
"if"		{return IF;}
"then"		{return THEN;}
"else"		{return ELSE;}
"endif"		{return ENDIF;}
"repeat"	{return REPEAT;}
"until"		{return UNTIL;}
"do"		{return DO;}
"while"		{return WHILE;}
"endwhile"	{return ENDWHILE;}
"read"		{return READ;}
"write"		{return WRITE;}
"begin"		{return BEG;}
"end"		{return END;}
"break"		{return BREAK;}
"continue"	{return CONTINUE;}
"decl"		{return DECL;}
"enddecl"	{return ENDDECL;}
"int"		{return INT;}
"str"		{return STR;}
[(),]		{return *yytext;}
[ \t]		{}
[\n]		{}
.			{printf("unknown character:%c\n",*yytext);exit(1);}

%%

int yywrap(void) {
	return 1;
}

