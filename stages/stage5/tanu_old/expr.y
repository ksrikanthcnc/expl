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
int type,temptype,retcount=0,flabel=0;;
char *funcname;
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
%token MAIN RETURN BRKP
%token AND OR
%left PLUS MINUS
%left MUL DIV MOD
%nonassoc LT LE GT GE EE NE

%%
//------------------------------------------------------------------------------------
start		:Program;
Program		:GDeclBlock FDefBlock MainBlock		{printf("Syntax Matched\n");}
			|GDeclBlock MainBlock				{printf("Syntax Matched\n");}
			|MainBlock							{printf("Syntax Matched\n");}
			;
//-------------------------------------------------------------------------
GDeclBlock	:DECL GDeclList ENDDECL ';'	{generate(target_file);}
			|DECL ENDDECL ';'			{generate(target_file);puts("No Global declared!");}
			;

GDeclList	:GDeclList GDecl			{}
			|GDecl						{}
			;

GDecl		:Type GidList ';'			{}
			;

Type		:INT	{type=t_INT;}
			|STR	{type=t_CHAR;}
			;

GidList		:GidList ',' Gid
			|Gid
			;

Gid			:ID										{GInstall($1->str,type,1);}
			|ID '[' NUM ']'							{int t=type;type=type==t_INT?t_INARR:t_CHARR;GInstall($1->str,type,$3->num);type=t;}
			|ID '[' NUM ']' '[' NUM ']'				{int t=type;type=type==t_INT?t_INARR:t_CHARR;GInstall($1->str,type,$3->num*$6->num);type=t;GLookup($1->str)->arr=$3->num;}
			|MUL ID									{int t=type;type=type==t_INT?t_INPTR:t_CHPTR;GInstall($2->str,type,1);type=t;}
			//ID '(' ParamList ')'
			|ID '(' {phead=ptail=malloc(sizeof(struct Paramstruct));temptype=type;} 
					ParamList {type=temptype;}
								')'	{	GInstall($1->str,type,0);
										struct Paramstruct *ptemp=phead;
										while(ptemp!=ptail){
											if(ptemp->next==ptail){
												ptemp->next=NULL;break;}
											ptemp=ptemp->next;}
										if(ptemp==ptail)	{phead=NULL;}
										GLookup($1->str)->paramlist=phead;
										GLookup($1->str)->flabel=flabel++;}
			;
//int factorial(int a, int b){}--------------------------------------------------------------------------------------
FDefBlock	:FDefBlock FDef
			|FDef
			;
			//Type ID '(' ParamList ')' '{' LDeclBlock Body '}'
FDef		:Type ID '(' {	check($2);
							funcname=$2->str;
							binding=-2;
							lhead=ltail=malloc(sizeof(struct Lsymbol));
							phead=ptail=malloc(sizeof(struct Paramstruct));}
						ParamList ')' {	struct Paramstruct *ptemp=phead;
										while(ptemp!=ptail){
											if(ptemp->next==ptail){
												ptemp->next=NULL;break;}
											ptemp=ptemp->next;}
										if(ptemp==ptail)	{phead=NULL;}
										LocalParam(lhead,phead,GLookup($2->str));}
									 '{' {if(lhead==NULL)
		 									lhead=ltail=malloc(sizeof(struct Lsymbol));
		 								 binding=0;}
		 									LDeclBlock Body '}'
			;

ParamList	:ParamList ',' Param			{}
			|Param
			| /*param can be empty*/
			;

Param		:Type ID	{PInstall($2->str,type);}
			;

//-----------------------------------------------------------------------------------------
LDeclBlock	:DECL LDecList ENDDECL ';'
			|DECL ENDDECL ';'
			;

LDecList	:LDecList LDecl
			|LDecl
			;

LDecl		:Type IdList ';'
			;

IdList		:IdList ',' ID	{binding++;LInstall($2->str,type);}
			|ID				{binding++;LInstall($1->str,type);}
			;
//-------------------------------------------------------------------------------------------

MainBlock : INT MAIN {binding=0;}'(' ')' '{' {	funcname="main";
												if(lhead==NULL)
			 										lhead=ltail=malloc(sizeof(struct Lsymbol));
		 										binding=0;}
		 									LDeclBlock Body '}'
/*                                {
                                    type = TLookup("int");
                                    gtemp = GInstall("MAIN",type,0,NULL);
                                    //...Some more work to be done
                                }
*/			;

//-------------------------------------------------------------------------------------------
Body		:BEG Slist END ';'		{//$$=$2;
									if(retcount==0){
										printf("No return statements found!\n");}
									funcGen(GLookup(funcname),target_file);
 									codeGen($2,target_file);retcount=0;}
			|BEG END ';'			{$$=NULL;printf("No Body!\n");}
			;

Slist		:Slist Stmt				{$$=createtree(t_NULL,NULL,NULL,nt_NODE,$1,NULL,$2,NULL,NULL);}
			|Stmt					{$$=$1;}
			;

