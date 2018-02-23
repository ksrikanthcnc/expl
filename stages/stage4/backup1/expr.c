struct tnode* createtree(int t, int num,char *str,int nt,struct tnode *l, struct tnode *d,struct tnode *r){
	switch(nt){
		case nt_NODE:
			break;
		case nt_PLUS:	
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_MUL:
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_MINUS:
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_DIV:
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_MOD:
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_NUM:
			break;
		case nt_ID:
			break;
		case nt_ARR:/*
			if(num==1)
				if(t->Gentry->arr==1)
					break;
			else if(num==2)
				if(t->Gentry->arr==2)
					break;
			else{
				printf("Problem with arrays!\n");
				exit(1);
			}*/
			break;
		case nt_STR:
			break;
		case nt_ASGN:
			if(!(l->t==t_CHAR||l->t==t_ARR)||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_LT:
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_LE:
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_GT:
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_GE:
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_EE:
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_NE:
			if(l->t==t_BOOL||r->t==t_BOOL)
				mismatch(nt,l->t,r->t);
			break;
		case nt_IF:
			if(l->t!=t_BOOL)
				mismatch(nt,l->t,-1);
			break;
		case nt_IFELSE:
			if(l->t!=t_BOOL)
				mismatch(nt,l->t,-1);
			break;
		case nt_WHILE:
			if(l->t!=t_BOOL)
				mismatch(nt,l->t,-1);
			break;}
	
	struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
	temp->num=num;
	temp->t=t;
	temp->nt=nt;
	if(str!=NULL)
		temp->str=strdup(str);
	else
		temp->str=NULL;
	//temp->Gentry=NULL;
	temp->left=l;
	temp->right=r;
	temp->down=d;
	return temp;}


struct Gsymbol *Lookup(char* name){
//	printf("Searching symbol table...\n");
	struct Gsymbol* temp;
	temp=head;
	while(temp!=tail){
//		printf("name:'%s'\ttype:'%d'\tsize:'%d'\tarr:%d\tarr1:%d\t:arr2:%d\n",temp->name,temp->type,temp->size,temp->arr,temp->arr1,temp->arr2);
		if(strcmp(temp->name,name)==0){
//			printf("Found!\n");
			return temp;}
		temp=temp->next;}
//	printf("Not found...\n");
	return NULL;}
	
void Install(char *name, int type, int size){
//	printf("Install-ing in Symbol table...\n");
	if(Lookup(name)!=NULL){
		printf("variable:'%s' redeclared\n",name);
		exit(1);
	}
	tail->name=name;
	tail->type=type;
	tail->size=size;
	tail->binding=binding;
	binding=binding+size;
//	printf("New entry is----\n");
//	printf("name:'%s'\ttype:'%d'\tsize:'%d'\tarr:%d\n",tail->name,tail->type,tail->size,tail->arr);
	struct Gsymbol* temp=malloc(sizeof(struct Gsymbol));
	temp->next=NULL;
	tail->next=temp;
	tail=temp;
//	printf("Install-ed...\n");
	;}

int generate(struct tnode *t,FILE *target_file){
	//printf("------------Generating Code------------\n");
	fprintf(target_file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(target_file,"MOV SP,%d\n",binding);
	Brkp(target_file);
	codeGen(t,target_file);
	Debrkp(target_file);
	Halt(target_file);
	//printf("-------------Generated--------------\n");
	;}

int reg=-1;
int label=0;
int getReg(){
	reg++;
	if(reg>19){printf("Out of registers\n");
				exit(1);}
	return reg;}
void freeReg(){reg--;}
int getLabel(){label++;return label;}

int codeGen(struct tnode *t,FILE *target_file){
	int i,j,k,ret,label1,label2,result;
	struct Gsymbol *node;
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
			fprintf(target_file, "MOV R%d,%s\n",i,Lookup(t->str)->binding);//----------------
			return i;
			break;
		case nt_ID:
			//puts("id");
			//printf("%s\n",t->str);
			i=getReg();
			if(Lookup(t->str)==NULL){
				printf("Undeclared identifier:%s\n",t->str);
				exit(1);}
			fprintf(target_file, "MOV R%d,[%d]\n",i,Lookup(t->str)->binding);
			return i;
			break;
		case nt_ARR:
			//puts("arr");
			//printf("%s\n",t->str);
			i=getReg();
			node=Lookup(t->str);
			if(node==NULL){
				printf("Undeclared identifier:%s\n",t->str);
				exit(1);}
			if((node->binding)+(t->num)>node->size)
				printf("WARNING:Accessing beyond declaration!\n");
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
		case nt_READ:
			//puts("read");
			//printf("%s",t->down->str);
			ret=getReg();
			if(Lookup(t->down->str)==NULL){
				printf("Undeclared identifier:%s\n",t->down->str);
				exit(1);}
			Read(Lookup(t->down->str)->binding+t->num,target_file,ret);
			freeReg();
			break;
		case nt_WRITE:
			//puts("write");
			if((t->down->t)==t_CHAR)
				//printf("%s\n",t->down->str);
			i=codeGen(t->down,target_file);
			ret=getReg();
			Write(i,target_file,ret);
			freeReg();
			break;
		case nt_ASGN:
			//puts("=");
			i=codeGen(t->right,target_file);
			node=Lookup(t->left->str);
			if(node==NULL){
				printf("Undeclared identifier:%s\n",t->str);
				exit(1);}
			if((node->binding)+(t->num)>node->size)
				printf("WARNING:Accessing beyond declaration!\n");
			fprintf(target_file,"MOV [%d],R%d\n",(node->binding)+(t->num),i );
			freeReg();
			break;
		case nt_LT:
			//puts("<");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"LT R%d,R%d\n",i,j);
			freeReg();
			return i;
			break;
		case nt_LE:
			//puts("<=");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"LE R%d,R%d\n",i,j);
			freeReg();
			return i;
			break;
		case nt_GT:
			//puts(">");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"GT R%d,R%d\n",i,j);
			freeReg();
			return i;
			break;
		case nt_GE:
			//puts(">=");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"GE R%d,R%d\n",i,j);
			freeReg();
			return i;
			break;
		case nt_EE:
			//puts("==");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"EQ R%d,R%d\n",i,j);
			freeReg();
			return i;
			break;
		case nt_NE:
			//puts("!=");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file,"NE R%d,R%d\n",i,j);
			freeReg();
			return i;
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
			label1=getLabel();
			label2=getLabel();
			fprintf(target_file,"L%d:\n",label1);
			result=codeGen(t->left,target_file);
			fprintf(target_file,"JZ R%d,L%d\n",result,label2);
			freeReg();
			codeGen(t->right,target_file);
			fprintf(target_file,"JMP L%d\n",label1);
			fprintf(target_file,"L%d:\n",label2);
			break;}}

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
	freeReg();}
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
	freeReg();}
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
	fprintf(target_file, "CALL 0\n");}
void Brkp(FILE* target_file){
	fprintf(target_file, "BRKP\n");}
void Debrkp(FILE* target_file){
	fprintf(target_file, "BRKP--DEBUG\n");}

void mismatch(int n, int l, int r){
	printf("type mismatch:%d\n",n);
	printf("left:%d\n",l);
	if(r!=-1)
	printf("right:%d\n",r);
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
		/*	if(val[*(t->str)-'a']!=NULL)
			else
			{
				printf("error\n");
				exit(1);
			}
		*/
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
			break;

	}}	

