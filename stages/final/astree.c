#ifndef INCL
	#include "headers.h"
	#endif
struct tnode* createtree(struct Typetable *t, int num,char *str,int nt,struct tnode *l, struct tnode *d,struct tnode *r,struct Gsymbol *gentry,struct tnode *arglist,struct Lsymbol *lentry){
	struct Paramstruct *ptemp;
	struct tnode *atemp,*treetemp;
	struct Typetable *tint,*tstr,*tintptr,*tstrptr,*tvoid,*tbool,*tnull;
	tint=TLookup("int");
	tstr=TLookup("str");
	tintptr=TLookup("intptr");
	tstrptr=TLookup("strptr");
	tbool=TLookup("bool");
	tvoid=TLookup("void");
	tnull=TLookup("null");
	/*switch(nt){
		case nt_NODE:
			if(t!=tvoid)
				mismatch(nt,l->t,r->t);
			break;
		case nt_PLUS:
		case nt_MINUS://need to work
		case nt_MUL:
		case nt_DIV:
		case nt_MOD:
			if(l->t!=tint || r->t!=tint)
				mismatch(nt, l->t, r->t);
			break;
		case nt_LT:
		case nt_LE:
		case nt_GT:
		case nt_GE:
		case nt_EE:
		case nt_NE:
			if((l->t==tint 		||
				l->t==tintptr 	||
				l->t==tbool 	||
				l->t==tstr 		||
				l->t==tstrptr 	||
				l->t==tvoid 	||
				l->t==tnull)
					&&
				r->t==tnull)
				mismatch(nt,l->t,r->t);
			if(	(l->t!=tint||r->t!=tint)	&&
				(r->t!=tnull))
				mismatch(nt,l->t,r->t);
			break;
		case nt_NUM:
		case nt_ID:
		case nt_USERROOT:
		case nt_USERNODE:
			break;
		case nt_ARR:
			if(d->t!=tint && d->t!=tstr)
				mismatch(nt,t,t);
			break;
		case nt_READ:
		case nt_WRITE:
		case nt_STR:
			break;
		case nt_ASGN:
			if((l->t==tint 		||
				l->t==tintptr 	||
				l->t==tbool 	||
				l->t==tstr 		||
				l->t==tstrptr 	||
				l->t==tvoid 	||
				l->t==tnull)
					&&
				r->t==tnull)
				mismatch(nt,l->t,r->t);
			if(l->t!=r->t && r->t!=tnull)
				mismatch(nt,l->t,r->t);
			break;
		case nt_IF:
		case nt_IFELSE:
		case nt_WHILE:
			break;
		case nt_FUNC:
			ptemp=GLookup(str)->paramlist;
			atemp=arglist;
			int param_pos=0;
			while(ptemp!=NULL && atemp!=NULL){
				param_pos++;
				if(ptemp->type!=atemp->t){
					//if(ptemp->type==t_INPTR && atemp->t==t_INT && atemp->nt==nt_APTR) goto goto1;
					//if(ptemp->type==t_CHPTR && atemp->t==t_CHAR && atemp->nt==nt_APTR) goto goto1;
					printf("line:%d\ttype mismatch in Function call at '%d' parameter from right\n",line,param_pos);
					printf("Declared type:'%s'\nCalled type:'%s'\n",ptemp->type->name,atemp->t->name);
					exit(1);}
				ptemp=ptemp->next;
				atemp=atemp->down;}
			if(ptemp!=NULL || atemp!=NULL){
				if(ptemp!=NULL){
					while(ptemp){
						printf("line:%d\tCalled with fewer arguments...\tname:'%s'\n",line,ptemp->name);
						ptemp=ptemp->next;}}
				else{while(atemp!=NULL){
					printf("line:%d\tCalled with more arguments...\tname:'%s'\n",line,atemp->str);
					atemp=atemp->down;}}
				exit(1);}
			break;
		case nt_RET:
			if(t!=d->t)
				mismatch(nt,t,d->t);
			break;
		case nt_BRKP:
		case nt_INIT:
			break;
		case nt_ALLOC:
			if(	d->t==tint 		||
				d->t==tintptr 	||
				d->t==tbool 	||
				d->t==tstr 		||
				d->t==tstrptr 	||
				d->t==tvoid 	||
				d->t==tnull)
				mismatch(nt,d->t,d->t);
			break;
		case nt_FREE:
			if(	d->t==tint 		||
				d->t==tintptr 	||
				d->t==tbool 	||
				d->t==tstr 		||
				d->t==tstrptr 	||
				d->t==tvoid 	||
				d->t==tnull)
				mismatch(nt,d->t,d->t);
			break;
		case nt_EXIT:
		case nt_TRUE:
		case nt_FALSE:
		case nt_AND:
		case nt_OR:
		case nt_NOT:
		case nt_NUL:
		case nt_SELF://-----------------
		case nt_NEW:
		case nt_DELETE:
			break;
		default:
			printf("NO NT MATCHED IN CREATTREE...\n");}
	*/treetemp=malloc(sizeof(struct tnode));
	treetemp->num=num;
	treetemp->t=t;
	treetemp->nt=nt;
	if(str!=NULL)
		treetemp->str=strdup(str);
	else
		treetemp->str=NULL;
	treetemp->Gentry=gentry;
	treetemp->Lentry=lentry;
	treetemp->arglist=arglist;
	treetemp->left=l;
	treetemp->right=r;
	treetemp->down=d;
	return treetemp;}