Stmt		:READ '(' id ')' ';'								{$$=createtree(t_NULL,NULL,NULL,nt_READ,NULL,$3,NULL,NULL,NULL);}
			|WRITE '(' Arth ')' ';'								{$$=createtree(t_NULL,NULL,NULL,nt_WRITE,NULL,$3,NULL,NULL,NULL);}
			|WRITE STRING ';'									{$$=createtree(t_NULL,NULL,NULL,nt_WRITE,NULL,$2,NULL,NULL,NULL);}
			|id EQ Arth ';'										{$$=createtree(t_NULL,NULL,NULL,nt_ASGN,$1,NULL,$3,NULL,NULL);}
			|IF '(' Bool ')' THEN Slist ELSE Slist ENDIF ';'	{$$=createtree(t_NULL,NULL,NULL,nt_IFELSE,$3,$6,$8,NULL,NULL);}
			|IF '(' Bool ')' THEN Slist ENDIF ';'				{$$=createtree(t_NULL,NULL,NULL,nt_IF,$1,NULL,$3,NULL,NULL);}
			|WHILE '(' Bool ')' DO Slist ENDWHILE ';'			{$$=createtree(t_NULL,NULL,NULL,nt_WHILE,$3,NULL,$6,NULL,NULL);}
			|REPEAT Slist UNTIL '(' Bool ')' ';'				{$$=createtree(t_NULL,NULL,NULL,nt_WHILE,$5,NULL,$2,NULL,NULL);}
			|DO Slist WHILE '(' Bool ')' ';'					{$$=createtree(t_NULL,NULL,NULL,nt_WHILE,$5,NULL,$2,NULL,NULL);}
			|BREAK ';'											{$$=createtree(t_NULL,NULL,NULL,nt_BREAK,NULL,NULL,NULL,NULL,NULL);}
			|CONTINUE ';'										{$$=createtree(t_NULL,NULL,NULL,nt_CONTINUE,NULL,NULL,NULL,NULL,NULL);}
			|RETURN Arth ';'									{retcount++;$$=createtree(GLookup(funcname)->type,NULL,NULL,nt_RET,NULL,$2,NULL,NULL,NULL);}
			|BRKP ';'											{$$=createtree(t_NULL,NULL,NULL,nt_BRKP,NULL,NULL,NULL,NULL,NULL);}
			;

Arth		:Arth PLUS Arth			{$$=createtree(t_INT,NULL,NULL,nt_PLUS,$1,NULL,$3,NULL,NULL);}
			|Arth MINUS Arth		{$$=createtree(t_INT,NULL,NULL,nt_MINUS,$1,NULL,$3,NULL,NULL);}
			|Arth MUL Arth			{$$=createtree(t_INT,NULL,NULL,nt_MUL,$1,NULL,$3,NULL,NULL);}
			|Arth DIV Arth			{$$=createtree(t_INT,NULL,NULL,nt_DIV,$1,NULL,$3,NULL,NULL);}
			|Arth MOD Arth			{$$=createtree(t_INT,NULL,NULL,nt_MOD,$1,NULL,$3,NULL,NULL);}
			|'(' Arth ')'			{$$=$2;}
			|NUM					{$$=$1;}
			|STRING					{$$=$1;}
			|id						{$$=$1;}
			|ID '(' ')'				{check($1);$$=createtree(GLookup($1->str)->type,NULL,$1->str,nt_FUNC,NULL,NULL,NULL,GLookup($1->str),NULL);} 
			|ID '(' ArgList ')'		{check($1);
									$$=createtree(GLookup($1->str)->type,NULL,$1->str,nt_FUNC,NULL,NULL,NULL,GLookup($1->str),$3);}
			;

ArgList		:ArgList ',' Arth		{	struct tnode *t=$1;
										while(t->down!=NULL)
											t=t->down;
										t->down=$3;
										$$=$1;}
			|Arth					{$$=$1;}
			;

Bool		:Arth LT Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_LT,$1,NULL,$3,NULL,NULL);}
			|Arth LE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_LE,$1,NULL,$3,NULL,NULL);}
			|Arth GT Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_GT,$1,NULL,$3,NULL,NULL);}
			|Arth GE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_GE,$1,NULL,$3,NULL,NULL);}
			|Arth EE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_EE,$1,NULL,$3,NULL,NULL);}
			|Arth NE Arth			{$$ =createtree(t_BOOL,NULL,NULL,nt_NE,$1,NULL,$3,NULL,NULL);}
			;

