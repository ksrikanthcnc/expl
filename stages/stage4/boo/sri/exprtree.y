%{
	#include <stdio.h>
	#include <stdlib.h>
//	#include <signal.h>
	#define YYSTYPE tnode *
	#include "exprtree.h"
	#include "exprtree.c"
	#include "label.h"
	#include "label.c"
	#include "codegen.c"

//	char type[10];

	int yylex(void);
	void yyerror(char const *s);
	FILE *yyin,*target_file;
	int reg,type;

	yydebug=0;
%}

%token NUM ID
%token PLUS MINUS MUL DIV EQ 
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
%left MUL DIV EQ

%%

program		:Declarations main	{puts("Syntax matched");generate($2,inter);return $2;}
			;

main		:BEG Slist END ';'	{$$=$2;}
			|BEG END	';'		{return NULL;}
			;

Slist		:Slist Stmt		{$$= createTree($1,$2);}
			|Stmt 			{$$= $1;}
			;

Stmt		:READ '(' ID ')' ';'							{$$ = makeFunc("read",$3);}
			|WRITE '(' E ')' ';'							{$$ = makeFunc("write",$3);}
			|ID EQ E ';'									{opc($1);$$ = makeOperatorNode("=",$1,$3);}
			|IF '(' E ')' THEN Slist ELSE Slist ENDIF ';'	{$$=threeTree($3,$6,$8,"ifelse");}
			|IF '(' E ')' THEN Slist ENDIF ';'				{$$=twoTree($3,$6,"if");}
			|WHILE '(' E ')' DO Slist ENDWHILE ';'			{$$=twoTree($3,$6,"while");}
			|REPEAT Slist UNTIL '(' E ')' ';'				{$$=twoTree($5,$2,"while");}
			|DO Slist WHILE '(' E ')' ';'					{$$=twoTree($5,$2,"while");}
			|BREAK	';' 									{$$=makeNode("break");}
			|CONTINUE ';'									{$$=makeNode("continue");}
			;

E			:E PLUS E 	{$$ = makeOperatorNode("+",$1,$3);}
			|E MINUS E  {$$ = makeOperatorNode("-",$1,$3);}
			|E MUL E 	{$$ = makeOperatorNode("*",$1,$3);}
			|E DIV E 	{$$ = makeOperatorNode("/",$1,$3);}
			|'(' E ')'	{$$ = $2;}
			|ID			{$$ = $1;}
			|NUM		{$$ = $1;}
			|E LT E 	{$$ = makeOperatorNode("<",$1,$3);}
			|E GT E 	{$$ = makeOperatorNode(">",$1,$3);}
			|E LE E  	{$$ = makeOperatorNode("<=",$1,$3);}
			|E GE E  	{$$ = makeOperatorNode(">=",$1,$3);}
			|E NE E  	{$$ = makeOperatorNode("!=",$1,$3);}
			|E EE E 	{$$ = makeOperatorNode("==",$1,$3);}
			;

Declarations:DECL DeclList ENDDECL ';' 
			|DECL ENDDECL ';'			
			;

DeclList 	:DeclList Decl	
			|Decl
			;

Decl 		:Type Varlist ';'
			;

Type 		:INT 	{strcpy(type,"Int");}
			|STR	{strcpy(type,"Str");}
			;

Varlist 	:Varlist ',' ID 	
			|ID					{Install($1,type,1);}
			;

%%

yyerror(char const *s){
	printf("yyerror %s\n",s);
	exit(0);
}

opc(struct tnode *t){
	if(t->type=='c'){
		return;}
	else{
		puts("type mismatch-CHAR");
		printf("type:%c\n",t->type);
		exit(1);}
}

int main(){
	head=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	tail=head;

	yyparse();
	struct Gsymbol* temp;
	temp=head;
	while(temp){
		printf("name:'%s'\ttype:'%s'\tsize:'%d'\n",temp->name,temp->type,temp->size);
		temp=temp->next;
	}
	return 0;
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
