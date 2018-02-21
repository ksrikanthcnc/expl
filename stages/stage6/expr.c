#define puts //puts
/*//uncomment for consoling
	#define puts(str) tabtemp=0; while(tabtemp++<tabs) printf("\t"); printf(str); printf("\n");
	#define target_file stdout
*/
#include "expr.h"
struct tnode* createtree(struct Typetable *t, int num,char *str,int nt,struct tnode *l, struct tnode *d,struct tnode *r,struct Gsymbol *gentry,struct tnode *arglist,struct Lsymbol *lentry){
	struct Paramstruct *ptemp;
	struct tnode *atemp,*treetemp;
	struct Typetable *tint,*tstr,*tintptr,*tstrptr,*tvoid,*tbool,*tnull,*tuser;
	tint=TLookup("int");
	tstr=TLookup("str");
	tintptr=TLookup("intptr");
	tstrptr=TLookup("strptr");
	tbool=TLookup("bool");
	tvoid=TLookup("void");
	tnull=TLookup("null");
	switch(nt){
		case nt_NODE:
			if(t!=tvoid)
				mismatch(nt,l->t,r->t);
			break;
		case nt_PLUS:	
		case nt_MINUS:
			/*if(l->nt==nt_PTR || r->nt==nt_PTR)
				if(	!(l->nt == nt_PTR && (r->nt==nt_PTR || r->nt==nt_NUM))	&&
					!(r->nt == nt_PTR && (l->nt==nt_PTR || l->nt==nt_NUM))){
						mismatch(nt, l->t, r->t);}
			if(l->nt==nt_PTR && r->nt==nt_PTR)
				if(l->t!=r->t)
					mismatch(nt, l->t, r->t);
				else
					t=l->t;
			if(l->nt==nt_PTR)	t=l->t;
			if(r->nt==nt_PTR)	t=r->t;*/
		case nt_MUL:
		case nt_DIV:
		case nt_MOD:
			if(l->t!=tint || r->t!=tint)
				mismatch(nt, l->t, r->t);
			/*if (	(l->t == t_CHAR && l->nt!=nt_PTR) || 
					(r->t == t_CHAR && r->nt!=nt_PTR))
				mismatch(nt, l->t, r->t);*/
			break;
		case nt_LT:
		case nt_LE:
		case nt_GT:
		case nt_GE:
		case nt_EE:
		case nt_NE:
			if(l->t!=tint||r->t!=tint)
				mismatch(nt,l->t,r->t);
			break;
		case nt_NUM:
		case nt_ID:
		case nt_USER:
		case nt_ARR:
		/*case nt_PTR:*/
		case nt_READ:
		case nt_WRITE:
		case nt_STR:
			break;
		case nt_ASGN:
			if(l->t!=r->t)
				mismatch(nt,l->t,r->t);
			/*if(l->nt==nt_PTR && r->nt==nt_FUNC)
				l->t+=4;
			if(	(l->nt==nt_NUM || l->t==t_BOOL || l->nt==nt_APTR)	||
				(r->t==t_BOOL)	||
				(l->t!=r->t)	||
				(l->nt==nt_PTR && r->nt==nt_PTR)	||
				(l->nt==nt_PTR && r->nt==nt_ID)		||
				(l->nt==nt_ID && r->nt==nt_PTR)		||
				(l->nt==nt_ID && r->nt==nt_APTR)	||
				(l->nt==nt_PTR && r->nt==nt_NUM))
				{printf("ntype mismatch:nt_%d at line:%d\n",nt,line);
				printf("left:nt_%d\n",l->nt);
				printf("right:nt_%d\n",r->nt);
				mismatch(nt,l->t,r->t);}*/
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
				goto1:
				ptemp=ptemp->next;
				atemp=atemp->down;}
			if(ptemp!=NULL || atemp!=NULL){
				if(ptemp!=NULL){
					printf("line:%d\tCalled with fewer arguments...\n",line);}
				else{
					printf("line:%d\tCalled with more arguments...\n",line);}
				exit(1);}
			break;
		case nt_RET:
			/*if(d->nt==nt_APTR)
				t-=4;*/
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
			break;
		default:
			printf("NO NT MATCHED IN CREATTREE...\n");
			}
		
	
	treetemp=malloc(sizeof(struct tnode));
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
	//printf("Install-ing in Global Symbol table...\n");
	struct Gsymbol* gitemp;
	if(GLookup(name)!=NULL){
		printf("line:%d\tGvariable:'%s' redeclared\n",line,name);
		exit(1);}
	gitemp=malloc(sizeof(struct Gsymbol));
	gitemp->name=name;
	gitemp->type=type;
	gitemp->size=size;
	if(size>0)
		gitemp->binding=gbinding;
	else
		gitemp->binding=0;
	gbinding=gbinding+size;
	gitemp->next=ghead;
	ghead=gitemp;
	//printf("New entry is----\n");
	//printf("name:'%s'\ttype:'%d'\tsize:'%d'\tbinding:'%d'\tarr:%d\n",gitemp->name,gitemp->type,gitemp->size,gitemp->binding,gitemp->arr);
	//printf("Install-ed...\n\n");
	;}