id			:ID							{check($1);
										if(LLookup($1->str)==NULL){//Global
											int t=GLookup($1->str)->type,nt;
											if(t==t_INPTR || t==t_CHPTR){t=t==t_INPTR?t_INT:t_CHAR;nt=nt_PTR;}
											else nt=nt_ID;
											$$=createtree(t,NULL,$1->str,nt,NULL,NULL,NULL,GLookup($1->str),NULL);}
										else{//Local
											int t=LLookup($1->str)->type,nt;
											if(t==t_INPTR || t==t_CHPTR){t=t==t_INPTR?t_INT:t_CHAR;nt=nt_PTR;}
											else nt=nt_ID;
											$$=createtree(t,NULL,$1->str,nt,NULL,NULL,NULL,NULL,NULL);}}
			|ID '[' NUM ']'				{check($1);
										int t=GLookup($2->str)->type;
										if(t!=t_INARR && t!=t_CHARR)printf("\tSomething's wrong!--arr[1D]\tline:%d\tt=t_%d\n",line,t);
										t=t==t_INARR?t_INT:t_CHAR;
										$$=createtree(t,$3->num,$1->str,nt_ARR,NULL,NULL,NULL,GLookup($1->str),NULL);}
			|ID '[' NUM ']' '[' NUM ']'	{check($1);
										int t=GLookup($2->str)->type;
										if(t!=t_INARR && t!=t_CHARR)printf("\tSomething's wrong!--arr[2D]\tline:%d\tt=t_%d\n",line,t);
										t=t_INARR?t_INT:t_CHAR;
										$$=createtree(t,(GLookup($1->str)->arr)*($3->num)+($6->num),$1->str,nt_ARR,NULL,NULL,NULL,GLookup($1->str),NULL);}
			|MUL id						{if(LLookup($2->str)==NULL){
											int t=GLookup($2->str)->type;
											if(t!=t_INPTR && t!=t_CHPTR)printf("\tSomething's wrong!--*\tline:%d\tt=t_%d\n",line,t);
											t=t_INPTR?t_INT:t_CHAR;
											$$=createtree(t,$2->num,$2->str,nt_SPTR,NULL,NULL,NULL,GLookup($2->str),NULL);}
										else{int t=LLookup($2->str)->type;
											if(t!=t_INPTR && t!=t_CHPTR)printf("\tSomething's wrong!--*\tline:%d\tt=t_%d\n",line,t);
											t=t_INPTR?t_INT:t_CHAR;
											$$=createtree(t,$2->num,$2->str,nt_SPTR,NULL,NULL,NULL,LLookup($2->str),NULL);}}
			|'&' id						{if(LLookup($2->str)==NULL){
											int t=GLookup($2->str)->type;
											if(t==t_INARR || t==t_CHARR)t=t==t_INARR?t_INT:t_CHAR;
											else if(t!=t_INT && t!=t_CHAR)printf("\tSomething's wrong!--&\tline:%d\tt=t_%d\n",line,t);
											$$=createtree(t,$2->num,$2->str,nt_APTR,NULL,NULL,NULL,GLookup($2->str),NULL);}
										else{int t=LLookup($2->str)->type;
											if(t==t_INARR || t==t_CHARR)t=t==t_INARR?t_INT:t_CHAR;
											else if(t!=t_INT && t!=t_CHAR)printf("\tSomething's wrong!--&\tline:%d\tt=t_%d\n",line,t);
											$$=createtree(t,$2->num,$2->str,nt_APTR,NULL,NULL,NULL,LLookup($2->str),NULL);}}
			;
%%

void check(struct tnode *t){
	if(LLookup(t->str)==NULL && GLookup(t->str)==NULL){
		printf("Undeclared identifier:'%s' at line:'%d'\n",t->str,line);
		exit(1);}
}

void yyerror(char const *s)
{
	printf("yyerror %s\nLine:%d at '%s'\n",s,line,yytext);
	exit(1);
}

void func(struct Paramstruct* phead){
	struct Paramstruct* temp=phead;
	while(temp!=ptail){
		printf("name:'%s'\ttype:'%d'\t\n",temp->name,temp->type);
		temp=temp->next;}
}

void other(){
	printf("\t\tGlobal Table\n");
	struct Gsymbol* gtemp=ghead;
	while(gtemp!=gtail){
		printf("name:'%s'\ttype:'%d'\tsize:'%d'\tarr:%d\n",gtemp->name,gtemp->type,gtemp->size,gtemp->arr);
		gtemp=gtemp->next;}
	printf("\t\tLocal Table\n");
	struct Lsymbol* ltemp=lhead;
	while(ltemp!=NULL){
		printf("name:'%s'\ttype:'%d'\tbinding:'%d'\n",ltemp->name,ltemp->type,ltemp->binding);
		ltemp=ltemp->next;}
}

void n(int n){printf("~~~%d~~~\n",n);}
void c(char c){printf("~~~%c~~~\n",c);}
void s(char *s){printf("~~~%s~~~\n",s);}

int main(void)
{
	ghead=malloc(sizeof(struct Gsymbol));
	gtail=ghead;

	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else
		printf("Input file error\n");
	target_file=fopen("intermediate.xsm","w+");
	GInstall("main",t_INT,0);
	GLookup("main")->flabel=1000;
	yyparse();

//	other();
	return 0;
}

