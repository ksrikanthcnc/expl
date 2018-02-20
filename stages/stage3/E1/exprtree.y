%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <signal.h>
	#define YYSTYPE tnode *
	#include "exprtree.h"
	#include "exprtree.c"
	#include "lex.yy.c"
	int yylex(void);
	yydebug=0;
%}

%token NUM ID
%token PLUS MINUS MUL DIV EQ 
%nonassoc LT GT LE GE NE EE
%token BEG END READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE ';'
%left PLUS MINUS
%left MUL DIV EQ

%%

start	:BEG Slist END ';'	{puts("\t\tSyntax matched");return $2;}
		|BEG END	';'		{return NULL;}
		;

Slist	:Slist Stmt		{$$= createTree($1,$2);}
		|Stmt 			{$$= $1;}
		;

Stmt	:InputStmt 		{$$=$1;}
		|OutputStmt 	{$$=$1;}
		|AsgStmt 		{$$=$1;}
		|Ifstmt			{$$=$1;}
		|Whilestmt		{$$=$1;}
		;
		
InputStmt	:READ '(' ID ')' ';'	{$$ = makeFunc("read",$3);}
			;

OutputStmt	:WRITE '(' E ')' ';'	{$$ = makeFunc("write",$3);}
			;
			
AsgStmt		:ID EQ E ';'	{op1($1);op1($3);$$ = makeOperatorNode("=",$1,$3);}
			;

Ifstmt	: IF '(' E ')' THEN Slist ELSE Slist ENDIF ';'	{boo($3);$$=threeTree($3,$6,$8,"ifelse");}
		| IF '(' E ')' THEN Slist ENDIF ';'				{boo($3);$$=twoTree($3,$6,"if");}
		;

Whilestmt	: WHILE '(' E ')' DO Slist ENDWHILE ';'		{boo($3);$$=twoTree($3,$6,"while");}
			;

E	:E PLUS E 	{$$ = makeOperatorNode("+",$1,$3);op($$);}
	|E MINUS E  {$$ = makeOperatorNode("-",$1,$3);op($$);}
	|E MUL E 	{$$ = makeOperatorNode("*",$1,$3);op($$);}
	|E DIV E 	{$$ = makeOperatorNode("/",$1,$3);op($$);}
	|'(' E ')'	{$$ = $2;}
	|ID			{$$ = $1;}
	|NUM		{$$ = $1;}
	|E LT E 	{$$ = makeOperatorNode("<",$1,$3);boo($$);}
	|E GT E 	{$$ = makeOperatorNode(">",$1,$3);boo($$);}
	|E LE E  	{$$ = makeOperatorNode("<=",$1,$3);boo($$);}
	|E GE E  	{$$ = makeOperatorNode(">=",$1,$3);boo($$);}
	|E NE E  	{$$ = makeOperatorNode("!=",$1,$3);boo($$);}
	|E EE E 	{$$ = makeOperatorNode("==",$1,$3);boo($$);}
	;

%%

yyerror(char const *s)
{
	printf("yyerror %s\n",s);
	exit(0);
}

op1(struct tnode *t){
	if(t->type=='i' || t->type=='c' || t->type=='a'){
		return;
	}
	else{
		puts("type mismatch-op1");
		printf("type:%c\n",t->type);
		exit(1);
	}
}

op(struct tnode *t){
	if((t->left->type=='i' || t->left->type=='c') && (t->right->type!='i' || t->right->type!='c')){
		return ;
	}
	else{
		puts("type mismatch-op");
		printf("left:%c\n",t->left->type);
		printf("right:%c\n",t->right->type);
		exit(1);
	}
		
}

boo(struct tnode *t){
	if(t->type=='b'){
		return;
	}
	else{
		puts("type mismatch-bool");
		printf("type:%c\n",t->type);
		exit(1);
	}
}

int main(){
	evaluate(yyparse());
	return 1;
}