struct Gsymbol *GLookup(char* name){
	//printf("  Searching symbol table...\n");
	struct Gsymbol* temp;
	temp=ghead;
	while(temp!=NULL){
		//printf("  name:'%s'\ttype:'%d'\tsize:'%d'\tbinding:'%d'\tarr:%d\n",temp->name,temp->type,temp->size,temp->binding,temp->arr);
		if(strcmp(temp->name,name)==0){
			//printf("  Found!\n");
			return temp;}
		temp=temp->next;}
	//printf("  Not found...\n");
	return NULL;}

void PInstall(char* name, struct Typetable *type){
	//printf("Install-ing in ParamList...\n");
	if(PLookup(name)!=NULL){
		printf("line:%d\tPvariable:'%s' redeclared\n",line,name);
		exit(1);}
	struct Paramstruct* pitemp=malloc(sizeof(struct Paramstruct));
	pitemp->name=name;
	pitemp->type=type;
	pitemp->next=phead;
	phead=pitemp;
	//printf("New entry is----\n");
	//printf("name:'%s'\ttype:'%d'\t\n",pitemp->name,pitemp->type);
	//printf("Install-ed...\n\n");
	;}

struct Paramstruct* PLookup(char* name){
	struct Paramstruct* temp;
	temp=phead;
	while(temp!=NULL){
		//printf("  name:'%s'\ttype:'%d'\n",temp->name,temp->type);
		if(strcmp(temp->name,name)==0){
			//printf("  Found!\n");
			return temp;}
		temp=temp->next;}
	//printf("  Not found!\n");
	return NULL;}

void LInstall(char *name, struct Typetable *type){
	//printf("Install-ing in Local Symbol table...\n");
	if(LLookup(name)!=NULL){
		printf("line:%d\tLvariable:'%s' redeclared\n",line,name);
		exit(1);}
	struct Lsymbol* litemp=malloc(sizeof(struct Lsymbol));
	litemp->name=name;
	litemp->type=type;
	litemp->binding=binding;
	litemp->next=lhead;
	lhead=litemp;
	//printf("New entry is----\n");
	//printf("name:'%s'\ttype:'%d'\tbinding:'%d'\n",litemp->name,litemp->type,litemp->binding);
	//printf("Install-ed...\n\n");
	;}

struct Lsymbol *LLookup(char *name){
	//printf("Searching Lsymbol table...\n");
	struct Lsymbol* temp;
	temp=lhead;
	while(temp!=NULL){
		//printf("name:'%s'\ttype:'%d'\tbinding:'%d'\n",temp->name,temp->type,temp->binding);
		if(strcmp(temp->name,name)==0){
			//printf("Found!\n");
			return temp;}
		temp=temp->next;}
	//printf("Not found...\n");
	return NULL;}
void TypeTableCreate(){
	thead=NULL;
	//printf("Initializing Type Table\n");
	TInstall("int",1,NULL);
	TInstall("intptr",1,NULL);
	TInstall("str",1,NULL);
	TInstall("strptr",1,NULL);
	TInstall("bool",0,NULL);
	TInstall("void",0,NULL);}
void TInstall(char *name,int size, struct Fieldlist *fields){
	//printf("Install-ing in TyepTable...\n");
	if(TLookup(name)!=NULL){
		printf("line:%d\ttype:'%s' redeclared\n",line,name);
		exit(1);}
	struct Typetable *ttemp=malloc(sizeof(struct Typetable));
	ttemp->name=name;
	ttemp->size=size;
	ttemp->fields=fields;
	ttemp->next=thead;
	thead=ttemp;
	//printf("New entry is----\n");
	//printf("name:'%s'\size:'%d'\t\n",ttemp->name,ttemp->size);
	//printf("Install-ed...\n\n");
	}
struct Typetable* TLookup(char *name){
	struct Typetable *temp;
	temp=thead;
	while(temp!=NULL){
		//printf("name:'%s'\ttype:'%d'\tbinding:'%d'\n",temp->name,temp->type,temp->binding);
		if(strcmp(temp->name,name)==0){
			//printf("Found!\n");
			return temp;}
		temp=temp->next;}
	//printf("Not found...\n");
	return NULL;}
