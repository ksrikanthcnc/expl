struct tnode* createtree(int t, int num,char *str,int nt,struct tnode *l, struct tnode *d,struct tnode *r)
{
	switch(nt)
	{
		case nt_NODE:
			break;
		case nt_PLUS:	
			if(l->t==t_BOOL||r->t==t_BOOL)
			{		printf("t mismatch1\n"); exit(1);}
			break;
		case nt_MUL:
			if(l->t==t_BOOL||r->t==t_BOOL)
			{		printf("t mismatch2\n"); exit(1);}
			break;
		case nt_MINUS:
			if(l->t==t_BOOL||r->t==t_BOOL)
			{		printf("t mismatch3\n"); exit(1);}
			break;
		case nt_DIV:
			if(l->t==t_BOOL||r->t==t_BOOL)
			{		printf("t mismatch4\n"); exit(1); }
			break;
		case nt_NUM:
			break;
		case nt_ID:
			break;
		case nt_ASGN:
			if(l->nt!=nt_ID||r->t==t_BOOL)
			{		printf("t mismatch7\n"); exit(1); }
			break;
		case nt_LT:
			if(l->t==t_BOOL||r->t==t_BOOL)
			{		printf("t mismatch8\n"); exit(1);}
			break;
		case nt_LE:
			if(l->t==t_BOOL||r->t==t_BOOL)
			{		printf("t mismatch9\n");	exit(1);}
			break;
		case nt_GT:
			if(l->t==t_BOOL||r->t==t_BOOL)
			{		printf("t mismatch10\n"); exit(1);}
			break;
		case nt_GE:
			if(l->t==t_BOOL||r->t==t_BOOL)
			{		printf("t mismatch11\n"); exit(1);}
			break;
		case nt_EE:
			if(l->t==t_BOOL||r->t==t_BOOL)
			{		printf("t mismatch12\n"); exit(1);}
			break;
		case nt_NE:
			if(l->t==t_BOOL||r->t==t_BOOL)
			{		printf("t mismatch13\n"); exit(1);}
			break;
		case nt_IF:
			if(l->t!=t_BOOL)
			{		printf("t mismatch14\n"); exit(1);}
			break;
		case nt_IFELSE:
			if(l->t!=t_BOOL)
			{		printf("t mismatch14\n"); exit(1);}
			break;
		case nt_WHILE:
			if(l->t!=t_BOOL)
			{		printf("t mismatch15\n");	exit(1);}
			break;
	}
	
	
	struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
	temp->num=num;
	temp->t=t;
	temp->nt=nt;
	if(str!=NULL){
		temp->str=strdup(str);
		temp->Gentry=Lookup(temp->str);}
	else
		temp->str=NULL;
	//temp->Gentry=NULL;
	temp->left=l;
	temp->right=r;
	temp->down=d;
	return temp;
}

int evaluate(struct tnode *t)
{
	switch(t->nt)
	{
		case nt_NODE:
		puts("node");
			evaluate(t->left);
			evaluate(t->right);
			break;
		case nt_PLUS:
		puts("plus");
			return evaluate(t->left)+evaluate(t->right);
			break;
		case nt_MUL:
		puts("mul");
			return evaluate(t->left)*evaluate(t->right);
			break;
		case nt_MINUS:
		puts("minus");
			return evaluate(t->left)-evaluate(t->right);
			break;
		case nt_DIV:
		puts("div");
			return evaluate(t->left)/evaluate(t->right);
			break;
		case nt_NUM:
		puts("num");
			return t->num;
			break;
		case nt_ID:
		puts("id");
				return val[*(t->str)-'a'];
/*			if(val[*(t->str)-'a']!=NULL)
			else
			{
				printf("error\n");
				exit(1);
			}
*/
			break;
		case nt_READ:
		puts("read");
			scanf("%d",&val[*(t->down->str)-'a']);
			break;
		case nt_WRITE:
		puts("write");
			printf("%d\n",evaluate(t->down));
			break;
		case nt_ASGN:
		puts("asgn");
			val[*(t->left->str)-'a']=evaluate(t->right);
			break;
		case nt_LT:
		puts("lt");
			return evaluate(t->left)<evaluate(t->right);
			break;
		case nt_LE:
		puts("le");
			return evaluate(t->left)<=evaluate(t->right);
			break;
		case nt_GT:
		puts("gt");
			return evaluate(t->left)>evaluate(t->right);
			break;
		case nt_GE:
		puts("ge");
			return evaluate(t->left)>=evaluate(t->right);
			break;
		case nt_EE:
		puts("ee");
			return evaluate(t->left)==evaluate(t->right);
			break;
		case nt_NE:
		puts("ne");
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
			break;

	}
}	
////-----------------------symbol table construction
struct Gsymbol *Lookup(char* name){
	printf("Searching...\n");
	struct Gsymbol* temp;
	temp=head;
	while(temp!=tail){
//		printf("name:'%s'\ttype:'%s'\tsize:'%d'\n",temp->name,temp->type,temp->size);
		if(strcmp(temp->name,name)==0){
			printf("Found!\n");
			return temp;}
		temp=temp->next;
	}
	printf("not found...\n");
	return NULL;
}

