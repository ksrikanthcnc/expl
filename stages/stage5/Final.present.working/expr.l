%{
	#include<stdio.h>
	#include<stdlib.h>
	#include"y.tab.h"
%}

%%

"/*"([^*/]|(\*[^/])|(\/))*"*/"	{int i=yyleng;char *c;c=&yytext[0];while(i) {if(*c=='\n') line++;c++;i--;}}
"//".* 			{}
"+"				{return PLUS;}
"-"				{return MINUS;}
"*"				{return MUL;}
"/"				{return DIV;}
"%"				{return MOD;}
"="				{return EQ;}
"<"				{return LT;}
">"				{return GT;}
"<="			{return LE;}
">="			{return GE;}
"!="			{return NE;}
"=="			{return EE;}
"++"			{return INC;}
"--"			{return DEC;}
"||"			{return OR;}
"&&"			{return AND;}
"main"			{return MAIN;}
"return"		{return RETURN;}
"brkp"			{return BRKP;}
"exit"			{return EXIT;}
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
"tuple"			{return TUPLE;}
["][^"\n]*["]	{yylval = createtree(t_CHAR,NULL,strdup(yytext),nt_STR,NULL,NULL,NULL,NULL,NULL,NULL);return STRING;}
['][^'\n]*[']	{yylval = createtree(t_CHAR,NULL,strdup(yytext),nt_STR,NULL,NULL,NULL,NULL,NULL,NULL);return STRING;}
[0-9]+			{yylval = createtree(t_INT,atoi(yytext),NULL,nt_NUM,NULL,NULL,NULL,NULL,NULL,NULL); return NUM;}
[a-zA-Z0-9]+			{yylval = createtree(NULL,NULL,yytext,nt_ID,NULL,NULL,NULL,NULL,NULL,NULL);return ID;}	//type=t_CHAR???
[(),\[\];&{}.]	{return *yytext;}
[ \t]			{}
[\n]			{line++;}
.				{printf("unknown character:'%c' line:'%d'\n",*yytext,line);exit(1);}

%%
int yywrap(void){
	return 1;
}