void FInstall(char *name,int fieldIndex,struct Typetable *type){
	struct Fieldlist *ftemp=malloc(sizeof(struct Fieldlist));
	if(FLookup(type,name)!=NULL){
		printf("line:%d\tfield:'%s' redeclared\n",line,name);
		exit(1);}
	ftemp->name=name;
	ftemp->fieldIndex=fieldIndex;
	ftemp->type=type;
	ftemp->next=fhead;
	fhead=ftemp;}
struct Fieldlist* FLookup(struct Typetable *type, char *name){
	struct Fieldlist *temp;
	temp=fhead;
	while(temp!=NULL){
		//printf("\tname:'%s'\tfieldIndex:'%d'\ttype->name:'%s'\n",temp->name,temp->fieldIndex,temp->type->name);
		if(strcmp(temp->name,name)==0){
			//printf("Found!\n");
			return temp;}
		temp=temp->next;}
	//printf("line:'%d':Not found '%s' in type:'%s'\n",line,name,type->name);
	return NULL;}

int GetSize (struct Typetable *type){
	return type->size;}

void generate(){
	puts("\t\t\t\t+Generating Code");
	fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(target_file,"MOV SP,%d --start\n",gbinding-1);
	fprintf(target_file,"MOV BP,%d --start\n",gbinding);
	fprintf(target_file,"PUSH R0 --ret.val\n");
	//Brkp(target_file);
	fprintf(target_file,"CALL F1000\n");
	Halt(target_file);
	puts("\t\t\t\t-Generated");
	;}

int reg=-1;
int label=0;
int break2[100];
int cont1[100];
int top=-1;

int getReg(){
	reg++;
	/*
	//printf("\t\tgotReg:R%d\t",reg);
	printf("\t\t\t\t+");
	for(int s=reg;s>-1;s--) printf("#");
	printf("\n");
	*/
	if(reg>19){printf("Out of registers\n");
				exit(1);}
	return reg;}
void freeReg(){
	reg--;
	if(reg<0){//puts("(All registers free...)");
	;}
	/*
	//printf("\t\tfreedReg:R%d\t",reg);
	printf("\t\t\t\t-");
	for(int s=reg;s>-1;s--) printf("#");
	printf("\n");
	*/
	}
