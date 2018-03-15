#define exit(a); /*printf("line:'%d'\n",line);*/ exit(a);
#include "expr.h"
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
			printf("NO NT MATCHED IN CREATTREE...\n");
			}*/
		
	
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
	gitemp->class=ctype;
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
	TInstall("null",0,NULL);
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
		//printf("\tname:'%s'\tfieldIndex:'%d'\ttype->name:'%s'\n",temp->name,temp->fieldIndex,temp->type->name);
		if(strcmp(temp->name,name)==0){
			//printf("Found!\n");
			return temp;}
		temp=temp->next;}
	//printf("line:'%d':Not found '%s' in type:'%s'\n",line,name,type->name);
	return NULL;}
struct Fieldlist* FLookmember(struct Typetable *type, char *name){
	struct Fieldlist *temp;
	temp=type->fields;
	while(temp!=NULL){
		//printf("\tname:'%s'\tfieldIndex:'%d'\ttype->name:'%s'\n",temp->name,temp->fieldIndex,temp->type->name);
		if(strcmp(temp->name,name)==0){
			//printf("Found!\n");
			return temp;}
		temp=temp->next;}
	//printf("line:'%d':Not found '%s' in type:'%s'\n",line,name,type->name);
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
void CFInstall(/*struct Classtable *cptr, */char *typename, char *name){
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
void CMInstall(/*struct Classtable *cptr, */char *name, struct Typetable *type, struct Paramstruct *Paramlist){
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
int reg=-1,tempreg;
int label=0;
int break2[100];
int cont1[100];
int top=-1;
int readflag=0;
int getReg(){
	reg++;
	//puts("\t\t\t\t+reg++");
#ifdef BUG
	//printf("\t\tgotReg:R%d\t",reg);
	printf("\t\t\t\t+");
	for(int s=reg;s>-1;s--) printf("#");
	printf("\n");
#endif	
	if(reg>19){printf("Out of registers\n");
				exit(1);}
	return reg;}
void freeReg(){
	reg--;
	//puts("\t\t\t\t-reg--");
	if(reg<0){//puts("(All registers free...)");
	;}
#ifdef BUG
	//printf("\t\tfreedReg:R%d\t",reg);
	printf("\t\t\t\t-");
	for(int s=reg;s>-1;s--) printf("#");
	printf("\n");
#endif	
	}
int getLabel(){label++;return label;}
void generate(){
	puts("\t\t\t\t+Generating Code");
	fprintf(target_file,"F%d:\n",TMAIN);
	fprintf(target_file,"MOV SP,%d --start\n",gbinding-1);
	fprintf(target_file,"MOV BP,%d --start\n",gbinding);
	fprintf(target_file,"PUSH R0 --ret.val\n");
	//Brkp(target_file);
	fprintf(target_file,"CALL F%d\n",FMAIN);
	Halt(target_file);
	puts("\t\t\t\t-Generated");
	;}
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
				fprintf(target_file, "MOV R%d,[%d] --Gid\n",i,j);}
			else{
				j=getReg();
				fetch_local_loc_to(t,j);
				fprintf(target_file, "MOV R%d,[R%d] --Lid.fetch\n",i,j);
				freeReg();}
			puts("\t\t\t\t-id");
			tabs--;
			return i;
			break;
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
			puts("\t\t\t\t+'mod'");
			i=codeGen(t->left);
			j=codeGen(t->right);
			fprintf(target_file, "MOD R%d,R%d\n",i,j );
			freeReg();
			puts("\t\t\t\t-'mod'");
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
			readflag=1;
			saveReg();
			if(t->down->Lentry==NULL){
				if(t->down->nt!=nt_ARR)
					i=codeGen(t->down);
				else
					i=codeGen(t->down->down);
				k=getReg();
				if(t->down->nt!=nt_USERROOT){
					fprintf(target_file,"MOV R%d,%d --Rbind\n",k,t->down->Gentry->binding);
					fprintf(target_file,"ADD R%d,R%d --Roff\n",k,i);}
				else{
					fprintf(target_file,"MOV R%d,R%d --Roff\n",k,i);
				}
				freeReg();
				ret=getReg();
				ReadReg(k,ret);
				freeReg();
				freeReg();}
			else{
				j=getReg();
				if(t->down->nt==nt_USERROOT){
					i=codeGen(t->left);
					fprintf(target_file, "MOV R%d,R%d --rluser\n",j,i);
					freeReg();
				}
				else{
					fetch_local_loc_to(t->down,j);}
				ret = getReg();
				ReadReg(j, ret);
				freeReg();
				freeReg();}
			readflag=0;
			restReg();
			puts("\t\t\t\t-read");
			break;
		case nt_WRITE:
			puts("\t\t\t\t+write");
			//if((t->down->t)==t_CHAR)
				//printf("%s\n",t->down->str);
				;
			saveReg();
			i=codeGen(t->down);
			ret=getReg();
			Write(i,ret);
			freeReg();
			freeReg();//--------------------------
			restReg();
			puts("\t\t\t\t-write");

			break;
		case nt_ASGN:
			puts("\t\t\t\t+'='");
			/*if(t->left->class!=NULL && t->left->left->nt==nt_SELF){//self.root=null;
				j=codeGen(t->right);
				i=getReg();
				fprintf(target_file, "MOV R%d,BP --(BP-?)\n",i);
				fprintf(target_file, "ADD R%d, %d --heapbind\n",i,t->left->left->num);
				Debug(i);
				fprintf(target_file, "MOV [R%d],R%d --self\n",i,j);
				k=getReg();
				freeReg();
				freeReg();
				freeReg();
				break;}*/
			if(t->left->Lentry==NULL){//------------------------
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
				else if(t->left->nt==nt_STR){
					j=(node->binding)+(t->left->num);
					fprintf(target_file,"MOV [%d],\"%s\" --\"str\"\n",j,t->right->str);}
				else if(t->left->nt==nt_USERROOT){
					i=codeGen(t->left->left);
					if(t->left->left->nt==nt_SELF){
						fprintf(target_file, "ADD R%d,%d --off\n",i,t->left->num);
						j=codeGen(t->right);
						fprintf(target_file, "MOV [R%d],R%d --asgn\n",i,j);
						freeReg();}
					else{
						fprintf(target_file, "ADD R%d,%d --off\n",i,t->left->num);
						j=codeGen(t->right);
						fprintf(target_file, "MOV [R%d],R%d --asgn\n",i,j);
						freeReg();}
					freeReg();}
				else{
					if(t->left->down!=NULL)
						i=codeGen(t->left->down);
					else{
						i=getReg();
						fprintf(target_file, "MOV R%d,0 --extra\n",i);}
					/*if((t->left->down->num)>node->size)//-------------------------------
						printf("WARNING:Accessing beyond declaration!\n");*/
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
				if(t->left->nt==nt_SPTR){
					fetch_local_loc_to(t->left,k);
					i=codeGen(t->right);
					fprintf(target_file,"MOV R%d,[R%d] --Lsptr\n",k,k);
					fprintf(target_file,"MOV [R%d],R%d --Lsptr\n",k,i);
					freeReg();}
				else if(t->left->nt==nt_STR){
					fetch_local_loc_to(t->left,k);
					fprintf(target_file,"MOV [R%d],\"%s\" --\"str\"\n",k,t->right->str);}
				else if(t->left->nt==nt_USERROOT){
					i=codeGen(t->left->left);
					fprintf(target_file, "ADD R%d,%d --off\n",i,t->left->num);
					j=codeGen(t->right);
					fprintf(target_file, "MOV [R%d],R%d --asgn\n",i,j);
					freeReg();
					freeReg();
				}
				else{
					fetch_local_loc_to(t->left,k);
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
			if(t->class!=NULL && t->left->nt!=nt_SELF){
				i=getReg();
				j=getReg();
				fprintf(target_file,"MOV R%d, %d --clasloc\n",i,t->left->Gentry->binding);
				fprintf(target_file,"MOV R%d,[R%d]\n",j,i);
				fprintf(target_file,"PUSH R%d --clasloc\n",j);
				fprintf(target_file,"ADD R%d, 1 --vfunc\n",i);
				fprintf(target_file,"MOV R%d,[R%d]\n",j,i);
				fprintf(target_file,"PUSH R%d --vfunc\n",j);
				freeReg();
				freeReg();}
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
			if(t->class!=NULL)
				fprintf(target_file, "CALL F%d\n",CMLookup(t->class,t->str)->flabel);
			else
				fprintf(target_file, "CALL F%d\n",t->Gentry->flabel);
			fprintf(target_file, "POP R%d --result\n",regtemp+1);
			atemp=t->arglist;
			i=getReg();
			if(t->class!=NULL && t->left->nt!=nt_SELF){
				fprintf(target_file, "POP R%d --clasargs\n",i==0?19:0);
				fprintf(target_file, "POP R%d --clasargs\n",i==0?19:0);}
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
			j=getReg();
			if(t->down->Lentry==NULL){
				fprintf(target_file, "MOV R%d, %d\n",j,t->down->Gentry->binding);
				fprintf(target_file, "MOV R%d,R%d --ret\n",j,i);}
			else{fetch_local_loc_to(t->down,j);
				fprintf(target_file, "MOV [R%d],R%d --ret\n",j,i);}
			freeReg();
			freeReg();
			puts("\t\t\t\t-init");
			break;
		case nt_ALLOC:
			puts("\t\t\t\t+alloc");
			saveReg();
			i=getReg();
			if(t->down->Lentry==NULL){
				alloc_to(t->num,i);
				if(t->down->down==NULL){
					fprintf(target_file,"MOV [%d],R%d --Galloc\n",t->down->Gentry->binding+t->down->num,i);}
				else{
					j=codeGen(t->down->down);
					fprintf(target_file, "ADD R%d,%d --base+off\n",j,t->down->num);
					fprintf(target_file,"MOV [R%d],R%d --Galloc\n",j,i);
					freeReg();}}
			else{
				alloc_to(t->num,i);
				if(t->down->down==NULL){
					j=getReg();
					fetch_local_loc_to(t->down,j);}
				else{
					j=codeGen(t->down->down);
					fprintf(target_file, "ADD R%d,%d --base+off\n",j,t->down->num);}
				fprintf(target_file,"MOV [R%d],R%d --Lalloc\n",j,i);
				freeReg();}
			freeReg();
			restReg();
			puts("\t\t\t\t-alloc");
			break;
		case nt_FREE:
			puts("\t\t\t\t+free");
			saveReg();
			if(t->down->Lentry==NULL){
				i=codeGen(t->down);
				//j=getReg();
				/*j=*/freee(i);
				freeReg();}
			else{
				//j=getReg();
				i=getReg();
				fetch_local_loc_to(t->down,i);
				fprintf(target_file,"MOV R%d,[R%d]\n",i,i);
				/*j=*/freee(i);
				freeReg();}
			restReg();
			puts("\t\t\t\t-free");
			break;
		case nt_USERROOT:
			puts("\t\t\t\t+user");
			//printf("%s\n",t->str);
			j=codeGen(t->left);
			k=getReg();
			/*fprintf(target_file, "MOV R%d,[R%d] --user\n",k,j);
			freeReg();*/
			fprintf(target_file, "ADD R%d,%d --off\n",j,t->num);
			if(!readflag)
				fprintf(target_file, "MOV R%d,[R%d] --fetch\n",k,j);
			fprintf(target_file, "MOV R%d,[R%d] --user\n",j,j);
			puts("\t\t\t\t-user");
			freeReg();
			tabs--;
			return j;
			break;
		case nt_USERNODE:
			puts("\t\t\t\t+usernode");
			if(t->left==NULL){//root node
				puts("\t\t\t\t-user");
				if(t->Lentry==NULL){
					i=getReg();
					fprintf(target_file,"MOV R%d,[%d] --groot\n",i,t->Gentry->binding);
					tabs--;
					puts("\t\t\t\t-usernode");
					return i;}
				else{
					j=getReg();
					i=getReg();
					fetch_local_loc_to(t,i);
					fprintf(target_file, "MOV R%d,[R%d] --lroot\n",j,i);
					freeReg();
					tabs--;
					puts("\t\t\t\t-usernode");
					return j;}}
			else{
				j=codeGen(t->left);
				fprintf(target_file, "ADD R%d,%d --addr\n",j,t->num);
				fprintf(target_file, "MOV R%d,[R%d] --addr\n",j,j);
				tabs--;
				puts("\t\t\t\t-usernode");
				return j;}
			break;
		case nt_TRUE:
			puts("\t\t\t\t+true");
			i=getReg();
			fprintf(target_file, "MOV R%d, 1 --true\n",i);
			tabs--;
			puts("\t\t\t\t-true");
			return i;
		case nt_FALSE:
			puts("\t\t\t\t+false");
			i=getReg();
			fprintf(target_file, "MOV R%d, 0 --false\n",i);
			tabs--;
			puts("\t\t\t\t-false");
			return i;
		case nt_NOT:
			puts("\t\t\t\t+not");
			label1=getLabel();
			label2=getLabel();
			j=codeGen(t->down);
			i=getReg();
			fprintf(target_file, "MOV R%d,0 --not\n",i);
			fprintf(target_file, "EQ R%d,R%d --not\n",j,i);
			freeReg();
			fprintf(target_file, "JZ R%d,L%d\n",j,label1);
			fprintf(target_file, "MOV R%d, 1 --set1\n",j);
			fprintf(target_file, "JMP L%d\n",label2);
			fprintf(target_file, "L%d:\n",label1);
			fprintf(target_file, "MOV R%d,0 --set0\n",j);
			fprintf(target_file, "L%d:\n",label2);
			tabs--;
			puts("\t\t\t\t-not");
			return j;
		case nt_AND:
			puts("\t\t\t\t+and");
			label1=getLabel();
			label2=getLabel();
			k=getReg();
			fprintf(target_file, "MOV R%d,1 --and\n",k);
			i=codeGen(t->left);
			fprintf(target_file, "EQ R%d,R%d --cond1?\n",i,k);
			fprintf(target_file, "JZ R%d,L%d\n",i,label1);
			freeReg();
			fprintf(target_file, "MOV R%d,1 \n",k);
			j=codeGen(t->right);
			fprintf(target_file, "EQ R%d,R%d --cond2?\n",j,k);
			fprintf(target_file, "JZ R%d,L%d\n",j,label1);
			freeReg();
			freeReg();
			result=getReg();
			fprintf(target_file, "MOV R%d,1 --ans1\n",result);
			fprintf(target_file, "JMP L%d\n",label2);
			fprintf(target_file, "L%d:\n",label1);
			fprintf(target_file, "MOV R%d,0 --ans0\n",result);
			fprintf(target_file, "L%d:\n",label2);
			tabs--;
			puts("\t\t\t\t-and");
			return result;
		case nt_OR:
			puts("\t\t\t\t+or");
			label1=getLabel();
			label2=getLabel();
			k=getReg();
			fprintf(target_file, "MOV R%d,0 --or\n",k);
			i=codeGen(t->left);
			fprintf(target_file, "EQ R%d,R%d --cond1?\n",i,k);
			fprintf(target_file, "JZ R%d,L%d\n",i,label1);
			freeReg();
			fprintf(target_file, "MOV R%d,0 \n",k);
			j=codeGen(t->right);
			fprintf(target_file, "EQ R%d,R%d --cond2?\n",j,k);
			fprintf(target_file, "JZ R%d,L%d\n",j,label1);
			freeReg();
			freeReg();
			result=getReg();
			fprintf(target_file, "MOV R%d,0 --ans0\n",result);
			fprintf(target_file, "JMP L%d\n",label2);
			fprintf(target_file, "L%d:\n",label1);
			fprintf(target_file, "MOV R%d,1 --ans1\n",result);
			fprintf(target_file, "L%d:\n",label2);
			tabs--;
			puts("\t\t\t\t-or");
			return result;
		case nt_NUL:
			i=getReg();
			fprintf(target_file, "MOV R%d, \"null\" --null\n",i);
			return i;
		case nt_SELF:
			puts("\t\t\t\t+self");
			i=getReg();
			fprintf(target_file, "MOV R%d,BP --(BP-?)\n",i);
			fprintf(target_file, "ADD R%d, %d --heapbind\n",i,t->num-1);
			fprintf(target_file, "MOV R%d,[R%d] --self\n",i,i);
			tabs--;
			puts("\t\t\t\t-self");
			return i;
			break;		
		case nt_NEW:
			puts("\t\t\t\t+new");
			saveReg();
			i=getReg();
			fprintf(target_file, "MOV R%d,%d --Gbinding\n",i,t->left->Gentry->binding);
			j=getReg();
			alloc_to(8,j);
			fprintf(target_file, "MOV [R%d],R%d\n",i,j);
			freeReg();
			fprintf(target_file, "ADD R%d, 1 --func\n",i);
			fprintf(target_file, "MOV [R%d], %d --vfunc\n",i,4096+8*t->right->class->index);
			freeReg();
			restReg();
			tabs--;
			puts("\t\t\t\t-new");
			break;
		case nt_DELETE:
			puts("\t\t\t\t+delete");
			saveReg();
			i=codeGen(t->down);
			freee(i);
			freeReg();
			restReg();
			tabs--;
			puts("\t\t\t\t-delete");
			break;
		default:
			printf("\tNO CODE-GEN MATCHING FOUND\ttype:'%d'\n",t->nt);
			exit(1);	
			}
		tabs--;
		puts("\t\t\t\t-done");
		return -1;}
void funcGen(char *g){
	puts("\t\t\t\t+funcGen");
	if(GLookup(g)!=NULL){
		fprintf(target_file, "F%d:\n",GLookup(g)->flabel);
		fprintf(target_file, "PUSH BP --caller.bp\n");
		fprintf(target_file, "MOV BP,SP --act.rec\n");
		struct Lsymbol *temp=lhead;
		int i;
		i=getReg();
		while(temp){
			if(temp->binding>0){
				fprintf(target_file, "MOV R%d,\"\" --blank\n",i);
				break;}
			temp=temp->next;}
		temp=lhead;
		while(temp){
			if(temp->binding>0)
				fprintf(target_file, "PUSH R%d --for.locals\n",i);
			temp=temp->next;}
		freeReg();}
	else{
		fprintf(target_file, "F%d:\n",CMLookup(class,g)->flabel);
		fprintf(target_file, "PUSH BP --caller.bp\n");
		fprintf(target_file, "MOV BP,SP --act.rec\n");
		struct Lsymbol *temp=lhead;
		int i;
		i=getReg();
		while(temp){
			if(temp->binding>0){
				fprintf(target_file, "MOV R%d,\"\" --blank\n",i);
				break;}
			temp=temp->next;}
		temp=lhead;
		while(temp){
			if(temp->binding>0)
				fprintf(target_file, "PUSH R%d --for.locals\n",i);
			temp=temp->next;}
		freeReg();}
	puts("\t\t\t\t-funcGen");
	;}
void Write(int reg,int ret){
	int t;
	puts("\t\t\t\t(write)");
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
	freeReg();
	puts("\t\t\t\t(write)");
	;}
void ReadReg(int reg_addr,int ret){
	int t;
	puts("\t\t\t\tread");
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
	freeReg();
	puts("\t\t\t\t");
	;}
void Halt(){
	int t;
	puts("\t\t\t\t");
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Exit\"\n",t);
	fprintf(target_file, "PUSH R%d--\"exit\"\n",t);
	fprintf(target_file, "MOV R%d, \"\"\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	puts("\t\t\t\t");
	;}
void Brkp(){
	puts("\t\t\t\t");
	fprintf(target_file, "BRKP\n");
	puts("\t\t\t\t");
	;}
void Debug(int i){
	puts("\t\t\t\t");
	fprintf(target_file,"BRKP\n");
	fprintf(target_file,"BRKP--'%d'\n",i);
	puts("\t\t\t\t");
	;}
void init(int ret){
	int t;
	puts("\t\t\t\t");
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
	fprintf(target_file, "POP R%d--ret\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();
	puts("\t\t\t\t");
	;}
void alloc_to(int size,int i){
	int t;
	puts("\t\t\t\t");
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Alloc\"\n",t);
	fprintf(target_file, "PUSH R%d --\"alloc\"\n",t);
	fprintf(target_file, "MOV R%d,%d\n",t,size);
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
	freeReg();
	puts("\t\t\t\t");
	;}
void freee(int reg_addr){
	int t,ret;
	puts("\t\t\t\t");
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
	fprintf(target_file, "POP R%d--retfree\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();
	puts("\t\t\t\t");
	;}
void mismatch(int n, struct Typetable *l, struct Typetable *r){
	printf("line:'%d'\ttype mismatch:nt_%d\n",line,n);
	printf("left:'%s'\n",l->name);
	printf("right:'%s'\n",r->name);
	exit(1);}
void fetch_local_loc_to(struct tnode *t,int i){
	puts("\t\t\t\t");
	fprintf(target_file, "MOV R%d,BP --BP+?\n",i);
	fprintf(target_file, "ADD R%d,%d --L.loc\n",i,t->Lentry->binding);
	puts("\t\t\t\t");
	;}
void saveReg(){
	tempreg=reg;
	#ifdef BUG
		if(reg>-1){
			puts("\t\t\t\tsaving regs");}
	#endif
	while(reg>-1){
		fprintf(target_file, "PUSH R%d --save.reg\n",reg);
		freeReg();}}
void restReg(){
	int t;
	#ifdef BUG
		if(reg>-1){
			puts("\t\t\t\trestoring regs");}
	#endif
	while(tempreg!=-1){
		tempreg--;
		t=getReg();
		fprintf(target_file, "POP R%d --old.regs\n",t);}}
//
/*
void CInstall()
*/