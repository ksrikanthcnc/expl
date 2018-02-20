struct tnode* createtree(int t, int num,char *str,int nt,struct tnode *l, struct tnode *d,struct tnode *r,struct Gsymbol *gentry,struct tnode *arglist,struct Lsymbol *lentry){
	struct Paramstruct *ptemp;
	struct tnode *atemp,*treetemp;
	switch(nt){
		case nt_NODE:
			break;
		case nt_PLUS:	
		case nt_MINUS:
			if(l->nt==nt_PTR || r->nt==nt_PTR)
				if(	!(l->nt == nt_PTR && (r->nt==nt_PTR || r->nt==nt_NUM))	&&
					!(r->nt == nt_PTR && (l->nt==nt_PTR || l->nt==nt_NUM))){
						mismatch(nt, l->t, r->t);}
			if(l->nt==nt_PTR && r->nt==nt_PTR)
				if(l->t!=r->t)
					mismatch(nt, l->t, r->t);
				else
					t=l->t;
			if(l->nt==nt_PTR)	t=l->t;
			if(r->nt==nt_PTR)	t=r->t;
		case nt_MUL:
		case nt_DIV:
		case nt_MOD:
			if (	(l->t == t_CHAR && l->nt!=nt_PTR) || 
					(r->t == t_CHAR && r->nt!=nt_PTR))
				mismatch(nt, l->t, r->t);
		case nt_LT:
		case nt_LE:
		case nt_GT:
		case nt_GE:
		case nt_EE:
		case nt_NE:
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_NUM:
		case nt_ID:
		case nt_ARR:
		case nt_PTR:
		case nt_STR:
			break;
		case nt_ASGN:
			if(l->nt==nt_PTR && r->nt==nt_FUNC)
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
				mismatch(nt,l->t,r->t);}
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
					if(ptemp->type==t_INPTR && atemp->t==t_INT && atemp->nt==nt_APTR) goto goto1;
					if(ptemp->type==t_CHPTR && atemp->t==t_CHAR && atemp->nt==nt_APTR) goto goto1;
					printf("line:%d\ttype mismatch in Function call at '%d' parameter from right\n",line,param_pos);
					printf("Declared type:'%d'\nCalled type:'%d'\n",ptemp->type,atemp->t);
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
			if(d->nt==nt_APTR)
				t-=4;
			if(t!=d->t)
				mismatch(nt,t,d->t);
		case nt_BRKP:
		case nt_EXIT:
			break;
			}
		
	
	treetemp=(struct tnode *)malloc(sizeof(struct tnode));
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


