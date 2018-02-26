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
"=="			{return EE;}/*
"++"			{return INC;}
"--"			{return DEC;}*/
"!"				{return NOT;}
"not"			{return NOT;}
"||"			{return OR;}
"or"			{return OR;}
"&&"			{return AND;}
"and"			{return AND;}
"true"			{return TRUE;}
"false"			{return FALSE;}
"return"		{return RETURN;}
"brkp"			{return BRKP;}
"breakpoint"	{return BRKP;}
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
"print"			{return WRITE;}
"begin"			{return BEG;}
"end"			{return END;}
"break"			{return BREAK;}
"continue"		{return CONTINUE;}
"decl"			{return DECL;}
"enddecl"		{return ENDDECL;}
"tuple"			{return TUPLE;}
"type"			{return TYPE;}
"endtype"		{return ENDTYPE;}
"int main"		{return MAIN;}
"initialize"	{return INIT;}
"alloc"			{return ALLOC;}
"free"			{return FREE;}
"class"			{return CLASS;}
"endclass"		{return ENDCLASS;}
"extends"		{return EXTENDS;}
"new"			{return NEW;}
"delete"		{return DELETE;}
"self"			{return SELF;}

["][^"\n]*["]					{yylval = createtree(TLookup("str"),0,strdup(yytext),nt_STR,NULL,NULL,NULL,NULL,NULL,NULL);return STRING;}
['][^'\n]*[']					{yylval = createtree(TLookup("str"),0,strdup(yytext),nt_STR,NULL,NULL,NULL,NULL,NULL,NULL);return STRING;}
[0-9]+							{yylval = createtree(TLookup("int"),atoi(yytext),NULL,nt_NUM,NULL,NULL,NULL,NULL,NULL,NULL); return NUM;}
[a-zA-Z][a-zA-Z0-9]*			{yylval = createtree(NULL,0,yytext,nt_ID,NULL,NULL,NULL,NULL,NULL,NULL);return ID;}	//type=t_CHAR???
[(),\[\];&{}.]					{return *yytext;}
[ \t]							{}
[\n]							{line++;}
.								{printf("line:'%d'\tunknown character:'%c'\n",line,*yytext);exit(1);}

%%
int yywrap(void){
	return 1;
}

