%{
//#define exit(a); exit(a);
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#define YYSTYPE tnode *
	#include "expr.c"
	#include "lex.yy.c"
	int yydebug=0;
	FILE *yyin;
	int reg;
	int mainflag=0,equiv=0,tuplesize=0,typesize=0,fieldindex,initflag=0,allocflag=0;
	struct Typetable *type,*temptype,*t;
	char *tuplename;
	int tint=1,ttint=1;
	struct Classtable *ctemp,*Cptr;
	char *typename;
	int cflag;
%}
%error-verbose

//tokens
	%token NUM ID STRING
	%token PLUS MINUS MUL DIV MOD EQ
	%token INC DEC
	%token BEG END
	%token READ WRITE
	%token IF THEN ELSE ENDIF
	%token TRUE FALSE NOT
	%token WHILE DO ENDWHILE
	%token BREAK CONTINUE
	%token REPEAT UNTIL
	%token TYPE ENDTYPE DECL ENDDECL
	%token INT STR TUPLE
	%token MAIN RETURN BRKP EXIT
	%token AND OR
	%token INIT ALLOC FREE NUL
	%token CLASS ENDCLASS EXTENDS NEW DELETE SELF
	%left AND OR
	%right NOT
	%left PLUS MINUS
	%left MUL DIV MOD
	%nonassoc LT LE GT GE EE NE
%%
//-------------------------------------------------------------------------start
	start		:Program;
	Program		:TDeclBlock CDefBlock GDeclBlock FDefBlock MainBlock		{printf("Syntax Matched\n");}
				;
//-------------------------------------------------------------------------type
	TDeclBlock	:TYPE TStructs ENDTYPE					{tprint();}
				|
				;
	TStructs	:TStructs TStruct
				|TStruct;
	TStruct		:ID '{' {TInstall($1->str,0,NULL);
						fhead=NULL;
						fieldindex=0;
						typesize=0;}
						TFields  '}' 	{TLookup($1->str)->fields=fhead;
										TLookup($1->str)->size=typesize;}
				;
	TFields		:TFields TField			{}			
				|//TField					{}	
				;
	TField		:Type VList ';'
				;
	VList		:VList ',' Vid 
				|Vid;
	Vid			:ID		{FInstall($1->str,fieldindex++,type);typesize++;}	
				|ID '(' {phead=NULL;
						temptype=type;} 
						ParamList {type=temptype;}
									')'	{	GInstall($1->str,type,0);//-------------------------------------------------------
											GLookup($1->str)->paramlist=phead;
											GLookup($1->str)->flabel=flabel++;}	
				;
//-------------------------------------------------------------------------class
	CDefBlock	:CLASS {cflag=1;}	CDefList {cflag=0;}	ENDCLASS				{cprint();}
				|
				;
	CDefList 	:CDefList CDef
				|//CDef
				;
	CDef		:Cname '{'	{CFieldindex=0;
							Funcposition=0;
							ghead=NULL;}
							DECL Fieldlists MethodDecl	{chead->MemberFunc=cmhead;
														chead->MemberField=cfhead;} ENDDECL MethodDefns '}'
				;
	Cname		:ID				{Cptr = CInstall($1->str,NULL);}		
				|ID EXTENDS ID	{Cptr = CInstall($1->str,CLookup($3->str));}
				;
	Fieldlists 	:Fieldlists Flist
				|
				;	
	Flist		:Type Cid ';' 
				;
	Cid			:Cid ',' ID			{Class_Finstall(Cptr,typename,$3->str);}
				|ID					{Class_Finstall(Cptr,typename,$1->str);}
				;
	MethodDecl 	:MethodDecl MDecl
				|MDecl//----------needed
				;
	MDecl		:Type ID '(' {phead=NULL;}
							ParamList ')' ';' 	{Class_Minstall(Cptr,$2->str,TLookup($1->str),phead);
												GInstall($2->str,type,0);//-------------------------------------------------------
												GLookup($2->str)->paramlist=phead;
												GLookup($2->str)->flabel=flabel++;}
				;
	MethodDefns :MethodDefns FDef
				|//FDef
				;