int getLabel(){label++;return label;}
//int argtemp=0;
int codeGen(struct tnode *t){
	tabs++;
	int i,j,k,ret,label1,label2,result,regtemp;
	struct Gsymbol *node,*temp;
	struct tnode *atemp;
	struct Lsymbol *ltemp;
	switch(t->nt){
		case nt_NODE:
			puts("\t\t\t\t+node");
			puts("\t\t\t\t+left");
			codeGen(t->left);
			puts("\t\t\t\t+right");
			codeGen(t->right);
			puts("\t\t\t\t-");
			break;
		case nt_NUM:
			puts("\t\t\t\t+num");
			//printf("%d\n",t->num);
			i=getReg();
			fprintf(target_file, "MOV R%d,%d --num\n",i,t->num);
			puts("\t\t\t\t-num");
			tabs--;
			return i;
			break;
		case nt_STR:
			puts("\t\t\t\t+str");
			//printf("%s\n",t->str);
			i=getReg();
			fprintf(target_file, "MOV R%d,%s --str\n",i,t->str);//----------------
			puts("\t\t\t\t-str");
			tabs--;
			return i;
			break;
		case nt_ID:
			puts("\t\t\t\t+id");
			//printf("%s\n",t->str);
			i=getReg();
			if(t->Lentry==NULL){
				j=t->Gentry->binding+t->num;
				fprintf(target_file, "MOV R%d,[%d] --Gid.fetch\n",i,j);}
			else{
				j=getReg();
				fetch_local_loc_to(t,j);
				fprintf(target_file, "MOV R%d,[R%d] --Lid.fetch\n",i,j);
				freeReg();}
			puts("\t\t\t\t-id");
			tabs--;
			return i;
			break;
		/*case nt_PTR:
			puts("\t\t\t\tpointer-<var name>");
			//printf("%s\n",t->str);
			i=getReg();
			if(t->Lentry==NULL){
				fprintf(target_file, "MOV R%d, [%d]\n",i,t->Gentry->binding);}
			else{
				j=getReg();
				fetch_local_loc_to(t,j);
				fprintf(target_file, "MOV R%d,[R%d]\n",i,j);
				freeReg();}
			tabs--;
			return i;
			break;*/
		case nt_APTR:
			puts("\t\t\t\t+pointer-&");
			//printf("%s\n",t->str);
			i=getReg();
			if(t->Lentry==NULL){
				fprintf(target_file, "MOV R%d, %d --Gaptr\n",i,t->Gentry->binding+t->num);}
			else{
				j=getReg();
				fetch_local_loc_to(t,j);
				fprintf(target_file, "MOV R%d,R%d --Laptr\n",i,j);
				freeReg();}
			puts("\t\t\t\t-pointer-&");
			tabs--;
			return i;
			break;
		case nt_SPTR:
			puts("\t\t\t\t+pointer-*");
			//printf("%s\n",t->str);
			i=getReg();
			if(t->Lentry==NULL){
				fprintf(target_file, "MOV R%d, [%d] --Gaddr\n",i,t->Gentry->binding+t->num);
				fprintf(target_file, "MOV R%d, [R%d] --Gval\n",i,i);}
			else{
				j=getReg();
				fetch_local_loc_to(t,j);
				fprintf(target_file, "MOV R%d,[R%d] --Laddr\n",i,j);
				fprintf(target_file, "MOV R%d, [R%d] --Lval\n",i,i);
				freeReg();}
			puts("\t\t\t\t-pointer-*");
			tabs--;
			return i;
			break;
		case nt_ARR:
			puts("\t\t\t\t+arr");
			//printf("%s\n",t->str);
			i=getReg();
			node=t->Gentry;
			if((t->num)>node->size)
				printf("WARNING:Accessing beyond declaration!\n");
			j=codeGen(t->down);
			k=getReg();
			fprintf(target_file, "MOV R%d,%d --offset\n",k,(node->binding));
			fprintf(target_file, "ADD R%d,R%d --base+off\n",k,j);
			fprintf(target_file, "MOV R%d,[R%d] --fetch\n",i,k);
			freeReg();
			puts("\t\t\t\t-arr");
			tabs--;
			return i;
			break;
		case nt_PLUS:
			puts("\t\t\t\t+'+'");
			i=codeGen(t->left);
			j=codeGen(t->right);
			fprintf(target_file, "ADD R%d,R%d\n",i,j );
			freeReg();
			puts("\t\t\t\t-'+'");
			tabs--;
			return i;
			break;
		case nt_MUL:
			puts("\t\t\t\t+'*'");
			i=codeGen(t->left);
			j=codeGen(t->right);
			fprintf(target_file, "MUL R%d,R%d\n",i,j );
			freeReg();
			puts("\t\t\t\t-'*'");
			tabs--;
			return i;
			break;
		case nt_MINUS:
			puts("\t\t\t\t+'-'");
			i=codeGen(t->left);
			j=codeGen(t->right);
			fprintf(target_file, "SUB R%d,R%d\n",i,j );
			freeReg();
			puts("\t\t\t\t-'-'");
			tabs--;
			return i;
			break;
		case nt_DIV:
			puts("\t\t\t\t+'/'");
			i=codeGen(t->left);
			j=codeGen(t->right);
			fprintf(target_file, "DIV R%d,R%d\n",i,j );
			freeReg();
			puts("\t\t\t\t-'/'");
			tabs--;
			return i;
			break;
		case nt_MOD:
			puts("\t\t\t\t+'%'");
			i=codeGen(t->left);
			j=codeGen(t->right);
			fprintf(target_file, "MOD R%d,R%d\n",i,j );
			freeReg();
			puts("\t\t\t\t-'%'");
			tabs--;
			return i;
			break;
		case nt_LT:
			puts("\t\t\t\t+'<'");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "LT R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'<'");
			tabs--;
			return i;
			break;
		case nt_LE:
			puts("\t\t\t\t+'<='");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "LE R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'<='");
			tabs--;
			return i;
			break;
		case nt_GT:
			puts("\t\t\t\t+'>'");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "GT R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'>'");
			tabs--;
			return i;
			break;
		case nt_GE:
			puts("\t\t\t\t+'>='");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "GE R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'>='");
			tabs--;
			return i;
			break;
		case nt_EE:
			puts("\t\t\t\t+'=='");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "EQ R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'=='");
			tabs--;
			return i;
			break;
		case nt_NE:
			puts("\t\t\t\t+'!='");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "NE R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'!='");
			tabs--;
			return i;
			break;
		case nt_READ:
			puts("\t\t\t\t+read");
			// printf("%s",t->down->str);
			ret = getReg();
			if(t->down->Lentry==NULL){
				i=codeGen(t->down);
				k=getReg();
				fprintf(target_file,"MOV R%d,%d --Gphy.loc\n",k,t->down->Gentry->binding);
				fprintf(target_file,"ADD R%d,R%d --Gbase+off\n",k,i);
				freeReg();
				ret=getReg();
				ReadReg(k,ret);
				freeReg();
				freeReg();
				break;}
			else{
				j=getReg();
				fetch_local_loc_to(t->down,j);
				/*j=getReg();
				fprintf(target_file, "MOV R%d,BP\n",j);
				fprintf(target_file, "ADD R%d,%d\n",j,LLookup(t->down->str)->binding);*/
				ReadReg(j, ret);
				freeReg();}
			freeReg();
			puts("\t\t\t\t-read");
			break;
		/*case nt_READ://---------old
			puts("\t\t\t\tread");
			// printf("%s",t->down->str);
			ret = getReg();
			if(t->down->Lentry==NULL){
				if(t->down->nt==nt_ARR){
					i=codeGen(t->down->down);
					k=getReg();
					fprintf(target_file,"MOV R%d,%d\n",k,t->down->Gentry->binding);
					fprintf(target_file,"ADD R%d,R%d\n",k,i);
					freeReg();
					ret=getReg();
					ReadReg(k,ret);
					freeReg();
					freeReg();
					break;
				}
				Read(t->down->Gentry->binding + t->num, ret);}
			else{
				j=getReg();
				fprintf(target_file, "MOV R%d,BP\n",j);
				fprintf(target_file, "ADD R%d,%d\n",j,LLookup(t->down->str)->binding);
				ReadReg(j, ret);
				freeReg();}
			freeReg();
			break;*/
		case nt_WRITE:
			puts("\t\t\t\t+write");
			//if((t->down->t)==t_CHAR)
				//printf("%s\n",t->down->str);
				;
			i=codeGen(t->down);
			ret=getReg();
			/*if(t->down->Lentry==NULL || t->down->nt==nt_STR){
				puts("\t\t\t\t global");
				Write(i,ret);}
			else{
				puts("\t\t\t\t local");
				Write(i,ret);}//---------------------------------------------LWrite??*/
			Write(i,ret);
			freeReg();
			freeReg();//--------------------------
			puts("\t\t\t\t-write");
			break;
		case nt_ASGN:
			puts("\t\t\t\t+'='");
			if(LLookup(t->left->str)==NULL){//------------------------
				node=t->left->Gentry;
				if(t->left->nt==nt_SPTR){
					i=codeGen(t->right);
					j=(node->binding+t->left->num);
					k=getReg();
					fprintf(target_file,"MOV R%d,[%d] --Gsptr\n",k,j);
					fprintf(target_file,"MOV [R%d],R%d --Gsptr\n",k,i );
					freeReg();
					freeReg();//---------------------
					;}
				/*else if(t->left->nt==nt_ARR){
					i=codeGen(t->left->down);
					j=codeGen(t->right);
					k=getReg();
					fprintf(target_file,"MOV R%d,%d\n",k,node->binding);
					fprintf(target_file,"ADD R%d,R%d\n",k,i);
					fprintf(target_file,"MOV [R%d],R%d\n",k,j);
					freeReg();
					freeReg();
					freeReg();}*/
				else if(t->left->nt==nt_STR){
					j=(node->binding)+(t->left->num);
					fprintf(target_file,"MOV [%d],\"%s\" --\"str\"\n",j,t->right->str);}
				/*else{
					if((t->left->num)>node->size)
						printf("WARNING:Accessing beyond declaration!\n");
						;
					i=codeGen(t->right);
					j=(node->binding)+(t->left->num);
					fprintf(target_file,"MOV [%d],R%d\n",j,i);
					freeReg();}}*/
				else if(t->left->nt==nt_USER){
					i=codeGen(t->left->down);
					j=codeGen(t->right);
					k=getReg();
					fprintf(target_file, "MOV R%d,%d\n",k,node->binding);
					fprintf(target_file, "ADD R%d,R%d\n",k,i);
					fprintf(target_file, "MOV [R%d],R%d\n",k,j);
					freeReg();
					freeReg();
					freeReg();
				}
				else{
					i=codeGen(t->left);
					j=codeGen(t->right);
					k=getReg();
					fprintf(target_file,"MOV R%d,%d --Gbind\n",k,node->binding);
					fprintf(target_file,"ADD R%d,R%d --Goff\n",k,i);
					fprintf(target_file,"MOV [R%d],R%d --Gasgn\n",k,j);
					freeReg();
					freeReg();
					freeReg();}
				}
			else{//Local
				k=getReg();
				fetch_local_loc_to(t->left,k);
				if(t->left->nt==nt_SPTR){
					i=codeGen(t->right);
					fprintf(target_file,"MOV R%d,[R%d] --Lsptr\n",k,k);
					fprintf(target_file,"MOV [R%d],R%d --Lsptr\n",k,i);
					freeReg();}
				else if(t->left->nt==nt_STR){
					fprintf(target_file,"MOV [R%d],\"%s\" --\"str\"\n",k,t->right->str);}
				else{
					i=codeGen(t->right);
					fprintf(target_file,"MOV [R%d],R%d --Lasgn\n",k,i);
					freeReg();}
				freeReg();}
			puts("\t\t\t\t-'='");
			break;

		case nt_IF:
			puts("\t\t\t\t+if");
			result=codeGen(t->left);
			label1=getLabel();
			fprintf(target_file,"JZ R%d,L%d\n",result,label1);
			freeReg();
			codeGen(t->right);
			fprintf(target_file,"L%d:\n",label1);
			puts("\t\t\t\t-if");
			break;
		case nt_IFELSE:
			puts("\t\t\t\tifelse");
			label1=getLabel();
			label2=getLabel();
			result=codeGen(t->left);
			fprintf(target_file,"JZ R%d,L%d\n",result,label1);
			freeReg();
			codeGen(t->down);
			fprintf(target_file,"JMP L%d\n",label2);
			fprintf(target_file,"L%d:\n",label1);
			codeGen(t->right);
			fprintf(target_file,"L%d:\n",label2);
			puts("\t\t\t\t-ifelse");
			break;
		case nt_WHILE:
			puts("\t\t\t\t+while");
			top++;
			break2[top]=label1=getLabel();
			cont1[top]=label2=getLabel();
			fprintf(target_file,"L%d:\n",label1);
			result=codeGen(t->left);
			fprintf(target_file,"JZ R%d,L%d\n",result,label2);
			freeReg();
			codeGen(t->right);
			fprintf(target_file,"JMP L%d\n",label1);
			fprintf(target_file,"L%d:\n",label2);
			top--;
			puts("\t\t\t\t-while");
			break;
		case nt_BREAK:
			puts("\t\t\t\t+break");
			if(top<0) {puts("\t\t\t\tbreak not in loop");
						;}
			else{puts("\t\t\t\tbreak");
				fprintf(target_file, "JMP L%d\n",break2[top]);}
			puts("\t\t\t\t-break");
			break;
		case nt_CONTINUE:
			puts("\t\t\t\t+cont");
			if(top<0) {puts("\t\t\t\tcontinue not in loop");
						;}
			else{puts("\t\t\t\tcontinue");
				fprintf(target_file, "JMP L%d\n",cont1[top]);}
			puts("\t\t\t\t-cont");
			break;
		case nt_FUNC://-------------------------------------------------------------------
			puts("\t\t\t\t+function");
			regtemp=reg;
			while(reg>-1){
				fprintf(target_file, "PUSH R%d --save.reg\n",reg);
				freeReg();}
			atemp=t->arglist;
			while(atemp){
				i=getReg();
				j=codeGen(atemp);
				fprintf(target_file, "MOV R%d,R%d --arg.val\n",i,j);
				freeReg();
				fprintf(target_file, "PUSH R%d --arg\n",i);
				freeReg();
				atemp=atemp->down;}
			i=getReg();
			fprintf(target_file, "MOV R%d,\"\"\n",i);
			fprintf(target_file, "PUSH R%d --for.ret\n",i);
			freeReg();
			fprintf(target_file, "CALL F%d\n",t->Gentry->flabel);
			fprintf(target_file, "POP R%d --result\n",regtemp+1);
			atemp=t->arglist;
			i=getReg();
			while(atemp){
				fprintf(target_file, "POP R%d --args\n",i==0?19:0);
				atemp=atemp->down;}
			freeReg();
			while(regtemp!=-1){
				regtemp--;
				i=getReg();
				fprintf(target_file, "POP R%d --old.regs\n",i);}
			i=getReg();
			puts("\t\t\t\t-function");
			tabs--;
			return i;
			break;
		case nt_RET:
			puts("\t\t\t\t+ret");
			ltemp=lhead;
			i=getReg();
			while(ltemp!=NULL){
				if(ltemp->binding>0)
					fprintf(target_file, "POP R%d --locals\n",i);
				ltemp=ltemp->next;}
			freeReg();
			j=getReg();
			i=codeGen(t->down);
			fprintf(target_file, "MOV R%d,BP\n",j);
			fprintf(target_file, "SUB R%d,2 --(BP-2)\n",j);
			fprintf(target_file, "MOV [R%d],R%d --sav.result\n",j,i);
			freeReg();//--------------------------------
			freeReg();
			j=getReg();
			fprintf(target_file, "MOV BP,[SP] --old.bp\n");
			fprintf(target_file, "POP R%d --bp\n",j);
			freeReg();
			fprintf(target_file, "RET\n");
			puts("\t\t\t\t-ret");
			break;
		case nt_BRKP:
			puts("\t\t\t\t+brkp");
			fprintf(target_file, "BRKP\n");
			puts("\t\t\t\t-brkp");
			break;
		case nt_EXIT:
			puts("\t\t\t\t+exit");
			i=getReg();
			fprintf(target_file, "MOV R%d, \"Exit\"\n",i);
			fprintf(target_file, "PUSH R%d --\"exit\"\n",i);
			fprintf(target_file, "MOV R%d, \"\"\n",i);
			fprintf(target_file, "PUSH R%d  --\"\"\n",i);
			fprintf(target_file, "PUSH R%d  --\"\"\n",i);
			fprintf(target_file, "PUSH R%d  --\"\"\n",i);
			fprintf(target_file, "PUSH R%d  --\"\"\n",i);
			freeReg();
			fprintf(target_file, "CALL 0\n");
			puts("\t\t\t\t-exit");
			break;
		case nt_INIT:
			puts("\t\t\t\t+init");
			i=getReg();
			init(i);
			freeReg();
			puts("\t\t\t\t-init");
			break;
		case nt_ALLOC:
			puts("\t\t\t\t+alloc");
			if(t->down->Lentry==NULL){
				i=getReg();
				alloc_to(t->num,i);
				fprintf(target_file,"MOV [%d],R%d --Galloc\n",t->down->Gentry->binding+t->down->num,i);}
			else{
				i=getReg();
				alloc_to(t->num,i);
				k=getReg();
				fetch_local_loc_to(t->down,k);
				fprintf(target_file,"MOV [R%d],R%d --Lalloc\n",k,i);
				freeReg();}
			freeReg();
			puts("\t\t\t\t-alloc");
			break;
		case nt_FREE:
			puts("\t\t\t\t+free");
			if(t->down->Lentry==NULL){
				i=codeGen(t->down);
				//j=getReg();
				/*j=*/freee(i);
				freeReg();}
			else{
				//j=getReg();
				i=getReg();
				fetch_local_loc_to(t->down,i);
				/*j=*/freee(i);
				freeReg();}
			puts("\t\t\t\t-free");
			break;
		case nt_USER:
			puts("\t\t\t\t+user");
			//printf("%s\n",t->str);
			i=getReg();
			node=t->Gentry;
			j=codeGen(t->down);
			k=getReg();
			fprintf(target_file, "MOV R%d,%d --offset\n",k,(node->binding));
			fprintf(target_file, "ADD R%d,R%d --base+off\n",k,j);
			fprintf(target_file, "MOV R%d,[R%d] --fetch\n",i,k);
			freeReg();
			puts("\t\t\t\t-user");
			tabs--;
			return i;
			break;
		default:
			printf("\tNO CODE-GEN MATCHING FOUND\ttype:'%d'\n",t->nt);
			exit(1);	
			}
		tabs--;
		puts("\t\t\t\t-done");
		return -1;}
