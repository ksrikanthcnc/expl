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
	if(str!=NULL)
		temp->str=strdup(str);
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