//-------------------------------------------------------------------------global
	GDeclBlock	:DECL GDeclList ENDDECL 	{generate();gprint();}
				|			 				{generate();printf("No Globals declared!\n");}
				;
	GDeclList	:GDeclList GDecl			{}
				|GDecl						{};
	GDecl		:Type GidList ';'			{};
	Type		:ID							{	type=TLookup($1->str);
												typename=strdup($1->str);
												if(type==NULL){
													printf("line:'%d'\tundeclared type:'%s'\n",line,$1->str);
													exit(1);}
												//$$=$1;
												};
	GidList		:GidList ',' Gid
				|Gid;
	Gid			:ID										{if(strcmp(type->name,"void")==0 ||strcmp(type->name,"null")==0){
															printf("line:'%d'\tSorry, you cant declare that type...!\n",line);
															exit(1);}
														else
															GInstall($1->str,type,1);}
				|ID '[' NUM ']'							{GInstall($1->str,type,$3->num);}
				|ID '(' {phead=NULL;temptype=type;}
						ParamList {type=temptype;}
									')'	{	GInstall($1->str,type,0);//-------------------------------------------------------
											GLookup($1->str)->paramlist=phead;
											GLookup($1->str)->flabel=flabel++;}
				|MUL ID	'('	 {phead=NULL;temptype=type;}
							ParamList {type=temptype;}
										')'	{	t=type;
												if(strcmp(type->name,"int")==0)
													type=TLookup("intptr");
												else if(strcmp(type->name,"str")==0)
													type=TLookup("strptr");
												else{
													printf("line:'%d'\tpointer to neither int nor str for id:'%s'\n",line,$2->str);
													exit(1);}
												GInstall($2->str,type,0);
												GLookup($2->str)->paramlist=phead;
												GLookup($2->str)->flabel=flabel++;type=t;}
				;
//-------------------------------------------------------------------------functions
	FDefBlock	:FDefBlock FDef
				|FDef
				;
				//Type ID '(' ParamList ')' '{' LDeclBlock Body '}'
	FDef		:Type ID '(' {	checkid($2);
								funcname=$2->str;
								binding=-2;
								printf("\tDeallocating ltable...\n");
								ldealloc(lhead);
								printf("~~~~~~~~~~~~~~~~~~~~~~\n");
								lhead=NULL;
								phead=NULL;
								equiv=1;
								ttint=1;}//-------------------------------------------------------------------
							ParamList ')' {	equiv=0;
											struct Lsymbol *ltemp;
											struct Paramstruct *ptemp;
											ptemp=GLookup($2->str)->paramlist;
											ltemp=lhead;
											while(ptemp && ltemp){
												if(ptemp->type!=ltemp->type ||strcmp(ptemp->name,ltemp->name)!=0){//----------------------------------------------
													printf("line:%d\nParameter Globally Declared:\tname:'%s'\ttype:'%s'\nParameter Locally Declared:\tname:'%s'\ttype:'%s'\n",line,ptemp->name,ptemp->type->name,ltemp->name,ltemp->type->name);
													exit(1);}
												ptemp=ptemp->next;
												ltemp=ltemp->next;}
											if(ptemp!=NULL ||ltemp!=NULL){
												if(ptemp!=NULL){
													printf("line:%d\tExtra Global Parameters Declared...\n",line);
													while(ptemp!=NULL){
														printf("name:'%s'\ttype:'%s'\n",ptemp->name,ptemp->type->name);
														ptemp=ptemp->next;}}
												else{
													printf("line:%d\tExtra Local Parameters Declared...\n",line);
													while(ltemp!=NULL){
														printf("name:'%s'\ttype:'%s'\n",ltemp->name,ltemp->type->name);
														ltemp=ltemp->next;}}
												exit(1);}}
										 '{' {	binding=0;}
												LDeclBlock {lprint();initflag=allocflag=0;tint=1;}
															Body '}' ;