void funcGen(struct Gsymbol *g){
	puts("\t\t\t\t+funcGen");
	fprintf(target_file, "F%d:\n",g->flabel);
	fprintf(target_file, "PUSH BP --caller.bp\n");
	fprintf(target_file, "MOV BP,SP --act.rec\n");
	struct Lsymbol *temp=lhead;
	int i;
	i=getReg();
	while(temp){
		if(temp->binding>0){
			fprintf(target_file, "MOV R%d,\"\" --blank\n",i);
			break;}}
	temp=lhead;
	while(temp){
		if(temp->binding>0)
			fprintf(target_file, "PUSH R%d --for.locals\n",i);
		temp=temp->next;}
	freeReg();
	puts("\t\t\t\t-funcGen");
	;}

void Write(int reg,int ret){
	int t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Write\"\n",t);
	fprintf(target_file, "PUSH R%d--\"write\"\n",t);
	fprintf(target_file, "MOV R%d, -2\n",t);
	fprintf(target_file, "PUSH R%d--(-2)\n",t);
	fprintf(target_file, "PUSH R%d--data\n",reg);
	fprintf(target_file, "MOV R%d,\"\"\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d--ret\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();}

void Read(int addr,int ret){
	int t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Read\"\n",t);
	fprintf(target_file, "PUSH R%d--\"read\"\n",t);
	fprintf(target_file, "MOV R%d, -1\n",t);
	fprintf(target_file, "PUSH R%d--(-1)\n",t);
	fprintf(target_file, "MOV R%d,%d\n",t,addr);
	fprintf(target_file, "PUSH R%d--addr\n",t);
	fprintf(target_file, "MOV R%d, \"\"\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d--ret\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();}
void ReadReg(int reg_addr,int ret){
	int t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Read\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, -1\n",t);
	fprintf(target_file, "PUSH R%d--(-1)\n",t);
	fprintf(target_file, "MOV R%d, R%d\n",t,reg_addr);
	fprintf(target_file, "PUSH R%d--reg.addr\n",t);
	fprintf(target_file, "MOV R%d, \"\"\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d--ret\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();}
void Halt(){
	int t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Exit\"\n",t);
	fprintf(target_file, "PUSH R%d--\"exit\"\n",t);
	fprintf(target_file, "MOV R%d, \"\"\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");}
void Brkp(){
	fprintf(target_file, "BRKP\n");}
void Debug(int i){
	fprintf(target_file,"BRKP\n");
	fprintf(target_file,"BRKP--'%d'\n",i);}
void SDebug(char *func){
	fprintf(target_file,"BRKP\n");
	fprintf(target_file,"BRKP--%s\n",func);}
void init(int ret){
	int t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Heapset\"\n",t);
	fprintf(target_file, "PUSH R%d --\"heapset\"\n",t);
	fprintf(target_file, "MOV R%d, \"\" --blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--ret\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	//ret=getReg();
	fprintf(target_file, "POP R%d--ret\n",ret);
	//freeReg();
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();}
void alloc_to(int size,int i){
	int t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Alloc\"\n",t);
	fprintf(target_file, "PUSH R%d --\"alloc\"\n",t);
	fprintf(target_file, "MOV R%d,R%d\n",t,size);
	fprintf(target_file, "PUSH R%d--size\n",t);
	fprintf(target_file, "MOV R%d, \"\" --blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--ret\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d--ret\n",i);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();}

void freee(int reg_addr){
	int t,ret;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Free\"\n",t);
	fprintf(target_file, "PUSH R%d --\"free\"\n",t);
	fprintf(target_file, "PUSH R%d--pointer\n",reg_addr);
	fprintf(target_file, "MOV R%d, \"\" --blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--ret\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	//ret=getReg();
	fprintf(target_file, "POP R%d--retfree\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();
	//return ret;
	;}
void mismatch(int n, struct Typetable *l, struct Typetable *r){
	printf("line:'%d'\ttype mismatch:nt_%d\n",line,n);
	printf("left:'%s'\n",l->name);
	printf("right:'%s'\n",r->name);
	exit(1);}

/*int evaluate(struct tnode *t){
	switch(t->nt)
	{
		case nt_NODE:
		puts("\t\t\t\tnode");
			evaluate(t->left);
			evaluate(t->right);
			break;
		case nt_PLUS:
		puts("\t\t\t\tplus");
			return evaluate(t->left)+evaluate(t->right);
			break;
		case nt_MUL:
		puts("\t\t\t\tmul");
			return evaluate(t->left)*evaluate(t->right);
			break;
		case nt_MINUS:
		puts("\t\t\t\tminus");
			return evaluate(t->left)-evaluate(t->right);
			break;
		case nt_DIV:
		puts("\t\t\t\tdiv");
			return evaluate(t->left)/evaluate(t->right);
			break;
		case nt_NUM:
		puts("\t\t\t\tnum");
			return t->num;
			break;
		case nt_ID:
		puts("\t\t\t\tid");
				return val[*(t->str)-'a'];
			break;
		case nt_READ:
		puts("\t\t\t\tread");
			scanf("%d",&val[*(t->down->str)-'a']);
			break;
		case nt_WRITE:
		puts("\t\t\t\twrite");
			printf("%d\n",evaluate(t->down));
			break;
		case nt_ASGN:
		puts("\t\t\t\tasgn");
			val[*(t->left->str)-'a']=evaluate(t->right);
			break;
		case nt_LT:
		puts("\t\t\t\tlt");
			return evaluate(t->left)<evaluate(t->right);
			break;
		case nt_LE:
		puts("\t\t\t\tle");
			return evaluate(t->left)<=evaluate(t->right);
			break;
		case nt_GT:
		puts("\t\t\t\tgt");
			return evaluate(t->left)>evaluate(t->right);
			break;
		case nt_GE:
		puts("\t\t\t\tge");
			return evaluate(t->left)>=evaluate(t->right);
			break;
		case nt_EE:
		puts("\t\t\t\tee");
			return evaluate(t->left)==evaluate(t->right);
			break;
		case nt_NE:
		puts("\t\t\t\tne");
			return evaluate(t->left)!=evaluate(t->right);
			break;		
		case nt_IF:
			if(evaluate(t->left))
				evaluate(t->right);
			break;
		case nt_IFELSE:
			if(evaluate(t->left))
				evaluate(t->down);
			else
				evaluate(t->right);
			break;
		case nt_WHILE:
			while(evaluate(t->left))
				evaluate(t->right);
			break;}}	

//*/
void fetch_local_loc_to(struct tnode *t,int i){
	fprintf(target_file, "MOV R%d,BP --BP+?\n",i);
	fprintf(target_file, "ADD R%d,%d --L.loc\n",i,t->Lentry->binding);}