void GInstall(char *name, int type, int size){
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

void PInstall(char* name, int type){
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

void LInstall(char *name, int type){
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

/*void LocalParam(struct Paramstruct* phead,struct Gsymbol *g){
	struct Paramstruct *pgtemp,*pltemp;
	pgtemp=g->paramlist;
	pltemp=phead;
	while(pgtemp!=NULL && pltemp!=NULL){
		if(strcmp(pgtemp->name,pltemp->name)==0 && pgtemp->type==pltemp->type){
			binding--;
			LInstall(pgtemp->name,pgtemp->type);}
		else{
			printf("line:%d\nParameter Globally Declared:\tname:'%s'\ttype:'%d'\nParameter Locally Declared:\tname:'%s'\ttype:'%d'\n",line,pgtemp->name,pgtemp->type,pltemp->name,pltemp->type);
			exit(1);}
		pltemp=pltemp->next;
		pgtemp=pgtemp->next;}
	if(pgtemp!=NULL || pltemp!=NULL){
		if(pgtemp!=NULL){
			printf("line:%d\tExtra Global Parameters Declared...\n",line);
			while(pgtemp==NULL){
				printf("name:'%s'\ttype:'%d'\n",pgtemp->name,pgtemp->type);
				pgtemp=pgtemp->next;
			}}
		else{
			printf("line:%d\tExtra Local Parameters Declared...\n",line);
			while(pltemp==NULL){
				printf("name:'%s'\ttype:'%d'\n",pltemp->name,pltemp->type);
				pltemp=pltemp->next;}}
	exit(1);}}*/

int generate(FILE *target_file){
	//printf("------------Generating Code------------\n");
	fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(target_file,"MOV SP,%d\n",gbinding-1);
	fprintf(target_file,"MOV BP,%d\n",gbinding);
	fprintf(target_file,"PUSH R0\n");
	//Brkp(target_file);
	fprintf(target_file,"CALL F1000\n");
	Halt(target_file);
	//printf("-------------Generated--------------\n");
	;}

int reg=-1;
int label=0;
int break2[100];
int cont1[100];
int top=-1;

int getReg(){
	reg++;
	/*
	printf("\t\tgotReg:R%d\t",reg);
	for(int s=reg;s>-1;s--) printf(".");
	printf("\n");
	*/
	if(reg>19){printf("Out of registers\n");
				exit(1);}
	return reg;}
void freeReg(){
	reg--;
	/*
	printf("\t\tfreedReg:R%d\t",reg);
	for(int s=reg;s>-1;s--) printf(".");
	printf("\n");
	*/}
int getLabel(){label++;return label;}
//int argtemp=0;
int codeGen(struct tnode *t,FILE *target_file){
	int i,j,k,ret,label1,label2,result,regtemp;
	struct Gsymbol *node,*temp;
	struct tnode *atemp;
	struct Lsymbol *ltemp;
	switch(t->nt){
		case nt_NODE:
			//puts("node");
			//puts("\tleft");
			codeGen(t->left,target_file);
			//puts("\tright");
			codeGen(t->right,target_file);
			break;
		case nt_NUM:
			//puts("num");
			//printf("%d\n",t->num);
			i=getReg();
			fprintf(target_file, "MOV R%d,%d\n",i,t->num);
			return i;
			break;
		case nt_STR:
			//puts("str");
			//printf("%s\n",t->str);
			i=getReg();
			fprintf(target_file, "MOV R%d,%s\n",i,t->str);//----------------
			return i;
			break;
		case nt_ID:
			//puts("id");
			//printf("%s\n",t->str);
			i=getReg();
			if(LLookup(t->str)==NULL){
				j=t->Gentry->binding;
				fprintf(target_file, "MOV R%d,[%d]\n",i,j);}
			else{
				j=getReg();
				fprintf(target_file, "MOV R%d,BP\n",j);
				fprintf(target_file, "ADD R%d,%d\n",j,LLookup(t->str)->binding);
				fprintf(target_file, "MOV R%d,[R%d]\n",i,j);
				freeReg();}
			return i;
			break;
		case nt_PTR:
			//puts("pointer-<var name>");
			//printf("%s\n",t->str);
			i=getReg();
			if(t->Gentry!=NULL){
				fprintf(target_file, "MOV R%d, [%d]\n",i,t->Gentry->binding);}
			else{
				j=getReg();
				fprintf(target_file, "MOV R%d,BP\n",j);
				fprintf(target_file, "ADD R%d,%d\n",j,LLookup(t->str)->binding);
				fprintf(target_file, "MOV R%d,[R%d]\n",i,j);
				freeReg();}
			return i;
			break;
		case nt_APTR:
			//puts("pointer-&");
			//printf("%s\n",t->str);
			i=getReg();
			if(t->Gentry!=NULL){
				fprintf(target_file, "MOV R%d, %d\n",i,t->Gentry->binding+t->num);}
			else{
				j=getReg();
				fprintf(target_file, "MOV R%d,BP\n",j);
				fprintf(target_file, "ADD R%d,%d\n",j,LLookup(t->str)->binding);
				fprintf(target_file, "MOV R%d,R%d\n",i,j);
				freeReg();}
			return i;
			break;
		case nt_SPTR:
			//puts("pointer-*");
			//printf("%s\n",t->str);
			i=getReg();
			if(t->Gentry!=NULL){
				fprintf(target_file, "MOV R%d, [%d]\n",i,t->Gentry->binding+t->num);
				fprintf(target_file, "MOV R%d, [R%d]\n",i,i);}
			else{
				j=getReg();
				fprintf(target_file, "MOV R%d,BP\n",j);
				fprintf(target_file, "ADD R%d,%d\n",j,LLookup(t->str)->binding);
				fprintf(target_file, "MOV R%d,[R%d]\n",i,j);
				fprintf(target_file, "MOV R%d, [R%d]\n",i,i);
				freeReg();}
			return i;
			break;
		case nt_ARR:
			//puts("arr");
			//printf("%s\n",t->str);
			i=getReg();
			node=t->Gentry;
			if((t->num)>node->size)
				printf("WARNING:Accessing beyond declaration!\n");
			j=codeGen(t->down,target_file);
			k=getReg();
			fprintf(target_file, "MOV R%d,%d\n",k,(node->binding));
			fprintf(target_file, "ADD R%d,R%d\n",k,j);
			fprintf(target_file, "MOV R%d,[R%d]\n",i,k);
			freeReg();
			return i;
			break;
		case nt_PLUS:
			//puts("+");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "ADD R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_MUL:
			//puts("*");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "MUL R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_MINUS:
			//puts("-");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "SUB R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_DIV:
			//puts("/");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "DIV R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_MOD:
			//puts("%");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "MOD R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_LT:
			//puts("<");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "LT R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_LE:
			//puts("<=");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "LE R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_GT:
			//puts(">");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "GT R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_GE:
			//puts(">=");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "GE R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_EE:
			//puts("==");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "EQ R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_NE:
			//puts("!=");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "NE R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_READ:
			//puts("read");
			// printf("%s",t->down->str);
			ret = getReg();
			if(t->down->Gentry!=NULL){
				if(t->down->nt==nt_ARR){
					i=codeGen(t->down->down,target_file);
					k=getReg();
					fprintf(target_file,"MOV R%d,%d\n",k,t->down->Gentry->binding);
					fprintf(target_file,"ADD R%d,R%d\n",k,i);
					freeReg();
					ret=getReg();
					LRead(k,target_file,ret);
					freeReg();
					freeReg();
					break;
				}
				Read(t->down->Gentry->binding + t->num, target_file, ret);}
			else{
				j=getReg();
				fprintf(target_file, "MOV R%d,BP\n",j);
				fprintf(target_file, "ADD R%d,%d\n",j,LLookup(t->down->str)->binding);
				LRead(j, target_file, ret);
				freeReg();}
			freeReg();
			break;
		case nt_WRITE:
			//puts("write");
			if((t->down->t)==t_CHAR)
				//printf("%s\n",t->down->str);
				;
			i=codeGen(t->down,target_file);
			ret=getReg();
			if(t->down->Gentry!=NULL || t->down->nt==nt_STR){
				//puts(" global");
				Write(i,target_file,ret);}
			else{
				//puts(" local");
				Write(i,target_file,ret);}//---------------------------------------------LWrite??
			freeReg();
			freeReg();//--------------------------
			break;
		case nt_ASGN:
			//puts("=");
			if(LLookup(t->left->str)==NULL){//------------------------
				node=t->left->Gentry;
				if(t->left->nt==nt_SPTR){
					i=codeGen(t->right,target_file);
					j=(node->binding+t->left->num);
					k=getReg();
					fprintf(target_file,"MOV R%d,[%d]\n",k,j);
					fprintf(target_file,"MOV [R%d],R%d\n",k,i );
					freeReg();
					freeReg();//---------------------
					;}
				else if(t->left->nt==nt_ARR){
					i=codeGen(t->left->down,target_file);
					j=codeGen(t->right,target_file);
					k=getReg();
					fprintf(target_file,"MOV R%d,%d\n",k,node->binding);
					fprintf(target_file,"ADD R%d,R%d\n",k,i);
					fprintf(target_file,"MOV [R%d],R%d\n",k,j);
					freeReg();
					freeReg();
					freeReg();}
				else if(t->left->nt==nt_STR){
					j=(node->binding)+(t->left->num);
					fprintf(target_file,"MOV [%d],\"%s\"\n",j,t->right->str);}
				else{
					if((t->left->num)>node->size)
						printf("WARNING:Accessing beyond declaration!\n");
						;
					i=codeGen(t->right,target_file);
					j=(node->binding)+(t->left->num);
					fprintf(target_file,"MOV [%d],R%d\n",j,i);
					freeReg();}}
			else{//Local
				k=getReg();
				fprintf(target_file, "MOV R%d,BP\n",k);
				fprintf(target_file, "ADD R%d,%d\n",k,t->left->Lentry->binding);
				if(t->left->nt==nt_SPTR){
					i=codeGen(t->right,target_file);
					fprintf(target_file,"MOV R%d,[R%d]\n",k,k);
					fprintf(target_file,"MOV [R%d],R%d\n",k,i);
					freeReg();}
				else if(t->left->nt==nt_STR){
					fprintf(target_file,"MOV [R%d],\"%s\"\n",k,t->right->str);}
				else{
					i=codeGen(t->right,target_file);
					fprintf(target_file,"MOV [R%d],R%d\n",k,i);
					freeReg();}
				freeReg();}
			break;
		case nt_IF:
			//puts("if");
			result=codeGen(t->left,target_file);
			label1=getLabel();
			fprintf(target_file,"JZ R%d,L%d\n",result,label1);
			freeReg();
			codeGen(t->right,target_file);
			fprintf(target_file,"L%d:\n",label1);
			break;
		case nt_IFELSE:
			//puts("ifelse");
			label1=getLabel();
			label2=getLabel();
			result=codeGen(t->left,target_file);
			fprintf(target_file,"JZ R%d,L%d\n",result,label1);
			freeReg();
			codeGen(t->down,target_file);
			fprintf(target_file,"JMP L%d\n",label2);
			fprintf(target_file,"L%d:\n",label1);
			codeGen(t->right,target_file);
			fprintf(target_file,"L%d:\n",label2);
			break;
		case nt_WHILE:
			//puts("while");
			top++;
			break2[top]=label1=getLabel();
			cont1[top]=label2=getLabel();
			fprintf(target_file,"L%d:\n",label1);
			result=codeGen(t->left,target_file);
			fprintf(target_file,"JZ R%d,L%d\n",result,label2);
			freeReg();
			codeGen(t->right,target_file);
			fprintf(target_file,"JMP L%d\n",label1);
			fprintf(target_file,"L%d:\n",label2);
			top--;
			break;
		case nt_BREAK:
			if(top<0) {//puts("break not in loop");
						i=i;}
			else{//puts("break");
				fprintf(target_file, "JMP L%d\n",break2[top]);}
			break;
		case nt_CONTINUE:
			if(top<0) {//puts("continue not in loop");
						i=i;}
			else{//puts("continue");
				fprintf(target_file, "JMP L%d\n",cont1[top]);}
			break;
		case nt_FUNC://-------------------------------------------------------------------
			//puts("function");
			regtemp=reg;
			while(reg>-1){
				fprintf(target_file, "PUSH R%d--save.reg\n",reg);
				freeReg();}
			atemp=t->arglist;
			while(atemp){
				i=getReg();
				j=codeGen(atemp,target_file);
				fprintf(target_file, "MOV R%d,R%d\n",i,j);
				freeReg();
				fprintf(target_file, "PUSH R%d--arg\n",i);
				freeReg();
				atemp=atemp->down;}
			i=getReg();
			fprintf(target_file, "MOV R%d,\"\"\n",i);
			fprintf(target_file, "PUSH R%d--for.ret\n",i);
			freeReg();
			fprintf(target_file, "CALL F%d\n",t->Gentry->flabel);
			fprintf(target_file, "POP R%d--result\n",regtemp+1);
			atemp=t->arglist;
			i=getReg();
			while(atemp){
				fprintf(target_file, "POP R%d--args\n",i==0?19:0);
				atemp=atemp->down;}
			freeReg();
			while(regtemp!=-1){
				regtemp--;
				i=getReg();
				fprintf(target_file, "POP R%d--old.regs\n",i);}
			i=getReg();
			return i;
			break;
		case nt_RET:
			//puts("ret");
			ltemp=lhead;
			i=getReg();
			while(ltemp!=NULL){
				if(ltemp->binding>0)
					fprintf(target_file, "POP R%d--locals\n",i);
				ltemp=ltemp->next;}
			freeReg();
			j=getReg();
			i=codeGen(t->down,target_file);
			fprintf(target_file, "MOV R%d,BP\n",j);
			fprintf(target_file, "SUB R%d,2--(BP-2)\n",j);
			fprintf(target_file, "MOV [R%d],R%d--sav.result\n",j,i);
			freeReg();//--------------------------------
			freeReg();
			j=getReg();
			fprintf(target_file, "MOV BP,[SP]\n");
			fprintf(target_file, "POP R%d--bp\n",j);
			freeReg();
			fprintf(target_file, "RET\n");
			break;
		case nt_BRKP:
			fprintf(target_file, "BRKP\n");
			break;
		case nt_EXIT:
			i=getReg();
			fprintf(target_file, "MOV R%d, \"Exit\"\n",i);
			fprintf(target_file, "PUSH R%d\n",i);
			fprintf(target_file, "MOV R%d, \"\"\n",i);
			fprintf(target_file, "PUSH R%d\n",i);
			fprintf(target_file, "PUSH R%d\n",i);
			fprintf(target_file, "PUSH R%d\n",i);
			fprintf(target_file, "PUSH R%d\n",i);
			freeReg();
			fprintf(target_file, "CALL 0\n");
			break;
		default:
			//puts("\tNO CODE-GEN MATCHING FOUND\n");
			exit(1);	
			}}
void funcGen(struct Gsymbol *g, FILE *target_file){
	fprintf(target_file, "F%d:\n",g->flabel);
	fprintf(target_file, "PUSH BP\n");
	fprintf(target_file, "MOV BP,SP--act.rec\n");
	struct Lsymbol *temp=lhead;
	int i;
	/*if(temp){---------------------------------------------------*/
		i=getReg();
		fprintf(target_file, "MOV R%d,\"\" --blank\n",i);
	while(temp){
		if(temp->binding>0)
			fprintf(target_file, "PUSH R%d--locals\n",i);
		temp=temp->next;}
	freeReg();}

void Write(int reg,FILE* target_file,int ret){
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
/*
void LWrite(int reg,FILE* target_file,int ret){
	int t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Write\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, -2\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d,[R%d]\n",t,reg);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d,\"\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d\n",t);
	fprintf(target_file, "POP R%d\n",t);
	fprintf(target_file, "POP R%d\n",t);
	fprintf(target_file, "POP R%d\n",t);
	freeReg();}
*/
void Read(int addr,FILE* target_file,int ret){
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
void LRead(int reg_addr,FILE* target_file,int ret){
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
void Halt(FILE* target_file){
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
void Brkp(FILE* target_file){
	fprintf(target_file, "BRKP\n");}
void Debrkp(FILE* target_file){
	fprintf(target_file, "BRKP--DEBUG\n");}

void mismatch(int n, int l, int r){
	printf("type mismatch:nt_%d at line:%d\n",n,line);
	printf("left:t_%d\n",l);
	printf("right:t_%d\n",r);
	exit(1);}

int evaluate(struct tnode *t){
	switch(t->nt)
	{
		case nt_NODE:
		//puts("node");
			evaluate(t->left);
			evaluate(t->right);
			break;
		case nt_PLUS:
		//puts("plus");
			return evaluate(t->left)+evaluate(t->right);
			break;
		case nt_MUL:
		//puts("mul");
			return evaluate(t->left)*evaluate(t->right);
			break;
		case nt_MINUS:
		//puts("minus");
			return evaluate(t->left)-evaluate(t->right);
			break;
		case nt_DIV:
		//puts("div");
			return evaluate(t->left)/evaluate(t->right);
			break;
		case nt_NUM:
		//puts("num");
			return t->num;
			break;
		case nt_ID:
		//puts("id");
				return val[*(t->str)-'a'];
			break;
		case nt_READ:
		//puts("read");
			scanf("%d",&val[*(t->down->str)-'a']);
			break;
		case nt_WRITE:
		//puts("write");
			printf("%d\n",evaluate(t->down));
			break;
		case nt_ASGN:
		//puts("asgn");
			val[*(t->left->str)-'a']=evaluate(t->right);
			break;
		case nt_LT:
		//puts("lt");
			return evaluate(t->left)<evaluate(t->right);
			break;
		case nt_LE:
		//puts("le");
			return evaluate(t->left)<=evaluate(t->right);
			break;
		case nt_GT:
		//puts("gt");
			return evaluate(t->left)>evaluate(t->right);
			break;
		case nt_GE:
		//puts("ge");
			return evaluate(t->left)>=evaluate(t->right);
			break;
		case nt_EE:
		//puts("ee");
			return evaluate(t->left)==evaluate(t->right);
			break;
		case nt_NE:
		//puts("ne");
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
/*
void debg(struct Gsymbol *g){
	printf("\t##############\tgsymbol\n");
	if(g==NULL){
		printf("\tNULL\n");
		printf("\t~~~~~~~~\n");
		return;
	}
	printf("\tname:%s\n",g->name);
	printf("\ttype:t_%d\n",g->type);
	printf("\tsize:%d\n",g->size);
	printf("\tbinding:%d\n",g->binding);
	printf("\tarr:%d\n",g->arr);
	printf("\t~~~~~~~~\n");}
void debt(struct tnode *t){
	printf("\t##############\ttnode\t###################\n");
	if(t==NULL){
		printf("\tNULL");
		printf("\t~~~~~~~~\n");
		return;
	}
	printf("\ttype:t_%d\n", t->t);
	printf("\tnum:%d\n", t->num);
	printf("\tstr:%s\n", t->str);
	printf("\tnt:nt_%d\n", t->nt);
	debg(t->Gentry);
	printf("\t..........\n");}

void temp(struct Paramstruct* pghead){
	struct Paramstruct* temp=pghead;
  //while(temp!=NULL){
		printf("name:'%s'\ttype:'%d'\n",temp->name,temp->type);
  //	temp=temp->next;}}
*/