//-------------------------------------------------------------------------param
	ParamList	:ParamList ',' Param			{}
				|Param
				|/*param can be empty*/;
	Param		:Type Pid;
	Pid			:ID			{if(equiv==1){
								binding--;
								LInstall($1->str,type);}
							else
								PInstall($1->str,type);}
				|MUL ID		{if(equiv==1){
								binding--;
								t=type;
								if(strcmp(type->name,"int")==0)
									type=TLookup("intptr");
								else if(strcmp(type->name,"str")==0)
									type=TLookup("strptr");
								else{
									printf("line:'%d'\tpointer to neither int nor str for id:'%s'\n",line,$2->str);
									exit(1);}
								LInstall($2->str,type);
								type=t;}
							else{
								t=type;
								if(strcmp(type->name,"int")==0)
									type=TLookup("intptr");
								else if(strcmp(type->name,"str")==0)
									type=TLookup("strptr");
								else{
									printf("line:'%d'\tpointer to neither int nor str for id:'%s'\n",line,$2->str);
									exit(1);}
								PInstall($2->str,type);
								type=t;}}
				;
//-------------------------------------------------------------------------local
	LDeclBlock	:DECL LDecList ENDDECL
				|DECL ENDDECL
				|
				;
	LDecList	:LDecList LDecl
				|LDecl;
	LDecl		:Type IdList ';';
	IdList		:IdList ',' Lid
				|Lid;
	Lid			:ID				{binding+=1;LInstall($1->str,type);};
//-------------------------------------------------------------------------main
	MainBlock 	:MAIN '(' ')' '{' {		binding=0;
										funcname="main";
										printf("\tDeallocating ltable...\n");
										ldealloc(lhead);
										printf("~~~~~~~~~~~~~~~~~~~~~~\n");
										lhead=NULL;
										binding=0;
										GLookup("main")->type=TLookup("int");}
									LDeclBlock {lprint();initflag=allocflag=0;}
												Body '}' {ldealloc(lhead);}
				;