void Install(char *name, int type, int size){
	printf("Install-ing...\n");
	if(Lookup(name)!=NULL){
		printf("variable:'%s' redeclared\n",name);
		exit(1);
	}
	tail->name=name;
	tail->type=type;
	tail->size=size;
	printf("name:'%s'\ttype:'%d'\tsize:'%d'\n",tail->name,tail->type,tail->size);
	struct Gsymbol* temp=malloc(sizeof(struct Gsymbol));
	temp->next=NULL;
	tail->next=temp;
	tail=temp;
	printf("Install-ed\n");
}

//code gen-------------------------------------------------------------------------------------------------

int generate(struct tnode *t,FILE *target_file)
{
	fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
	fprintf(target_file,"MOV SP,4200\n");
	Brkp(target_file);
	codeGen(t,target_file);
	Debrkp(target_file);
	Halt(target_file);
}

int reg=-1;
int label=0;
int getReg(){
	reg++;
	if(reg>19){
		printf("Out of registers\n");
		exit(1);}
	return reg;
}

void freeReg(){reg--;}
int getLabel(){label++;return label;}

int codeGen(struct tnode *t,FILE *target_file)
{
	int i,j,k,ret,label1,label2,result;
	switch(t->nt)
	{
		case nt_NODE:
			codeGen(t->left,target_file);
			codeGen(t->right,target_file);
			break;
		case nt_NUM:
			i=getReg();
			fprintf(target_file, "MOV R%d,%d\n",i,t->num);
			return i;
			break;
		case nt_ID:
			i=getReg();
			fprintf(target_file, "MOV R%d,[%d]\n",i,4096+*(t->str)-'a');
			return i;
			break;
		case nt_PLUS:
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "ADD R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_MUL:
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "MUL R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_MINUS:
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "SUB R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_DIV:
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "DIV R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_READ:
			ret=getReg();
			Read(4096+*(t->left->str)-'a',target_file,ret);
			freeReg();
			break;
		case nt_WRITE:
			i=codeGen(t->left,target_file);
			ret=getReg();
			Write(i,target_file,ret);
			freeReg();
			break;
		case nt_ASGN:
			i=codeGen(t->right,target_file);
			fprintf(target_file,"MOV [%d],R%d\n",4096+*(t->left->str)-'a',i );
			freeReg();
			break;
		case nt_LT:
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"LT R%d,R%d\n",i,j);
			freeReg();
			return i;
			break;
		case nt_LE:
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"LE R%d,R%d\n",i,j);
			freeReg();
			return i;
			break;
		case nt_GT:
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"GT R%d,R%d\n",i,j);
			freeReg();
			return i;
			break;
		case nt_GE:
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"GE R%d,R%d\n",i,j);
			freeReg();
			return i;
			break;
		case nt_EE:
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"EQ R%d,R%d\n",i,j);
			freeReg();
			return i;
			break;
		case nt_NE:
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"NE R%d,R%d\n",i,j);
			freeReg();
			return i;
			break;
		case nt_IF:
			result=codeGen(t->left,target_file);
			label1=getLabel();
			fprintf(target_file,"JZ R%d,L%d\n",result,label1);
			freeReg();
			codeGen(t->right,target_file);
			fprintf(target_file,"L%d:\n",label1);
			break;
		case nt_IFELSE:
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
			label1=getLabel();
			label2=getLabel();
			fprintf(target_file,"L%d:\n",label1);
			result=codeGen(t->left,target_file);
			fprintf(target_file,"JZ R%d,L%d\n",result,label2);
			freeReg();
			codeGen(t->right,target_file);
			fprintf(target_file,"JMP L%d\n",label1);
			fprintf(target_file,"L%d:\n",label2);
			break;
	}
}




void Write(int reg,FILE* target_file,int ret){
	int t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Write\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, -2\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",reg);
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
	freeReg();
}

void Read(int addr,FILE* target_file,int ret){
	int t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Read\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, -1\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, %d\n",t,addr);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, \"\"\n",t);
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
	freeReg();
}

void Halt(FILE* target_file){
	int t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Exit\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, \"\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
}

void Brkp(FILE* target_file){
	fprintf(target_file, "BRKP\n");
}

void Debrkp(FILE* target_file){
	fprintf(target_file, "BRKP--DEBUG\n");
}





