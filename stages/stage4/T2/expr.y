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

%token NUM ID
%token PLUS MINUS MUL DIV EQ 
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
%left MUL DIV
%nonassoc LT LE GT GE EE NE

%%

start			:Declarations main		{printf("Syntax Matched\n");
										if($2==NULL){puts("Nothing to execute:)");exit(1);}
										generate($2,target_file);
										};

main			:BEG Slist END ';' 		{$$=$2;}
				|BEG END				{$$=NULL;}		
				;

Slist 			:Slist Stmt				{$$=createtree(t_NULL,NULL,NULL,nt_NODE,$1,NULL,$2);} 
				|Stmt					{$$=$1;}
				;

Stmt 			:READ '(' id ')' ';' 								{$$=createtree(t_NULL,NULL,NULL,nt_READ,NULL,$3,NULL);}
				|WRITE '(' Arth ')' ';' 							{$$=createtree(t_NULL,NULL,NULL,nt_WRITE,NULL,$3,NULL);}
				|id EQ Arth ';'										{$$=createtree(t_NULL,NULL,NULL,nt_ASGN,$1,NULL,$3);}
				|IF '(' Bool ')'	THEN Slist ELSE Slist ENDIF ';'	{$$=createtree(t_NULL,NULL,NULL,nt_IFELSE,$3,$6,$8);}
				|IF '(' Bool ')' THEN Slist ENDIF ';'				{$$=createtree(t_NULL,NULL,NULL,nt_IF,$1,NULL,$3);}
				|WHILE '(' Bool ')' DO Slist ENDWHILE ';'			{$$=createtree(t_NULL,NULL,NULL,nt_WHILE,$3,NULL,$6);}
				;

Declarations	:DECL DeclList ENDDECL ';' 
				|DECL ENDDECL ';'			
				;

DeclList 		:DeclList Decl	
				|Decl
				;

Decl 			:Type Varlist ';'
				;

Type 			:INT 	{type=t_INT;}
				|STR	{type=t_CHAR;}
				;

Varlist 		:Varlist ',' ID 				{Install($3->str,type,1);}
				|ID								{Install($1->str,type,1);}
				|Varlist ',' ID '[' NUM ']' 	{Install($3->str,type,$5->num);}
				|ID '[' NUM ']'					{Install($1->str,type,$3->num);}
				;

id 				:ID					{$$=createtree(t_CHAR,NULL,$1->str,nt_ID,NULL,NULL,NULL);}
				|ID '[' NUM ']'		{$$=createtree(t_CHAR,$3->num,$1->str,nt_ARR,NULL,NULL,NULL);}
				;
/*
expr			:Arth
				|Bool
				;
*/
Arth 			:Arth PLUS Arth			{$$ =createtree(t_INT,NULL,NULL,nt_PLUS,$1,NULL,$3);}
				|Arth MINUS Arth 		{$$ =createtree(t_INT,NULL,NULL,nt_MINUS,$1,NULL,$3);}
				|Arth MUL Arth			{$$ =createtree(t_INT,NULL,NULL,nt_MUL,$1,NULL,$3);}
				|Arth DIV Arth			{$$ =createtree(t_INT,NULL,NULL,nt_DIV,$1,NULL,$3);}
				|'(' Arth ')'			{$$ = $2;}
				|NUM					{$$ = $1;}
				|id 					{$$ = $1;}
				;

Bool			:Arth LT Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_LT,$1,NULL,$3);}
				|Arth LE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_LE,$1,NULL,$3);}
				|Arth GT Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_GT,$1,NULL,$3);}
				|Arth GE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_GE,$1,NULL,$3);}
				|Arth EE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_EE,$1,NULL,$3);}
				|Arth NE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_NE,$1,NULL,$3);}
				;

%%


void yyerror(char const *s)
{
	printf("yyerror %s",s);
}


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

/*	struct Gsymbol* temp=head;
	while(temp!=tail){
		printf("name:'%s'\ttype:'%d'\tsize:'%d'\tbinding:%d\n",temp->name,temp->type,temp->size,temp->binding);
		temp=temp->next;
	}
*/
	return 0;
}