//-------------------------------------------------------------------------body
	//struct tnode* createtree(struct Typetable *type, int num,char *str,int nt, struct tnode *l, struct tnode *r,struct tnode *d,struct Gsymbol *gentry,struct tnode *ArgList,struct Lsymbol *lentry);
	Body		:BEG Slist RETURN Expr ';' END 	{//$$=$2;
												struct tnode *ret=createtree(GLookup(funcname)->type,0,NULL,nt_RET,NULL,$4,NULL,NULL,NULL,NULL);
												struct tnode *body=createtree(TLookup("void"),0,NULL,nt_NODE,$2,NULL,ret,NULL,NULL,NULL);
												funcGen(GLookup(funcname));
												if(allocflag>0 && initflag==0){//--------------main:init other:alloc???
													printf("Using ALLOC without INIT... You may run into something...!\n");}
												printf("CodeGen-ing '%s'\n",funcname);
												codeGen(body);
												printf("Finished CodeGen-ing of '%s'\n",funcname);
												printf("\tDeallocating BODY...\n");
												bdealloc(body);
												printf("~~~~~~~~~~~~~~~~~~~~~~\n");
												printf("################################################################################################\n");}
				|BEG RETURN Expr ';' END 		{struct tnode *ret=createtree(GLookup(funcname)->type,0,NULL,nt_RET,NULL,$4,NULL,NULL,NULL,NULL);
												funcGen(GLookup(funcname));
												printf("CodeGen-ing '%s'\n",funcname);
												codeGen(ret);
												printf("Finished CodeGen-ing of '%s'\n",funcname);
												printf("\tDeallocating BODY...\n");
												bdealloc(ret);
												printf("~~~~~~~~~~~~~~~~~~~~~~\n");
												printf("################################################################################################\n");};
	Slist		:Slist Stmt				{$$=createtree(TLookup("void"),0,NULL,nt_NODE,$1,NULL,$2,NULL,NULL,NULL);}
				|Stmt					{$$=$1;}
				;
	Stmt		:READ '(' id ')' ';'								{$$=createtree(TLookup("void"),0,NULL,nt_READ,NULL,$3,NULL,NULL,NULL,NULL);}
				|WRITE '(' Expr ')' ';'								{$$=createtree(TLookup("void"),0,NULL,nt_WRITE,NULL,$3,NULL,NULL,NULL,NULL);}
				|WRITE STRING ';'									{$$=createtree(TLookup("void"),0,NULL,nt_WRITE,NULL,$2,NULL,NULL,NULL,NULL);}
				|IF '(' Bool ')' THEN Slist ELSE Slist ENDIF ';'	{$$=createtree(TLookup("void"),0,NULL,nt_IFELSE,$3,$6,$8,NULL,NULL,NULL);}
				|IF '(' Bool ')' THEN Slist ENDIF ';'				{$$=createtree(TLookup("void"),0,NULL,nt_IF,$3,NULL,$6,NULL,NULL,NULL);}
				|WHILE '(' Bool ')' DO Slist ENDWHILE ';'			{$$=createtree(TLookup("void"),0,NULL,nt_WHILE,$3,NULL,$6,NULL,NULL,NULL);}
				|REPEAT Slist UNTIL '(' Bool ')' ';'				{$$=createtree(TLookup("void"),0,NULL,nt_WHILE,$5,NULL,$2,NULL,NULL,NULL);}
				|DO Slist WHILE '(' Bool ')' ';'					{$$=createtree(TLookup("void"),0,NULL,nt_WHILE,$5,NULL,$2,NULL,NULL,NULL);}
				|BREAK ';'											{$$=createtree(TLookup("void"),0,NULL,nt_BREAK,NULL,NULL,NULL,NULL,NULL,NULL);}
				|CONTINUE ';'										{$$=createtree(TLookup("void"),0,NULL,nt_CONTINUE,NULL,NULL,NULL,NULL,NULL,NULL);}
				|BRKP ';'											{$$=createtree(TLookup("void"),0,NULL,nt_BRKP,NULL,NULL,NULL,NULL,NULL,NULL);}
				|EXIT ';'											{$$=createtree(TLookup("void"),0,NULL,nt_EXIT,NULL,NULL,NULL,NULL,NULL,NULL);}
				|INIT '(' ')' ';'									{$$=createtree(TLookup("void"),0,NULL,nt_INIT,NULL,NULL,NULL,NULL,NULL,NULL);initflag++;}
				|id EQ Expr ';'										{$$=createtree(TLookup("void"),0,NULL,nt_ASGN,$1,NULL,$3,NULL,NULL,NULL);}
				|id EQ ALLOC '(' ')' ';'							{$$=createtree(TLookup("void"),GetSize(TLookup($1->str)),NULL,nt_ALLOC,NULL,$1,NULL,NULL,NULL,NULL);allocflag++;}//---------------------------------
				|FREE '(' id ')' ';'								{$$=createtree(TLookup("void"),0,NULL,nt_FREE,NULL,$3,NULL,NULL,NULL,NULL);}
				|Field EQ Expr ';'									{$$=createtree(TLookup("void"),0,NULL,nt_ASGN,NULL,$1,NULL,NULL,NULL,NULL);}
				|id EQ NEW '(' id ')' ';'							{$$=createtree(TLookup("void"),0,NULL,nt_NEW,$1,NULL,$5,NULL,NULL,NULL);}
				|DELETE '(' Field ')' ';'							{$$=createtree(TLookup("void"),0,NULL,nt_DELETE,NULL,$3,NULL,NULL,NULL,NULL);}
				;
	Expr		:'(' Expr ')'					{$$=$2;}
				|id								{$$=$1;}
				|NUM							{$$=$1;}
				|STRING							{$$=$1;}
				|NUL							{$$=$1;}
				|Expr PLUS Expr					{$$=createtree(TLookup("int"),0,NULL,nt_PLUS,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr MINUS Expr				{$$=createtree(TLookup("int"),0,NULL,nt_MINUS,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr MUL Expr					{$$=createtree(TLookup("int"),0,NULL,nt_MUL,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr DIV Expr					{$$=createtree(TLookup("int"),0,NULL,nt_DIV,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr MOD Expr					{$$=createtree(TLookup("int"),0,NULL,nt_MOD,$1,NULL,$3,NULL,NULL,NULL);}
				|ID '(' ')'						{checkid($1);$$=createtree(GLookup($1->str)->type,0,$1->str,nt_FUNC,NULL,NULL,NULL,GLookup($1->str),NULL,NULL);}
				|ID '(' ArgList ')'				{checkid($1);$$=createtree(GLookup($1->str)->type,0,$1->str,nt_FUNC,NULL,NULL,NULL,GLookup($1->str),$3,NULL);}
				|SELF '.' ID '(' ArgList ')'	{if(cflag!=0){printf("Not in class\n");exit(1);}
												struct CFieldlist *cf=Class_FLookup(chead,$3->str);
												$$=createtree(cf->type,0,$3->str,nt_SELFFUNC,NULL,NULL,NULL,NULL,NULL,NULL);$$->cfield=cf;}
				|ID '.' ID '(' ArgList ')'		{if(cflag==0){printf("In class\n");exit(1);}
												struct CFieldlist *cf=Class_FLookup(chead,$3->str);
												$$=createtree(cf->type,0,$3->str,nt_SELF,NULL,NULL,NULL,NULL,NULL,NULL);$$->cfield=cf;}
				;
	ArgList		:ArgList ',' Expr		{$3->down=$1;$$=$3;}
				|Expr					{$$=$1;};
	Bool		:Expr LT Expr			{$$=createtree(TLookup("bool"),0,NULL,nt_LT,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr LE Expr			{$$=createtree(TLookup("bool"),0,NULL,nt_LE,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr GT Expr			{$$=createtree(TLookup("bool"),0,NULL,nt_GT,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr GE Expr			{$$=createtree(TLookup("bool"),0,NULL,nt_GE,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr EE Expr			{$$=createtree(TLookup("bool"),0,NULL,nt_EE,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr NE Expr			{$$=createtree(TLookup("bool"),0,NULL,nt_NE,$1,NULL,$3,NULL,NULL,NULL);}
				|TRUE					{$$=createtree(TLookup("bool"),0,NULL,nt_TRUE,NULL,NULL,NULL,NULL,NULL,NULL);}
				|FALSE					{$$=createtree(TLookup("bool"),0,NULL,nt_FALSE,NULL,NULL,NULL,NULL,NULL,NULL);}
				|'(' Bool ')'			{$$=$2;}
				|NOT Bool				{$$=createtree(TLookup("bool"),0,NULL,nt_NOT,NULL,$2,NULL,NULL,NULL,NULL);}
				|Bool AND Bool			{$$=createtree(TLookup("bool"),0,NULL,nt_AND,$1,NULL,$3,NULL,NULL,NULL);}
				|Bool OR Bool			{$$=createtree(TLookup("bool"),0,NULL,nt_OR,$1,NULL,$3,NULL,NULL,NULL);}
				;
//-------------------------------------------------------------------------id
	//struct tnode* createtree(struct Typetable *type, int num,char *str,int nt, struct tnode *l, struct tnode *r,struct tnode *d,struct Gsymbol *gentry,struct tnode *ArgList,struct Lsymbol *lentry);
	id			:ID							{checkid($1);
											$$=createtree(LLookup($1->str)==NULL?GLookup($1->str)->type:LLookup($1->str)->type,0,$1->str,nt_ID,NULL,NULL,NULL,GLookup($1->str),NULL,LLookup($1->str));}
				|ID '[' Expr ']'			{checkid($1);$$=createtree(LLookup($1->str)==NULL?GLookup($1->str)->type:LLookup($1->str)->type,0,$1->str,nt_ARR,NULL,$3,NULL,GLookup($1->str),NULL,LLookup($1->str));}
				/*|ID '[' NUM ']' '[' NUM ']'	{checkid($1);
											$$=createtree(TLookup($1->str),(GLookup($1->str)->arr)*($3->num)+($6->num),$1->str,nt_ID,NULL,NULL,NULL,GLookup($1->str),NULL,LLookup($1->str));}*/
				|MUL id						{$$=createtree(GLookup($2->str)->type,$2->num,$2->str,nt_SPTR,NULL,NULL,NULL,GLookup($2->str),NULL,LLookup($1->str));}
				|'&' id						{$$=createtree(GLookup($2->str)->type,$2->num,$2->str,nt_APTR,NULL,NULL,NULL,GLookup($2->str),NULL,LLookup($1->str));}
				/*|ID'.'ID					{checkid1($1,$3);
											struct	Paramstruct *ptemp=GLookup($1->str)->paramlist;
											int t,count=0;
											while(ptemp){
												if(strcmp(ptemp->name,$3->str)==0){
														t=ptemp->type;}
												count++;
												ptemp=ptemp->next;}
											$$=createtree(t,GLookup($1->str)->size-count,$3->str,nt_ID,NULL,NULL,NULL,GLookup($1->str),NULL,NULL);}*/
				|Field						{$$=$1;$$->nt=nt_USERROOT;}
				|SELF '.' ID				{if(cflag==0){printf("In class\n");exit(1);}
															struct CFieldlist *cf=Class_FLookup(chead,$3->str);
															$$=createtree(cf->type,0,$3->str,nt_SELF,NULL,NULL,NULL,NULL,NULL,NULL);$$->cfield=cf;}	
				;
	Field		:Field '.' ID 				{struct Typetable *ttemp=$1->t;
											checktype(ttemp,$3->str);
											struct Fieldlist *ftemp=FLookmember(ttemp,$3->str);
											$$=createtree(ftemp->type,ftemp->fieldIndex,$3->str,nt_USERNODE,$1,NULL,NULL,$1->Gentry,NULL,$1->Lentry);}
				|ID '.' ID					{checkid($1);
											struct Typetable *ttemp=LLookup($1->str)==NULL?GLookup($1->str)->type:LLookup($1->str)->type;
											struct Fieldlist *ftemp=FLookup(ttemp,$3->str);
											checktype(ttemp,$3->str);
											struct tnode *node=createtree(ttemp,0,$1->str,nt_USERNODE,NULL,NULL,NULL,GLookup($1->str),NULL,LLookup($1->str));
											$$=createtree(ftemp->type,ftemp->fieldIndex,$3->str,nt_USERNODE,node,NULL,NULL,GLookup($1->str),NULL,LLookup($1->str));}
				|Field '.' ID '(' ArgList ')'	{if(cflag!=0){printf("Not in class\n");exit(1);}
												struct CFieldlist *cf=Class_FLookup(chead,$3->str);
												$$=createtree(cf->type,0,$3->str,nt_SELF,NULL,NULL,NULL,NULL,NULL,NULL);$$->cfield=cf;}
				;

%%
void checkid(struct tnode *t){
	if(LLookup(t->str)==NULL && GLookup(t->str)==NULL){
		printf("Undeclared identifier:'%s' at line:'%d'\n",t->str,line);
		exit(1);}}
void checktype(struct Typetable *t1, char *member){
	if(FLookmember(t1,member)==NULL){
		printf("line:'%d'\tUndeclared type with name:'%s' in type:'%s'\n",line,member,t1->name);
		exit(1);
	return;}}
void yyerror(char const *s){
	printf("yyerror %s\nLine:%d at '%s'\n",s,line,yytext);
	if(strcmp(yytext,"end")==0)
		printf("Did you use a return statement...!\n");
	exit(1);}
void tprint(){
	printf("\t\tType Declarations\n");
	struct Typetable *ttemp;
	struct Fieldlist *ftemp;
	ttemp=thead;
	while(ttemp){
		printf("name:'%s'\tsize:'%d'\n",ttemp->name,ttemp->size);
		ftemp=ttemp->fields;
		if(ftemp)
			printf("\tFields...\n");
		while(ftemp){
			if(ftemp->type!=NULL)
				printf("\tname:'%s'\tfieldIndex:'%d'\ttype:'%s'\n",ftemp->name,ftemp->fieldIndex,ftemp->type->name);
			ftemp=ftemp->next;}
		ttemp=ttemp->next;}
	printf("######################################################\n");}
void gprint(){
	int i,j;
	printf("\t\tGlobal Table(Static size:'%d')\n",gbinding-4096);
	struct Gsymbol* gtemp=ghead;
	struct Paramstruct* ptemp;
	printf("GLOBALS...\n");
	i=1;
	while(gtemp!=NULL){
		if(gtemp->size>0){
			printf("%d.name:'%s'\ttype:'%s'\tsize:'%d'\tbase:'%d'\tarr:%d\n",i++,gtemp->name,gtemp->type->name,gtemp->size,gtemp->binding,gtemp->arr);
		if(gtemp->paramlist){
			ptemp=gtemp->paramlist;
			printf("\tContent of type...\n");
			while(ptemp){
				printf("\tname:'%s'\ttype:'%s'\n",ptemp->name,ptemp->type->name);
				ptemp=ptemp->next;}}
			if(gtemp->paramlist)
				printf("\n");}
		gtemp=gtemp->next;}
	gtemp=ghead;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("functions\n");
	i=1;
	while(gtemp!=NULL){
		if(gtemp->size==0 && gtemp->flabel!=1000){
			printf("%d.name:'%s'\ttype:'%s'\tflabel:'%d'\n",i++,gtemp->name,gtemp->type->name,gtemp->flabel);
			ptemp=gtemp->paramlist;
			printf("\tparameters\n");
			j=1;
			while(ptemp){
				printf("\t%d.name:'%s'\ttype:'%s'\n",j,ptemp->name,ptemp->type->name);
				ptemp=ptemp->next;}
			printf("\n");}
		gtemp=gtemp->next;}
	printf("######################################################\n");}
void lprint(){
	int i;
	printf("\t\tLocal Table('%s')\n",funcname);
	int count=0;
	struct Lsymbol* ltemp=lhead;
	printf("LOCALS...\n");
	i=1;
	while(ltemp!=NULL){
		count++;
		printf("%d.name:'%s'\ttype:'%s'\tbinding:'%d'\n",i++,ltemp->name,ltemp->type->name,ltemp->binding);
		if(ltemp->binding==1){printf("\narguments\n");i=1;}
		ltemp=ltemp->next;}
	printf("######################################################\n");}
void cprint(){
	}
void ldealloc(struct Lsymbol *lhead){
	if(lhead==NULL)
		return;
	printf("%d.funcname:'%s'\tname:'%s'\n",ttint++,funcname,lhead->name);
	ldealloc(lhead->next);
	free(lhead->next);}
void bdealloc(struct tnode *body){
	if(body==NULL)
		return;
	printf("%d.funcname:'%s'\tnt:'%d'\n",tint++,funcname,body->nt);
	bdealloc(body->left);
	free(body->left);
	bdealloc(body->down);
	free(body->down);
	bdealloc(body->right);
	free(body->right);}
int main(){
	ghead=NULL;
	phead=NULL;
	lhead=NULL;
	cfhead=NULL;
	chead=NULL;
	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else{
		printf("Input file error\n");
		exit(1);}
	target_file=fopen("intermediate.xsm","w+");//comment for consoling
	GInstall("main",TLookup("int"),0);
	GLookup("main")->flabel=1000;
	TypeTableCreate();
	yyparse();
	//print();
	return 0;}
//

