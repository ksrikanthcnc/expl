%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE tnode *
#include "abstracttree.h"
#include "abstracttree.c"
#include "symboltable.h"
#include "symboltable.c"
#include "codegen.c"

int yylex(void);
void yyerror(char const *s);
FILE *yyin,*target_file;
int reg,type;

%}

%token NUM ID
%token PLUS MINUS MUL DIV EQ 
%token INC DEC
%nonassoc LT GT LE GE NE EE
%token BEG END
%token READ WRITE
%token IF THEN ELSE ENDIF
%token WHILE DO ENDWHILE
%token BREAK CONTINUE 
%token REPEAT UNTIL
%token DECL ENDDECL
%token INT STR
//%token DO WHILE
%token ';'
%left PLUS MINUS
%left MUL DIV

%%

program: Declarations main {//printf("Evaluating tree\n"); 
								//abst_evaluate($2);
								generate($2,target_file);
							exit(1);}
;

main:BEG Slist END ';'	{$$=$2;} 
	|BEG END	';'		{}
	;

Slist:Slist Stmt	{$$=createtree(0,nodetype_NULL,type_null,NULL,$1,$2,NULL);} 
	|Stmt			{$$=$1;}
	;

Stmt :	InputStmt		{$$=$1;} 
	|	OutputStmt		{$$=$1;}
	|	AsgStmt			{$$=$1;}
	|	IfStmt			{$$=$1;}
	|	WhileStmt		{$$=$1;}
	;

InputStmt:	READ '(' ID ')' ';' {
									tempst=Lookup($3->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
									else $3->Gentry=tempst;
									$$=createtree(0,nodetype_READ,type_null,NULL,$3,NULL,NULL);
								}
		|	READ '(' ID '[' expr ']' ')' ';' {
									tempst=Lookup($3->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",$3->varname );exit(1);}
									else $3->Gentry=tempst;
									$$=createtree(0,nodetype_ARRREAD,type_null,NULL,$3,$5,NULL);
								}
	;

OutputStmt:	WRITE '(' expr ')' ';'	{$$=createtree(0,nodetype_WRITE,type_null,NULL,$3,NULL,NULL);}
	;

AsgStmt:	ID EQ expr ';'		{
									tempst=Lookup($1->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
									else $1->Gentry=tempst;
									$$=createtree(0,nodetype_ASGN,type_null,NULL,$1,$3,NULL);
								}
		|	ID '[' expr ']' '=' expr ';'	{
												tempst=Lookup($1->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
												else $1->Gentry=tempst;
												$$=createtree(0,nodetype_ARRASGN,type_null,NULL,$1,$3,$6);
											}	
	;

IfStmt:		IF '(' expr ')'	THEN Slist ELSE Slist ENDIF ';'	{$$=createtree(0,nodetype_IF,type_null,NULL,$3,$6,$8);}
	|		IF '(' expr ')' THEN Slist ENDIF ';'			{$$=createtree(0,nodetype_IF,type_null,NULL,$1,$3,NULL);}
	;

WhileStmt:	WHILE '(' expr ')' DO Slist ENDWHILE ';'	{$$=createtree(0,nodetype_WHILE,type_null,NULL,$3,$6,NULL);}
	;	


expr : expr PLUS expr		{$$ =createtree(0,nodetype_PLUS,type_int,NULL,$1,$3,NULL);}
	| expr MINUS expr 		{$$ =createtree(0,nodetype_MINUS,type_int,NULL,$1,$3,NULL);}
	| expr MUL expr			{$$ =createtree(0,nodetype_MUL,type_int,NULL,$1,$3,NULL);}
	| expr DIV expr			{$$ =createtree(0,nodetype_DIV,type_int,NULL,$1,$3,NULL);}
	| '(' expr ')'			{$$ = $2;}
	| NUM					{$$ = $1;}
	| expr LT expr			{$$ =createtree(0,nodetype_LT,type_bool,NULL,$1,$3,NULL);}
	| expr LE expr			{$$ =createtree(0,nodetype_LE,type_bool,NULL,$1,$3,NULL);}
	| expr GT expr			{$$ =createtree(0,nodetype_GT,type_bool,NULL,$1,$3,NULL);}
	| expr GE expr			{$$ =createtree(0,nodetype_GE,type_bool,NULL,$1,$3,NULL);}
	| expr EQ expr			{$$ =createtree(0,nodetype_EQ,type_bool,NULL,$1,$3,NULL);}
	| expr NE expr			{$$ =createtree(0,nodetype_NE,type_bool,NULL,$1,$3,NULL);}
	| ID 					{
								tempst=Lookup($1->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
								else {$1->Gentry=tempst; $1->type=tempst->type;}
								$$ = $1;
							}
	| ID '[' expr ']'		{
								tempst=Lookup($1->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",$1->varname );exit(1);}
								else {$1->Gentry=tempst; 
										if(tempst->type==type_int)
											$1->type=type_arrint;
										else if(tempst->type==type_char)
											$1->type=type_str;
									 }
								$$ = createtree(0,nodetype_ARRID,$1->type,NULL,$1,$3,NULL);
							}
	;

Declarations:	DECL DeclList ENDDECL	{printsymtab();}
			|	DECL ENDDECL			{}
			;

DeclList:		DeclList Decl 			{}
		|		Decl 					{}
		;

Decl:	Type VarList ';'				{}
	;

Type:	INTG 		{type=type_int;}
	|	STR 		{type=type_char;}
	;

VarList :	VarList ',' ID 		{Install($3->varname,type,1);}
		|	ID 					{Install($1->varname,type,1);}
		|	VarList ',' ID '[' NUM ']' {		
											if(type==type_int)
												Install($3->varname,type_arrint,$5->val);
											else if(type==type_char)
												Install($3->varname,type_str,$5->val);	
										}
		|	ID '[' NUM ']'		{
									if(type==type_int)
										Install($1->varname,type_arrint,$3->val);
									else if(type==type_char)
										Install($1->varname,type_str,$3->val);
								}
		;

%%


void yyerror(char const *s)
{
	printf("yyerror %s",s);
}


int main(void) 
{
	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else
		printf("Input file error\n");
	target_file=fopen("intermediate.xsm","w+");
	Ghead=NULL;varadrs=4096;
	yyparse();
	return 0;
}
