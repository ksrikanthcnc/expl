%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"y.tab.h"
%}

%%

"+"				{return PLUS;}
"-"				{return MINUS;}
"*"				{return MUL;}
"/"				{return DIV;}
"="				{return EQ;}
"<"				{return LT;}
">"				{return GT;}
"<="			{return LE;}
">="			{return GE;}
"!="			{return NE;}
"=="			{return EE;}
"if"			{return IF;}
"then"			{return THEN;}
"else"			{return ELSE;}
"endif"			{return ENDIF;}
"repeat"		{return REPEAT;}
"until"			{return UNTIL;}
"do"			{return DO;}
"while"			{return WHILE;}
"endwhile"		{return ENDWHILE;}
"read"			{return READ;}
"write"			{return WRITE;}
"begin"			{return BEG;}
"end"			{return END;}
"break"			{return BREAK;}
"continue"		{return CONTINUE;}
"decl"			{return DECL;}
"enddecl"		{return ENDDECL;}
"int"			{return INT;}
"str"			{return STR;}
[*][a-z]		{char* ret=malloc(sizeof(char)*yylen);strcpy(ret,yytext[1]);yylval = createtree(t_PTR,NULL,ret,nt_ID,NULL,NULL,NULL);return PTR;}
["][^"\n]+["]	{yylval = createtree(t_STR,NULL,yytext,nt_STR,NULL,NULL,NULL);return STRING;}
[0-9]+			{yylval = createtree(t_INT,atoi(yytext),NULL,nt_NUM,NULL,NULL,NULL); return NUM;}
[a-z]+			{yylval = createtree(t_CHAR,NULL,yytext,nt_ID,NULL,NULL,NULL);return ID;}
[(),\[\];]		{return *yytext;}
[ \t\n]			{}
.				{printf("unknown character:%c\n",*yytext);exit(1);}

%%
int yywrap(void){
	return 1;
}

char* remfirst(char* yytext){
	char* ret=malloc(sizeof(char)*strlen(yytext));
	strncpy(ret,&yytext[1]);
	
}
