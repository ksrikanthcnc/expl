struct tnode* createtree(int t, int num,char *str,int nt,struct tnode *l, struct tnode *d,struct tnode *r,struct Gsymbol *gentry){
	switch(nt){
		case nt_NODE:
			break;
		case nt_PLUS:	
		case nt_MINUS:
			if(	!(l->nt == nt_PTR && (r->nt==nt_PTR || r->nt==nt_NUM))	&&
				!(r->nt == nt_PTR && (l->nt==nt_PTR || l->nt==nt_NUM)))
					mismatch(nt, l->t, r->t);
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
			if(l->t!=t_BOOL)
				{printf("CHECK:Impossible mismatch\n");mismatch(nt,l->t,-1);}
			break;}
		
	
	struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
	temp->num=num;
	temp->t=t;
	temp->nt=nt;
	if(str!=NULL)
		temp->str=strdup(str);
	else
		temp->str=NULL;
	temp->Gentry=gentry;
	temp->left=l;
	temp->right=r;
	temp->down=d;
	return temp;}


struct Gsymbol *Lookup(char* name){
	//printf("Searching symbol table...\n");
	struct Gsymbol* temp;
	temp=head;
	while(temp!=tail){
		//printf("name:'%s'\ttype:'%d'\tsize:'%d'\tarr:%d\n",temp->name,temp->type,temp->size,temp->arr);
		if(strcmp(temp->name,name)==0){
			//printf("Found!\n");
			return temp;}
		temp=temp->next;}
	//printf("Not found...\n");
	return NULL;}
	
void Install(char *name, int type, int size){
	//printf("Install-ing in Symbol table...\n");
	if(Lookup(name)!=NULL){
		printf("variable:'%s' redeclared\n",name);
		exit(1);
	}
	tail->name=name;
	tail->type=type;
	tail->size=size;
	tail->binding=binding;
	binding=binding+size;
	//printf("New entry is----\n");
	//printf("name:'%s'\ttype:'%d'\tsize:'%d'\tarr:%d\n",tail->name,tail->type,tail->size,tail->arr);
	struct Gsymbol* temp=malloc(sizeof(struct Gsymbol));
	temp->next=NULL;
	tail->next=temp;
	tail=temp;
	//printf("Install-ed...\n\n");
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
int break2[100];
int cont1[100];
int top=-1;

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
			puts("node");
			puts("\tleft");
			codeGen(t->left,target_file);
			puts("\tright");
			codeGen(t->right,target_file);
			break;
		case nt_NUM:
			puts("num");
			//printf("%d\n",t->num);
			i=getReg();
			fprintf(target_file, "MOV R%d,%d\n",i,t->num);
			return i;
			break;
		case nt_STR:
			puts("str");
			//printf("%s\n",t->str);
			i=getReg();
			fprintf(target_file, "MOV R%d,%s\n",i,t->str);//----------------
			return i;
			break;
		case nt_ID:
			puts("id");
			//printf("%s\n",t->str);
			i=getReg();
			fprintf(target_file, "MOV R%d,[%d]\n",i,t->Gentry->binding);
			return i;
			break;
		case nt_PTR:
			puts("pointer-<var name>");
			//printf("%s\n",t->str);
			i=getReg();
			fprintf(target_file, "MOV R%d, [%d]\n",i,t->Gentry->binding);
			return i;
			break;
		case nt_APTR:
			puts("pointer-&");
			//printf("%s\n",t->str);
			i=getReg();
			fprintf(target_file, "MOV R%d, %d\n",i,t->Gentry->binding+t->num);
			return i;
			break;
		case nt_SPTR:
			puts("pointer-*");
			//printf("%s\n",t->str);
			i=getReg();
			fprintf(target_file, "MOV R%d, [%d]\n",i,t->Gentry->binding+t->num);
			fprintf(target_file, "MOV R%d, [R%d]\n",i,i);
			return i;
			break;
		case nt_ARR:
			puts("arr");
			//printf("%s\n",t->str);
			i=getReg();
			node=t->Gentry;
			if((t->num)>node->size)
				printf("WARNING:Accessing beyond declaration!\n");
			fprintf(target_file, "MOV R%d,[%d]\n",i,(node->binding)+(t->num));
			return i;
			break;
		case nt_PLUS:
			puts("+");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "ADD R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_MUL:
			puts("*");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "MUL R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_MINUS:
			puts("-");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "SUB R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_DIV:
			puts("/");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "DIV R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_MOD:
			puts("%");
			i=codeGen(t->left,target_file);
			j=codeGen(t->right,target_file);
			fprintf(target_file, "MOD R%d,R%d\n",i,j );
			freeReg();
			return i;
			break;
		case nt_LT:
			puts("<");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "LT R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_LE:
			puts("<=");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "LE R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_GT:
			puts(">");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "GT R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_GE:
			puts(">=");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "GE R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_EE:
			puts("==");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "EQ R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_NE:
			puts("!=");
			i = codeGen(t->left, target_file);
			j = codeGen(t->right, target_file);
			fprintf(target_file, "NE R%d,R%d\n", i, j);
			freeReg();
			return i;
			break;
		case nt_READ:
			puts("read");
			// printf("%s",t->down->str);
			ret = getReg();
			Read(t->down->Gentry->binding + t->num, target_file, ret);
			freeReg();
			break;
		case nt_WRITE:
			puts("write");
			if((t->down->t)==t_CHAR)
				//printf("%s\n",t->down->str);
				;
			i=codeGen(t->down,target_file);
			ret=getReg();
			Write(i,target_file,ret);
			freeReg();
			break;
		case nt_ASGN:
			puts("=");
			i=codeGen(t->right,target_file);
			node=t->left->Gentry;
			if(t->left->nt==nt_SPTR){
				j=(node->binding+t->left->num);
				k=getReg();
				fprintf(target_file,"MOV R%d,[%d]\n",k,j);
				fprintf(target_file,"MOV [R%d],R%d\n",k,i );
				freeReg();
				break;}
			else if(t->left->nt==nt_STR){
				j=(node->binding)+(t->left->num);
				fprintf(target_file,"MOV [%d],%s\n",j,t->right->str);}
			else{
				if((t->left->num)>node->size)
					printf("WARNING:Accessing beyond declaration!\n");
					;
				j=(node->binding)+(t->left->num);
				fprintf(target_file,"MOV [%d],R%d\n",j,i );}
			freeReg();
			break;
		case nt_IF:
			puts("if");
			result=codeGen(t->left,target_file);
			label1=getLabel();
			fprintf(target_file,"JZ R%d,L%d\n",result,label1);
			freeReg();
			codeGen(t->right,target_file);
			fprintf(target_file,"L%d:\n",label1);
			break;
		case nt_IFELSE:
			puts("ifelse");
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
			puts("while");
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
			if(top<0) puts("break not in loop");
			else{puts("break");
				fprintf(target_file, "JMP L%d\n",break2[top]);}
			break;
		case nt_CONTINUE:
			if(top<0) puts("continue not in loop");
			else{puts("continue");
				fprintf(target_file, "JMP L%d\n",cont1[top]);}
			break;
		default:
			puts("\tNO CODE-GEN MATCHING FOUND\n");
			exit(1);	
			}}

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
	printf("type mismatch:nt_%d at line:%d\n",n,line);
	printf("left:t_%d\n",l);
	printf("right:t_%d\n",r);
	exit(1);}

int evaluate(struct tnode *t){
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
		/*	if(val[*(t->str)-'a']!=NULL)
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

	}}	

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
