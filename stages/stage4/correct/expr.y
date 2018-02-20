%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE tnode *
#include "expr.h"
#include "expr.c"
//#include "codegen.c"
#include "lex.yy.c"

yydebug=0;
int yylex(void);
void yyerror(char const *s);
FILE *yyin,*target_file;
int reg;
int type;
%}

%token NUM ID PLUS MINUS MUL DIV BEG END NL READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE LT LE GT GE EE NE INC DEC BREAK CONTINUE EQ REPEAT UNTIL DECL ENDDECL INT STR
%left PLUS MINUS
%left MUL DIV
%nonassoc LT LE GT GE EE NE

%%

program :Declarations main		{printf("Syntax Matched\n"); //	evaluate($2);
						if($2==NULL){
						puts("Nothing to execute:)");
							exit(1);}
									generate($2,target_file);
								};

main : BEG Slist END ';' 	{$$=$2;}
		| BEG END	{$$=NULL;}		
	;

Slist : Slist Stmt	{$$=createtree(t_NULL,NULL,NULL,nt_NODE,$1,NULL,$2);} 
	| Stmt			{$$=$1;}
	;

Stmt :	READ '(' ID ')' ';' {$$=createtree(t_NULL,NULL,NULL,nt_READ,NULL,$3,NULL);}
	|	WRITE '(' expr ')' ';' {$$=createtree(t_NULL,NULL,NULL,nt_WRITE,NULL,$3,NULL);}
	|	ID EQ expr ';'		{$$=createtree(t_NULL,NULL,NULL,nt_ASGN,$1,NULL,$3);}
	|	IF '(' expr ')'	THEN Slist ELSE Slist ENDIF ';'	{$$=createtree(t_NULL,NULL,NULL,nt_IFELSE,$3,$6,$8);}
	|IF '(' expr ')' THEN Slist ENDIF ';'			{$$=createtree(t_NULL,NULL,NULL,nt_IF,$1,NULL,$3);}
	|	WHILE '(' expr ')' DO Slist ENDWHILE ';'	{$$=createtree(t_NULL,NULL,NULL,nt_WHILE,$3,NULL,$6);}
	;

Declarations:DECL DeclList ENDDECL ';' 
			|DECL ENDDECL ';'			
			;

DeclList 	:DeclList Decl	
			|Decl
			;

Decl 		:Type Varlist ';'
			;

Type 		:INT 	{type=t_INT;}
		|STR	{type=t_CHAR;}
			;

Varlist 	:Varlist ',' ID 	{Install($3->str,type,1);}
			|ID		{Install($1->str,type,1);}
			;


expr : expr PLUS expr			{$$ =createtree(t_INT,NULL,NULL,nt_PLUS,$1,NULL,$3);}
	| expr MINUS expr 		{$$ =createtree(t_INT,NULL,NULL,nt_MINUS,$1,NULL,$3);}
	| expr MUL expr			{$$ =createtree(t_INT,NULL,NULL,nt_MUL,$1,NULL,$3);}
	| expr DIV expr			{$$ =createtree(t_INT,NULL,NULL,nt_DIV,$1,NULL,$3);}
	| '(' expr ')'			{$$ = $2;}
	| NUM					{$$ = $1;}
	| ID 					{$$ = $1;}
	| expr LT expr			{$$ =createtree(t_BOOL,NULL,NULL,nt_LT,$1,NULL,$3);}
	| expr LE expr			{$$ =createtree(t_BOOL,NULL,NULL,nt_LE,$1,NULL,$3);}
	| expr GT expr			{$$ =createtree(t_BOOL,NULL,NULL,nt_GT,$1,NULL,$3);}
	| expr GE expr			{$$ =createtree(t_BOOL,NULL,NULL,nt_GE,$1,NULL,$3);}
	| expr EE expr			{$$ =createtree(t_BOOL,NULL,NULL,nt_EE,$1,NULL,$3);}
	| expr NE expr			{$$ =createtree(t_BOOL,NULL,NULL,nt_NE,$1,NULL,$3);}
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
		printf("name:'%s'\ttype:'%d'\tsize:'%d'\n",temp->name,temp->type,temp->size);
		temp=temp->next;
	}
*/
	return 0;
}