void GInstall(char *name, struct Typetable *type, int size){
	struct Gsymbol* gitemp;
	if(GLookup(name)!=NULL){
		printf("line:%d\tGvariable:'%s' redeclared\n",line,name);
		exit(1);}
	gitemp=malloc(sizeof(struct Gsymbol));
	gitemp->name=name;
	gitemp->type=type;
	gitemp->class=ctype;
	gitemp->size=size;
	if(size>0)
		gitemp->binding=gbinding;
	else
		gitemp->binding=0;
	gbinding=gbinding+size;
	gitemp->next=ghead;
	ghead=gitemp;}
struct Gsymbol *GLookup(char* name){
	struct Gsymbol* temp;
	temp=ghead;
	while(temp!=NULL){
		if(strcmp(temp->name,name)==0){
			return temp;}
		temp=temp->next;}
	return NULL;}
void PInstall(char* name, struct Typetable *type){
	if(PLookup(name)!=NULL){
		printf("line:%d\tPvariable:'%s' redeclared\n",line,name);
		exit(1);}
	struct Paramstruct* pitemp=malloc(sizeof(struct Paramstruct));
	pitemp->name=name;
	pitemp->type=type;
	pitemp->next=phead;
	phead=pitemp;}
struct Paramstruct* PLookup(char* name){
	struct Paramstruct* temp;
	temp=phead;
	while(temp!=NULL){
		if(strcmp(temp->name,name)==0){
			return temp;}
		temp=temp->next;}
	return NULL;}
void LInstall(char *name, struct Typetable *type){
	if(LLookup(name)!=NULL){
		printf("line:%d\tLvariable:'%s' redeclared\n",line,name);
		exit(1);}
	struct Lsymbol* litemp=malloc(sizeof(struct Lsymbol));
	litemp->name=name;
	litemp->type=type;
	litemp->binding=binding;
	litemp->next=lhead;
	lhead=litemp;}
struct Lsymbol *LLookup(char *name){
	struct Lsymbol* temp;
	temp=lhead;
	while(temp!=NULL){
		if(strcmp(temp->name,name)==0){
			return temp;}
		temp=temp->next;}
	return NULL;}
void TypeTableCreate(){
	thead=NULL;
	TInstall("int",1,NULL);
	TInstall("intptr",1,NULL);
	TInstall("str",1,NULL);
	TInstall("strptr",1,NULL);
	TInstall("bool",0,NULL);
	TInstall("null",0,NULL);
	TInstall("void",0,NULL);}
void TInstall(char *name,int size, struct Fieldlist *fields){
	if(TLookup(name)!=NULL){
		printf("line:%d\ttype:'%s' redeclared\n",line,name);
		exit(1);}
	struct Typetable *ttemp=malloc(sizeof(struct Typetable));
	ttemp->name=name;
	ttemp->size=size;
	ttemp->fields=fields;
	ttemp->next=thead;
	thead=ttemp;}
