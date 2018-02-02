%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE tnode *
#include "expr.h"
#include "expr.c"
#include "lex.yy.c"

yydebug=0;
//int yylex(void);
//void yyerror(char const *s);
FILE *yyin,*target_file;
int reg;
int type;
%}

%token NUM ID STRING
%token PLUS MINUS MUL DIV MOD EQ 
%token INC DEC
%token BEG END
%token READ WRITE
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE
%token BREAK CONTINUE 
%token REPEAT UNTIL
%token DECL ENDDECL
%token INT STR
%token ';'
%left PLUS MINUS
%left MUL DIV MOD
%nonassoc LT LE GT GE EE NE

%%

start			:Declarations main		{printf("Syntax Matched\n");
										if($2==NULL){puts("Nothing to execute :)");}
										generate($2,target_file);
										};

Declarations	:DECL DeclList ENDDECL ';' 	{other();}
				|DECL ENDDECL ';'			{puts("Nothing declared!! :)");}
				;

DeclList		:DeclList Decl	
				|Decl
				;

Decl			:Type Varlist ';'
				;

Type			:INT	{type=t_INT;}
				|STR	{type=t_CHAR;}
				;

Varlist			:Varlist ',' declid
				|declid									
				;
				
declid			:ID										{Install($1->str,type,1);}
				|ID '[' NUM ']'							{int t=type;type=type==t_INT?t_INARR:t_CHARR;Install($1->str,type,$3->num);type=t;}
				|ID '[' NUM ']' '[' NUM ']'				{int t=type;type=type==t_INT?t_INARR:t_CHARR;Install($1->str,type,$3->num*$6->num);type=t;Lookup($1->str)->arr=$3->num;}
				|MUL ID									{int t=type;type=type==t_INT?t_INPTR:t_CHPTR;Install($2->str,type,1);type=t;}
				;

main			:BEG Slist END ';'		{$$=$2;}
				|BEG END				{$$=NULL;}		
				;

Slist			:Slist Stmt				{$$=createtree(t_NULL,NULL,NULL,nt_NODE,$1,NULL,$2,NULL);} 
				|Stmt					{$$=$1;}
				;

Stmt			:READ '(' id ')' ';'								{$$=createtree(t_NULL,NULL,NULL,nt_READ,NULL,$3,NULL,NULL);}
				|WRITE '(' Arth ')' ';'								{$$=createtree(t_NULL,NULL,NULL,nt_WRITE,NULL,$3,NULL,NULL);}
				|WRITE STRING ';'									{$$=createtree(t_NULL,NULL,NULL,nt_WRITE,NULL,$2,NULL,NULL);}
				|id EQ Arth ';'										{$$=createtree(t_NULL,NULL,NULL,nt_ASGN,$1,NULL,$3,NULL);}
				|IF '(' Bool ')' THEN Slist ELSE Slist ENDIF ';'	{$$=createtree(t_NULL,NULL,NULL,nt_IFELSE,$3,$6,$8,NULL);}
				|IF '(' Bool ')' THEN Slist ENDIF ';'				{$$=createtree(t_NULL,NULL,NULL,nt_IF,$1,NULL,$3,NULL);}
				|WHILE '(' Bool ')' DO Slist ENDWHILE ';'			{$$=createtree(t_NULL,NULL,NULL,nt_WHILE,$3,NULL,$6,NULL);}
				|REPEAT Slist UNTIL '(' Bool ')' ';'				{$$=createtree(t_NULL,NULL,NULL,nt_WHILE,$5,NULL,$2,NULL);}
				|DO Slist WHILE '(' Bool ')' ';'					{$$=createtree(t_NULL,NULL,NULL,nt_WHILE,$5,NULL,$2,NULL);}
				|BREAK ';'											{$$=createtree(t_NULL,NULL,NULL,nt_BREAK,NULL,NULL,NULL,NULL);}
				|CONTINUE ';'										{$$=createtree(t_NULL,NULL,NULL,nt_CONTINUE,NULL,NULL,NULL,NULL);}
				;

