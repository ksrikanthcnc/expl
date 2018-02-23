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
%left PLUS MINUS
%left MUL DIV MOD
%nonassoc LT LE GT GE EE NE

%%

start			:Declarations 		{printf("Syntax Matched\n");
								//		if($2==NULL){puts("Nothing to execute :)");}
									//	generate($2,target_file);
										};

Declarations	:DECL DeclList ENDDECL ';'	{other();}
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

Varlist			:Varlist ',' Gid
				|Gid
				;
Gid			:ID										{Install($1->str,type,1);}
			|ID '[' NUM ']'							{int t=type;type=type==t_INT?t_INARR:t_CHARR;Install($1->str,type,$3->num);type=t;}
			|ID '[' NUM ']' '[' NUM ']'				{int t=type;type=type==t_INT?t_INARR:t_CHARR;Install($1->str,type,$3->num*$6->num);type=t;Lookup($1->str)->arr=$3->num;}
			|MUL ID									{int t=type;type=type==t_INT?t_INPTR:t_CHPTR;Install($2->str,type,1);type=t;}
			|ID '(' ParamList ')'					{Install($1->str,type,0);}
			;
ParamList	:ParamList ',' Param
			|Param
			| /*param can be empty*/
			;

Param		:Type ID
			;

id			:ID							{check($1);
										int t=Lookup($1->str)->type,nt;
										if(t==t_INPTR || t==t_CHPTR){t=t==t_INPTR?t_INT:t_CHAR;nt=nt_PTR;}
										else nt=nt_ID;
										$$=createtree(t,NULL,$1->str,nt,NULL,NULL,NULL,Lookup($1->str));}
			|ID '[' NUM ']'				{check($1);
										int t=Lookup($2->str)->type;
										if(t!=t_INARR && t!=t_CHARR)printf("\tSomething's wrong!--arr[1D]\tline:%d\tt=t_%d\n",line,t);
										t=t==t_INARR?t_INT:t_CHAR;
										$$=createtree(t,$3->num,$1->str,nt_ARR,NULL,NULL,NULL,Lookup($1->str));}
			|ID '[' NUM ']' '[' NUM ']'	{check($1);
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

void check(struct tnode *t){
	if(Lookup(t->str)==NULL){
		printf("Undeclared identifier:%s\n",t->str);
		exit(1);}
}

void yyerror(char const *s)
{
	printf("yyerror %s\nLine:%d at '%s'\n",s,line,yytext);
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