struct Typetable* TLookup(char *name){
	struct Typetable *temp;
	temp=thead;
	while(temp!=NULL){
		if(strcmp(temp->name,name)==0){
			return temp;}
		temp=temp->next;}
	return NULL;}
void FInstall(char *name,int fieldindex,struct Typetable *type){
	struct Fieldlist *ftemp=malloc(sizeof(struct Fieldlist));
	if(FLookup(type,name)!=NULL){
		printf("line:%d\tfield:'%s' redeclared\n",line,name);
		exit(1);}
	ftemp->name=name;
	ftemp->fieldindex=fieldindex;
	ftemp->type=type;
	ftemp->ctype=NULL;
	ftemp->next=fhead;
	fhead=ftemp;}
struct Fieldlist* FLookup(struct Typetable *type, char *name){
	struct Fieldlist *temp;
	temp=fhead;
	while(temp!=NULL){
		if(strcmp(temp->name,name)==0){
			return temp;}
		temp=temp->next;}
	return NULL;}
struct Fieldlist* FLookmember(struct Typetable *type, char *name){
	struct Fieldlist *temp;
	temp=type->fields;
	while(temp!=NULL){
		if(strcmp(temp->name,name)==0){
			return temp;}
		temp=temp->next;}
	return NULL;}
struct Classtable* CInstall(char *name,char *parent){
	struct Classtable *new=malloc(sizeof(struct Classtable));
	new->name=name;
	if(parent!=NULL && CLookup(parent)==NULL){
		printf("line:'%d'\tNo parent class:'%s' to extend from\n",line,parent);
		exit(1);}
	if(parent!=NULL)
		new->parent=CLookup(parent);
	else
		new->parent=NULL;
	new->index=cindex++;
	new->next=chead;
	chead=new;
	return new;}
struct Classtable* CLookup(char *name){
	struct Classtable *temp;
	temp=chead;
	while(temp){
		if(strcmp(temp->name,name)==0){
			return temp;}
		temp=temp->next;}
	return NULL;}
void CFInstall(char *typename, char *name){
	struct Fieldlist *new=malloc(sizeof(struct Fieldlist));
	new->name=name;
	if(TLookup(typename)!=NULL){
		new->type=TLookup(typename);
		new->ctype=NULL;}
	else{
		new->type=NULL;
		new->ctype=CLookup(typename);}
	if(TLookup(typename)!=NULL && CLookup(typename)!=NULL){
		printf("line:'%d'\tCHECK ME!\n",line);
		exit(1);}
	new->fieldindex=fieldindex++;
	if(new->type==NULL) {fieldindex++;fieldcount++;}//classs
	new->next=fhead;
	fhead=new;}
struct Fieldlist *CFLookup(struct Classtable *class, char *name){
	struct Fieldlist *temp;
	temp=class->memberfield;
	while(temp){
		if(strcmp(temp->name,name)==0){
			return temp;}
		temp=temp->next;}
	return NULL;}
void CMInstall(char *name, struct Typetable *type, struct Paramstruct *Paramlist){
	struct Memberfunclist *new=malloc(sizeof(struct Memberfunclist));
	new->name=name;
	new->type=type;
	new->paramlist=Paramlist;
	new->flabel=flabel++;
	new->funcposition=funcposition++;
	new->next=mhead;
	mhead=new;}
struct Memberfunclist *CMLookup(struct Classtable *class, char *name){
	struct Memberfunclist *temp;
	temp=class->memberfunc;
	while(temp){
		if(strcmp(temp->name,name)==0){
			return temp;}
		temp=temp->next;}
	return NULL;}
int GetSize (struct Typetable *type){
	return type->size;}
void mismatch(int n, struct Typetable *l, struct Typetable *r){
	printf("line:'%d'\ttype mismatch:nt_%d\n",line,n);
	printf("left:'%s'\n",l->name);
	printf("right:'%s'\n",r->name);
	exit(1);}
//