Arth			:Arth PLUS Arth			{$$ =createtree(t_INT,NULL,NULL,nt_PLUS,$1,NULL,$3,NULL);}
				|Arth MINUS Arth		{$$ =createtree(t_INT,NULL,NULL,nt_MINUS,$1,NULL,$3,NULL);}
				|Arth MUL Arth			{$$ =createtree(t_INT,NULL,NULL,nt_MUL,$1,NULL,$3,NULL);}
				|Arth DIV Arth			{$$ =createtree(t_INT,NULL,NULL,nt_DIV,$1,NULL,$3,NULL);}
				|Arth MOD Arth			{$$ =createtree(t_INT,NULL,NULL,nt_MOD,$1,NULL,$3,NULL);}
				|'(' Arth ')'			{$$ = $2;}
				|NUM					{$$ = $1;}
				|STRING					{$$ = $1;}
				|id						{$$ = $1;}
				;

Bool			:Arth LT Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_LT,$1,NULL,$3,NULL);}
				|Arth LE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_LE,$1,NULL,$3,NULL);}
				|Arth GT Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_GT,$1,NULL,$3,NULL);}
				|Arth GE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_GE,$1,NULL,$3,NULL);}
				|Arth EE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_EE,$1,NULL,$3,NULL);}
				|Arth NE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_NE,$1,NULL,$3,NULL);}
				;
//divide below to nt_PTR,nt_ID
id				:ID							{if(Lookup($1->str)==NULL){
												printf("Undeclared identifier:%s\n",$1->str);
												exit(1);}
											int t=Lookup($1->str)->type,nt;
											if(t==t_INPTR || t==t_CHPTR){t=t==t_INPTR?t_INT:t_CHAR;nt=nt_PTR;}
											else nt=nt_ID;
											$$=createtree(t,NULL,$1->str,nt,NULL,NULL,NULL,Lookup($1->str));}
				|ID '[' NUM ']'				{if(Lookup($1->str)==NULL){
												printf("Undeclared identifier:%s\n",$1->str);
												exit(1);}
											int t=Lookup($2->str)->type;
											if(t!=t_INARR && t!=t_CHARR)printf("\tSomething's wrong!--arr[1D]\tline:%d\tt=t_%d\n",line,t);
											t=t==t_INARR?t_INT:t_CHAR;
											$$=createtree(t,$3->num,$1->str,nt_ARR,NULL,NULL,NULL,Lookup($1->str));}
				|ID '[' NUM ']' '[' NUM ']'	{if(Lookup($1->str)==NULL){
												printf("Undeclared identifier:%s\n",$1->str);
												exit(1);}
											int t=Lookup($2->str)->type;
											if(t!=t_INARR && t!=t_CHARR)printf("\tSomething's wrong!--arr[2D]\tline:%d\tt=t_%d\n",line,t);
											t=t_INARR?t_INT:t_CHAR;
											$$=createtree(t,(Lookup($1->str)->arr)*($3->num)+($6->num),$1->str,nt_ARR,NULL,NULL,NULL,Lookup($1->str));}
				|MUL id						{int t=Lookup($2->str)->type;
											if(t!=t_INPTR && t!=t_CHPTR)printf("\tSomething's wrong!--*\tline:%d\tt=t_%d\n",line,t);
											t=t_INPTR?t_INT:t_CHAR;
											$$=createtree(t,$2->num,$2->str,nt_SPTR,NULL,NULL,NULL,Lookup($2->str));}
				|'&' id						{int t=Lookup($2->str)->type;
											if(t==t_INARR || t==t_CHARR)t=t==t_INARR?t_INT:t_CHAR;
											else if(t!=t_INT && t!=t_CHAR)printf("\tSomething's wrong!--&\tline:%d\tt=t_%d\n",line,t);
											$$=createtree(t,$2->num,$2->str,nt_APTR,NULL,NULL,NULL,Lookup($2->str));}
				;
%%


void yyerror(char const *s)
{
	printf("yyerror %s\nLine:%d\n",s,line);
	exit(1);
}

void other(){

	struct Gsymbol* temp=head;
	while(temp!=tail){
		printf("name:'%s'\ttype:'%d'\tsize:'%d'\tarr:%d\n",temp->name,temp->type,temp->size,temp->arr);
		temp=temp->next;}

}

void n(int n){printf("~~~%d~~~\n",n);}
void c(char c){printf("~~~%c~~~\n",c);}
void s(char *s){printf("~~~%s~~~\n",s);}

int main(void) 
{
	head=malloc(sizeof(struct Gsymbol));
	tail=head;

	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else
		printf("Input file error\n");
	target_file=fopen("intermediate.xsm","w+");
	yyparse();

//	other();
	return 0;
}

