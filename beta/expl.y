%{
	#define YYSTYPE tnode *
	#define INCL
	#include "headers.h"
	#include "astree.c"
	#include "codegen.c"
	#include "lex.yy.c"
	int yydebug=0;
	FILE *yyin;
	int reg;
	int mainflag=0,tolocal=0,tuplesize=0,typesize=0,genflag=1;
	struct Typetable *type,*temptype,*t;
	char *tuplename;
	int tint=1,ttint=1;
	struct Classtable *class;
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
	Program		:TDeclBlock CDeclBlock GDeclBlock FDefBlock MainBlock		{printf("\n\n\n\nSyntax Matched\n");}
				;
//-------------------------------------------------------------------------type
	TDeclBlock	:TYPE TStructs ENDTYPE			{tprint();}
				|;
	TStructs	:TStructs TStruct
				|;
	TStruct		:ID '{' 						{TInstall($1->str,0,NULL);fhead=NULL;fieldindex=0;typesize=0;}
						TFields  '}' 			{TLookup($1->str)->fields=fhead;TLookup($1->str)->size=typesize;}
				;
	TFields		:TFields TField
				|TField
				;
	TField		:Type 						{type=TLookup($1->str);
											if(type==NULL){
												printf("line:'%d'\ttype:'%s' undeclared\n",line,$1->str);
												exit(1);}}
						VList ';'
				;
	VList		:VList ',' Vid
				|Vid;
	Vid			:ID			{FInstall($1->str,fieldindex++,type);typesize++;}
				;
//-------------------------------------------------------------------------class
	CDeclBlock	:CLASS {classflag=1;}	CDefList	{classflag=0;}	 ENDCLASS		{cprint();}
				|;
	CDefList	:CDefList CDef
				|CDef;
	CDef		:Cname '{' DECL Fieldlists MethodDecl ENDDECL 	{CLookup($1->str)->memberfield=fhead;
							 									CLookup($1->str)->memberfunc=mhead;}
							 									MethodDefns '}'	{if(class->fieldcount>7) {printf("line:'%d'\t>7 fields declared in class:'%s'\n",line,$1->str); exit(1);}
							 													if(class->methodcount>7) {printf("line:'%d'\t>7 methods declared in class:'%s'\n",line,$1->str);exit(1);}
							 													class->fieldcount=fieldcount;
							 													class->methodcount=methodcount;
																				fhead=NULL;mhead=NULL;funcposition=0;fieldindex=0;gbinding+=8;fieldcount=methodcount=0;}
				;
	Cname		:ID					{class=CInstall($1->str,NULL);$$=$1;}
				|ID EXTENDS ID		{struct Classtable *parent=CLookup($3->str);
									struct Classtable *new=malloc(sizeof(struct Classtable));
									new->name=$1->str;
									if(parent==NULL){
										printf("line:'%d'\tNo parent class:'%s' to extend from\n",line,$3->str);
										exit(1);}
									fhead=new->memberfield=parent->memberfield;
									if(fhead!=NULL){
										fieldindex=fhead->fieldindex;fieldindex++;}
									else{
										fieldindex=0;
									}
									mhead=new->memberfunc=parent->memberfunc;
									if(mhead!=NULL){
										funcposition=mhead->funcposition;funcposition++;}
									else{
										funcposition=0;
									}
									new->parent=parent;
									new->index=cindex++;
									fieldcount=new->fieldcount=parent->fieldcount;
									methodcount=new->methodcount=parent->methodcount;
									new->next=chead;
									chead=new;
									class=new;
									$$=$1;}
				;
	Fieldlists	:Fieldlists Fld
				|;
	Fld			:ID ID ';'		{CFInstall($1->str,$2->str);fieldcount++;}
				;
	MethodDecl	:MethodDecl MDecl
				|MDecl;
	MDecl		:ID ID '(' 	{phead=NULL;}
							ParamList ')' ';'	{CMInstall($2->str,TLookup($1->str),phead);methodcount++;
												if(class->parent!=NULL && CMLookup(class->parent,$2->str)!=NULL){
													funcposition--;
													methodcount--;
													mhead->funcposition=CMLookup(class->parent,$2->str)->funcposition;
												}}
				;
	MethodDefns	:MethodDefns FDef
				|FDef;
//-------------------------------------------------------------------------global
	GDeclBlock	:DECL GDeclList ENDDECL 	{gprint();}
				|			 				{printf("No Globals declared!\n");}
				;
	GDeclList	:GDeclList GDecl
				|							;
	GDecl		:Type GidList ';'			;
	Type		:ID							{	type=TLookup($1->str);
												ctype=CLookup($1->str);
												if(type==NULL && ctype==NULL){
													printf("line:'%d'\tno type or class:'%s'\n",line,$1->str);
													exit(1);}
												$$=$1;};
	GidList		:GidList ',' Gid
				|Gid;
	Gid			:ID										{if(type!=NULL){//type
															if(strcmp(type->name,"void")==0 || strcmp(type->name,"null")==0){
																	printf("line:'%d'\tSorry, you cant declare that type...!\n",line);
																	exit(1);}
															GInstall($1->str,type,1);}
														else{//class
															GInstall($1->str,NULL,2);
															GLookup($1->str)->class=ctype;}}
				|ID '[' NUM ']'							{GInstall($1->str,type,$3->num);}
				|ID '(' {phead=NULL;temptype=type;}
						ParamList {type=temptype;}
									')'	{	GInstall($1->str,type,0);//-------------------------------------------------------
											GLookup($1->str)->paramlist=phead;
											GLookup($1->str)->flabel=flabel++;}
				;
//-------------------------------------------------------------------------functions
	FDefBlock	:FDefBlock FDef
				|;
	FDef		:Type ID '(' {	checkid($2);
								funcname=$2->str;
								binding=-2;
								ldealloc(lhead);
								lhead=NULL;
								phead=NULL;
								tolocal=1;
								ttint=1;}//-------------------------------------------------------------------
							ParamList ')' {	tolocal=0;
											struct Lsymbol *ltemp;
											struct Paramstruct *ptemp;
											ptemp=ghead->flabel==FMAIN?CMLookup(class,funcname)->paramlist:GLookup($2->str)->paramlist;
											ltemp=lhead;
											while(ptemp && ltemp){
												if(ptemp->type!=ltemp->type || strcmp(ptemp->name,ltemp->name)!=0){//----------------------------------------------
													printf("line:%d\nParameter Globally Declared:\tname:'%s'\ttype:'%s'\nParameter Locally Declared:\tname:'%s'\ttype:'%s'\n",line,ptemp->name,ptemp->type->name,ltemp->name,ltemp->type->name);
													exit(1);}
												ptemp=ptemp->next;
												ltemp=ltemp->next;}
											if(ptemp!=NULL || ltemp!=NULL){
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
										 '{' {	heapbinding=binding-1;binding=0;}
												LDeclBlock {lprint();tint=1;}
															Body '}' ;
//-------------------------------------------------------------------------param
	ParamList	:ParamList ',' Param
				|Param
				| /*param can be empty*/;
	Param		:Type Pid;
	Pid			:ID			{if(tolocal==1){
								binding--;
								LInstall($1->str,type);}
							else
								PInstall($1->str,type);}
				;
//-------------------------------------------------------------------------local
	LDeclBlock	:DECL LDecList ENDDECL
				|;
	LDecList	:LDecList LDecl
				|LDecl;
	LDecl		:Type IdList ';';
	IdList		:IdList ',' Lid
				|Lid;
	Lid			:ID				{binding+=1;LInstall($1->str,type);};
//-------------------------------------------------------------------------main
	MainBlock 	:MAIN '(' ')' '{' 						{	binding=0;
															generate();
															funcname="main";
															ldealloc(lhead);
															lhead=NULL;
															binding=0;
															GLookup("main")->type=TLookup("int");}
									LDeclBlock 				{lprint();}
												Body '}'	{ldealloc(lhead);}
				;
//-------------------------------------------------------------------------body
	Body		:BEG Slist RETURN Expr ';' END 	{struct tnode *ret=createtree(ghead->flabel==FMAIN?CMLookup(class,funcname)->type:GLookup(funcname)->type,0,NULL,nt_RET,NULL,$4,NULL,NULL,NULL,NULL);
												struct tnode *body=createtree(TLookup("void"),0,NULL,nt_NODE,$2,NULL,ret,NULL,NULL,NULL);
												funcGen(funcname);
												printf("+CodeGen-ing\n");
												codeGen(body);
												printf("-CodeGen-ing\n");
												bdealloc(body);}
				|BEG RETURN Expr ';' END 		{struct tnode *ret=createtree(ghead->flabel==FMAIN?CMLookup(class,funcname)->type:GLookup(funcname)->type,0,NULL,nt_RET,NULL,$3,NULL,NULL,NULL,NULL);
												funcGen(funcname);
												printf("+CodeGen-ing\n");
												codeGen(ret);
												printf("-CodeGen-ing\n");
												bdealloc(ret);}
	Slist		:Slist Stmt				{$$=createtree(TLookup("void"),0,NULL,nt_NODE,$1,NULL,$2,NULL,NULL,NULL);}
				|Stmt					{$$=$1;};
	Stmt		:READ '(' id ')' ';'								{$$=createtree(TLookup("void"),0,NULL,nt_READ,NULL,$3,NULL,NULL,NULL,NULL);}
				|WRITE '(' Expr ')' ';'								{$$=createtree(TLookup("void"),0,NULL,nt_WRITE,NULL,$3,NULL,NULL,NULL,NULL);}
				|WRITE STRING ';'									{$$=createtree(TLookup("void"),0,NULL,nt_WRITE,NULL,$2,NULL,NULL,NULL,NULL);}
				|id EQ Expr ';'										{$$=createtree(TLookup("void"),0,NULL,nt_ASGN,$1,NULL,$3,NULL,NULL,NULL);}
				|IF '(' Bool ')' THEN Slist ELSE Slist ENDIF ';'	{$$=createtree(TLookup("void"),0,NULL,nt_IFELSE,$3,$6,$8,NULL,NULL,NULL);}
				|IF '(' Bool ')' THEN Slist ENDIF ';'				{$$=createtree(TLookup("void"),0,NULL,nt_IF,$3,NULL,$6,NULL,NULL,NULL);}
				|WHILE '(' Bool ')' DO Slist ENDWHILE ';'			{$$=createtree(TLookup("void"),0,NULL,nt_WHILE,$3,NULL,$6,NULL,NULL,NULL);}
				|REPEAT Slist UNTIL '(' Bool ')' ';'				{$$=createtree(TLookup("void"),0,NULL,nt_WHILE,$5,NULL,$2,NULL,NULL,NULL);}
				|DO Slist WHILE '(' Bool ')' ';'					{$$=createtree(TLookup("void"),0,NULL,nt_WHILE,$5,NULL,$2,NULL,NULL,NULL);}
				|BREAK ';'											{$$=createtree(TLookup("void"),0,NULL,nt_BREAK,NULL,NULL,NULL,NULL,NULL,NULL);}
				|CONTINUE ';'										{$$=createtree(TLookup("void"),0,NULL,nt_CONTINUE,NULL,NULL,NULL,NULL,NULL,NULL);}
				|BRKP ';'											{$$=createtree(TLookup("void"),0,NULL,nt_BRKP,NULL,NULL,NULL,NULL,NULL,NULL);}
				|EXIT ';'											{$$=createtree(TLookup("void"),0,NULL,nt_EXIT,NULL,NULL,NULL,NULL,NULL,NULL);}
				|id EQ INIT '(' ')' ';'								{$$=createtree(TLookup("void"),0,NULL,nt_INIT,NULL,$1,NULL,NULL,NULL,NULL);}
				|id EQ ALLOC '(' ')' ';'							{dnode=$1;$$=createtree(TLookup("void"),GetSize(LLookup($1->str)==NULL?GLookup($1->str)->type:LLookup($1->str)->type),NULL,nt_ALLOC,NULL,$1,NULL,NULL,NULL,NULL);}
				|FREE '(' id ')' ';'								{$$=createtree(TLookup("void"),0,NULL,nt_FREE,NULL,$3,NULL,NULL,NULL,NULL);}
				|DELETE '(' id ')'									{$$=createtree(TLookup("void"),0,NULL,nt_DELETE,NULL,$3,NULL,NULL,NULL,NULL);}
				;
	Expr		:Expr PLUS Expr			{$$=createtree(TLookup("int"),0,NULL,nt_PLUS,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr MINUS Expr		{$$=createtree(TLookup("int"),0,NULL,nt_MINUS,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr MUL Expr			{$$=createtree(TLookup("int"),0,NULL,nt_MUL,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr DIV Expr			{$$=createtree(TLookup("int"),0,NULL,nt_DIV,$1,NULL,$3,NULL,NULL,NULL);}
				|Expr MOD Expr			{$$=createtree(TLookup("int"),0,NULL,nt_MOD,$1,NULL,$3,NULL,NULL,NULL);}
				|'(' Expr ')'			{$$=$2;}
				|NUM					{$$=$1;}
				|STRING					{$$=$1;}
				|id						{$$=$1;}
				|NUL					{$$=$1;}
				|id '(' ')'				{checkid($1);
										if($1->nt!=nt_USERROOT)
											$$=createtree(GLookup($1->str)->type,0,$1->str,nt_FUNC,NULL,$1,NULL,$1->Gentry,NULL,$1->Lentry);
										else{
											class=$1->class;
											$$=createtree(CMLookup($1->class,$1->str)->type,0,$1->str,nt_FUNC,NULL,$1,NULL,$1->Gentry,NULL,$1->Lentry);}
										$$->class=$1->class;}
				|id '(' ArgList ')'		{checkid($1);
										if($1->nt!=nt_USERROOT)
											$$=createtree(GLookup($1->str)->type,0,$1->str,nt_FUNC,NULL,$1,NULL,$1->Gentry,$3,$1->Lentry);
										else{
											class=$1->class;
											$$=createtree(CMLookup($1->class,$1->str)->type,0,$1->str,nt_FUNC,NULL,$1,NULL,$1->Gentry,$3,$1->Lentry);}
										$$->class=$1->class;}
				|NEW '(' ID ')'			{$$=createtree(NULL,0,NULL,nt_NEW,NULL,$3,NULL,NULL,NULL,NULL);}
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
	id			:ID							{checkid($1);
											if(classflag==0){
												$$=createtree(LLookup($1->str)==NULL?GLookup($1->str)->type:LLookup($1->str)->type,0,$1->str,nt_ID,NULL,NULL,NULL,GLookup($1->str),NULL,LLookup($1->str));
												$$->class=LLookup($1->str)==NULL?GLookup($1->str)->class:NULL;}
											else{
												$$=createtree(LLookup($1->str)==NULL?CFLookup(class,$1->str)->type:LLookup($1->str)->type,0,$1->str,nt_ID,NULL,NULL,NULL,NULL,NULL,LLookup($1->str));
											}}
				|ID '[' Expr ']'			{checkid($1);
											$$=createtree(LLookup($1->str)==NULL?GLookup($1->str)->type:LLookup($1->str)->type,0,$1->str,nt_ARR,NULL,$3,NULL,GLookup($1->str),NULL,LLookup($1->str));}
				|MUL id						{$$=createtree(GLookup($2->str)->type,$2->num,$2->str,nt_SPTR,NULL,NULL,NULL,GLookup($2->str),NULL,LLookup($1->str));}
				|'&' id						{$$=createtree(GLookup($2->str)->type,$2->num,$2->str,nt_APTR,NULL,NULL,NULL,GLookup($2->str),NULL,LLookup($1->str));}
				|Field						{$$=$1;}
	Field		:Field '.' ID 				{struct Typetable *ttemp=$1->t;
											struct Typetable *tttemp;
											int findex;
											struct Fieldlist *ftemp;
											struct Classtable *classs;
											struct Memberfunclist *mtemp;
											if(ttemp!=NULL){//type
												checktype(ttemp,$3->str);
												ftemp=FLookmember(ttemp,$3->str);
												tttemp=ftemp->type;findex=ftemp->fieldindex;}
											else{//class
												if(CFLookup($1->class,$3->str)==NULL){//method	ol.findfact()
													mtemp=CMLookup(CFLookup($1->class,$1->str)->ctype,$3->str);
													tttemp=mtemp->type;findex=mtemp->funcposition;}
												else{//field	ol.x
													ftemp=CFLookup(GLookup($1->str)->class,$3->str);
													tttemp=ftemp->type;findex=ftemp->fieldindex;}}
											$1->nt=nt_USERNODE;
											$$=createtree(tttemp,findex,$3->str,nt_USERROOT,$1,NULL,NULL,$1->Gentry,NULL,$1->Lentry);}
				|ID '.' ID					{checkid($1);
											checkmember($1,$3);
											if(classflag==0) $1->class=LLookup($1->str)==NULL?GLookup($1->str)->class:NULL;
											struct Typetable *ttemp=LLookup($1->str)==NULL?GLookup($1->str)->type:LLookup($1->str)->type;
											struct Fieldlist *ftemp;
											struct Memberfunclist *mtemp;
											int findex;
											if(ttemp!=NULL){//type
												checktype(ttemp,$3->str);
												ftemp=FLookmember(ttemp,$3->str);
												ttemp=ftemp->type;findex=ftemp->fieldindex;}
											else{//class obj.init()
												if(CFLookup(GLookup($1->str)->class,$3->str)==NULL){//method
													mtemp=CMLookup(GLookup($1->str)->class,$3->str);
													ttemp=mtemp->type;findex=mtemp->funcposition;}
												else{//field
													ftemp=CFLookup(GLookup($1->str)->class,$3->str);
													ttemp=ftemp->type;findex=ftemp->fieldindex;}}
											struct tnode *node=createtree(ttemp,0,$1->str,nt_USERNODE,NULL,NULL,NULL,GLookup($1->str),NULL,LLookup($1->str));
											$$=createtree(ttemp,findex,$3->str,nt_USERROOT,node,NULL,NULL,GLookup($1->str),NULL,LLookup($1->str));
											if(classflag==0) $$->class=LLookup($1->str)==NULL?GLookup($1->str)->class:NULL;}
				|SELF '.' ID				{struct tnode *self=createtree($3->t,heapbinding,$3->str,nt_SELF,NULL,NULL,NULL,NULL,NULL,NULL);self->class=class;
											struct Typetable *typ;
											int field;
											if(CFLookup(class,$3->str)!=NULL){//Field
												typ=CFLookup(class,$3->str)->type;
												field=CFLookup(class,$3->str)->fieldindex;}
											else{//Method
												typ=CMLookup(class,$3->str)->type;
												field=CMLookup(class,$3->str)->funcposition;}
											$$=createtree(typ,field,$3->str,nt_USERROOT,self,NULL,NULL,NULL,NULL,LLookup($3->str));
											$$->class=class;}
				;
%%
void checkid(struct tnode *t){
	if(classflag==1){//classblock
		if(CFLookup(class,t->str)==NULL && CMLookup(class,t->str)==NULL && LLookup(t->str)==NULL){
			printf("Undeclared identifier:'%s' at line:'%d'\n",t->str,line);
			exit(1);}}
	else{//general
		if(t->nt!=nt_USERROOT && LLookup(t->str)==NULL && GLookup(t->str)==NULL && CLookup(t->str)==NULL){
			printf("Undeclared identifier:'%s' at line:'%d'\n",t->str,line);
			exit(1);}}}
void checkmember(struct tnode *parent, struct tnode *member){
	struct Classtable *ctemp;
	if(LLookup(parent->str)==NULL){
		ctemp=GLookup(parent->str)->class;
		if(ctemp!=NULL && CFLookup(ctemp,member->str)==NULL && CMLookup(ctemp,member->str)==NULL){
			printf("line:'%d'\tno field or method:'%s' in class:'%s'\n",line,member->str,ctemp->name);
			exit(1);}}}
void checktype(struct Typetable *t1, char *member){
	if(FLookmember(t1,member)==NULL){
		printf("line:'%d'\tUndeclared type with name:'%s' in type:'%s'\n",line,member,t1->name);
		exit(1);
	return;}}
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
				printf("\tname:'%s'\tfieldIndex:'%d'\ttype:'%s'\n",ftemp->name,ftemp->fieldindex,ftemp->type->name);
			ftemp=ftemp->next;}
		ttemp=ttemp->next;}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");}
void cprint(){
	int i,j;
	struct Classtable *ctemp;
	ctemp=chead;
	printf("\n\n\n\n\n\t\t\t\tCLASS TABLE\n");
	while(ctemp){
		ctemp=ctemp;
		printf("\nClass:'%s'\tParent:'%s'\tindex:'%d'\tfieldcount:'%d'\tmethodcount:'%d'\n",ctemp->name,ctemp->parent!=NULL?ctemp->parent->name:"(null)",ctemp->index,ctemp->fieldcount,ctemp->methodcount);
		struct Fieldlist *ftemp;
		struct Memberfunclist *mtemp;
		struct Paramstruct *ptemp;
		printf("Members:\n");
		printf("\tFields\n");
		ftemp=ctemp->memberfield;
		i=1;
		while(ftemp){
			printf("\t%d.name:'%s'\tfieldindex:'%d'\t",i++,ftemp->name,ftemp->fieldindex);
			if(ftemp->type!=NULL)
				printf("type:'%s'\t",ftemp->type->name);
			else
				printf("type:'---'\t");
			if(ftemp->ctype!=NULL)
				printf("ctype:'%s'\n",ftemp->ctype->name);
			else
				printf("ctype:---\n");
			ftemp=ftemp->next;}
		printf("\n\tMethods\n");
		i=1;
		mtemp=ctemp->memberfunc;
		while(mtemp){
			printf("\t%d.name:'%s'\ttype:'%s'\tfuncposition:'%d'\tflabel:F%d\n",i++,mtemp->name,mtemp->type->name,mtemp->funcposition,mtemp->flabel);
			j=1;
			ptemp=mtemp->paramlist;
			if(ptemp!=NULL)
				printf("\t\tparamters...\n");
			while(ptemp){
				printf("\t\t%d.name:'%s'\ttype:'%s'\n",j,ptemp->name,ptemp->type->name);
				ptemp=ptemp->next;}
			mtemp=mtemp->next;}
		ctemp=ctemp->next;
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");}
	printf("\n\n\n\n");}
void gprint(){
	int i,j;
	printf("\n\n\n\t\tGlobal Table(Static size:'%d')\tgbinding:'%d'\n\n",gbinding-4096-8*(1+(chead==NULL?-1:chead->index)),gbinding);
	struct Gsymbol* gtemp=ghead;
	struct Paramstruct* ptemp;
	i=1;
	while(gtemp!=NULL){
		if(gtemp->size>0){
			if(gtemp->type!=NULL)
				printf("%d.name:'%s'\ttype:'%s'\tclass:'---'\tsize:'%d'\tbase:'%d'\tarr:%d\n",i++,gtemp->name,gtemp->type->name,gtemp->size,gtemp->binding,gtemp->arr);
			else
				printf("%d.name:'%s'\ttype:'---'\tclass:'%s'\tsize:'%d'\tbase:'%d'\tarr:%d\n",i++,gtemp->name,gtemp->class->name,gtemp->size,gtemp->binding,gtemp->arr);
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
	printf("\n\n\n\n");}
void lprint(){
	int i;
	printf("\n\t\t\t\t\t\t'%s'\n",funcname);
	int count=0;
	struct Lsymbol* ltemp=lhead;
	if(ltemp!=NULL)
		printf("LOCALS...\n");
	i=1;
	while(ltemp!=NULL){
		count++;
		printf("%d.name:'%s'\ttype:'%s'\tbinding:'%d'\n",i++,ltemp->name,ltemp->type->name,ltemp->binding);
		if(ltemp->binding==1){printf("\narguments\n");i=1;}
		ltemp=ltemp->next;}
	ltemp=lhead;
	if(ltemp!=NULL)
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");}
void ldealloc(struct Lsymbol *lhead){
	if(lhead==NULL)
		return;
	ldealloc(lhead->next);
	free(lhead->next);}
void bdealloc(struct tnode *body){
	if(body==NULL)
		return;
	bdealloc(body->left);
	free(body->left);
	bdealloc(body->down);
	free(body->down);
	bdealloc(body->right);
	free(body->right);}
void sigint_handler(int num){
	printf("\n\n\nSegmentation occured at line:'%d'\n",line);
	signal(SIGSEGV, SIG_DFL);
	raise(SIGSEGV);}
void yyerror(char const *s){
	printf("yyerror %s\nLine:%d at '%s'\n",s,line,yytext);
	if(strcmp(yytext,"end")==0)
		printf("Did you use a return statement...!\n");
	exit(1);}
int main(){
	signal(SIGSEGV, sigint_handler);
	ghead=NULL;
	chead=NULL;
	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else{
		printf("Input file error\n");
		exit(1);}
	#ifndef BUG
		target_file=fopen("intermediate.xsm","w+");
	#endif
	GInstall("main",TLookup("int"),0);
	GLookup("main")->flabel=FMAIN;
	TypeTableCreate();
	fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(target_file,"JMP F%d  --'start'\n",TMAIN);
	yyparse();
	return 0;}
//
