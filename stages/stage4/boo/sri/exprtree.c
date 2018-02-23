struct tnode* createtree(int val, int nt,int t,char *c,struct tnode *l, struct tnode *r,struct tnode *d)
{
	switch(nt)
	{
		case nt_NULL:
			break;
		case nt_PLUS:	if(l->t!=t_int||r->t!=t_int)
			{		printf("t mismatch1\n"); exit(1);}
			break;
		case nt_MUL:
			if(l->t!=t_int||r->t!=t_int)
			{		printf("t mismatch2\n"); exit(1);}
			break;
		case nt_MINUS:
			if(l->t!=t_int||r->t!=t_int)
			{		printf("t mismatch3\n"); exit(1);}
			break;
		case nt_DIV:
			if(l->t!=t_int||r->t!=t_int)
			{		printf("t mismatch4\n"); exit(1); }
			break;
		case nt_LEAF:
			break;
		case nt_ID:
			break;
		case nt_ASGN:
			if(l->nt!=nt_ID||(r->t!=t_int&&r->t!=t_bool))
			{		printf("t mismatch7\n"); exit(1); }
			break;
		case nt_LT:
			if(l->t!=t_int||r->t!=t_int)
			{		printf("t mismatch8\n"); exit(1);}
			break;
		case nt_LE:
			if(l->t!=t_int||r->t!=t_int)
			{		printf("t mismatch9\n");	exit(1);}
			break;
		case nt_GT:
			if(l->t!=t_int||r->t!=t_int)
			{		printf("t mismatch10\n"); exit(1);}
			break;
		case nt_GE:
			if(l->t!=t_int||r->t!=t_int)
			{		printf("t mismatch11\n"); exit(1);}
			break;
		case nt_EQ:
			if(l->t!=t_int||r->t!=t_int)
			{		printf("t mismatch12\n"); exit(1);}
			break;
		case nt_NE:
			if(l->t!=t_int||r->t!=t_int)
			{		printf("t mismatch13\n"); exit(1);}
			break;
		case nt_IF:
			if(l->t!=t_bool)
			{		printf("t mismatch14\n"); exit(1);}
			break;
		case nt_WHILE:
			if(l->t!=t_bool)
			{		printf("t mismatch15\n");	exit(1);}
			break;
	}
	
	
	struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
	temp->val=val;
	temp->t=t;
	temp->nt=nt;
	if(c!=NULL)
		temp->varname=strdup(c);
	else
		temp->varname=NULL;
	temp->Gentry=NULL;
	temp->left=l;
	temp->right=r;
	temp->end=d;
	return temp;
}

int evaluate(struct tnode *t)
{
	switch(t->nt)
	{
		case nt_NULL:
			evaluate(t->left);
			evaluate(t->right);
			//return 1;
			break;
		case nt_PLUS:
			return evaluate(t->left)+evaluate(t->right);
			break;
		case nt_MUL:
			return evaluate(t->left)*evaluate(t->right);
			break;
		case nt_MINUS:
			return evaluate(t->left)-evaluate(t->right);
			break;
		case nt_DIV:
			return evaluate(t->left)/evaluate(t->right);
			break;
		case nt_LEAF:
			return t->val;
			break;
		case nt_ID:
			if(val[*(t->varname)-'a']!=NULL)
				return val[*(t->varname)-'a'];
			else
			{
				printf("error\n");
				exit(1);
			}
			break;
		case nt_READ:
			if(val[*(t->left->varname)-'a']==NULL)
				val[*(t->left->varname)-'a']=malloc(sizeof(int*));
			scanf("%d",val[*(t->left->varname)-'a']);
			//return 1;
			break;
		case nt_WRITE:
			printf("%d\n",evaluate(t->left));
			break;
		case nt_ASGN:
			if(val[*(t->left->varname)-'a']==NULL)
				val[*(t->left->varname)-'a']=malloc(sizeof(int*));
			val[*(t->left->varname)-'a']=evaluate(t->right);
			//return 1;
			break;
		case nt_LT:
			return evaluate(t->left)<evaluate(t->right);
			break;
		case nt_LE:
			return evaluate(t->left)<=evaluate(t->right);
			break;
		case nt_GT:
			return evaluate(t->left)>evaluate(t->right);
			break;
		case nt_GE:
			return evaluate(t->left)>=evaluate(t->right);
			break;
		case nt_EQ:
			return evaluate(t->left)==evaluate(t->right);
			break;
		case nt_NE:
			return evaluate(t->left)!=evaluate(t->right);
			break;		
		case nt_IF:
			if(evaluate(t->left))
				evaluate(t->right);
			else if(t->end!=NULL)
				evaluate(t->end);
			break;
		case nt_WHILE:
			while(evaluate(t->left))
				evaluate(t->right);
			break;

	}
}	


/*
struct tnode* makeLeafNum(int n){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 'i';
	temp->num = n;
//	temp->id = ;
//	temp->func = ;
	temp->left = NULL;
	temp->down = NULL;
	temp->right = NULL;
	//printf("Num	%d\n",temp->num);
	return temp;
}

struct tnode* makeLeafID(char id){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 'c';
//	temp->num = ;
	temp->id=id;
//	temp->func = ;
	temp->left = NULL;
	temp->down = NULL;
	temp->right = NULL;
	//printf("ID	%c\n",temp->id);
	return temp;
}

struct tnode* makeOperatorNode(char* c,struct tnode *l,struct tnode *r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	if(l->type!='b' && r->type!='b')
		{if(strcmp(c,"+")==0 || strcmp(c,"-")==0 || strcmp(c,"*")==0 || strcmp(c,"/")==0 || strcmp(c,"=")==0)
			temp->type='a';
		else if(strcmp(c,"<")==0 || strcmp(c,">")==0 || strcmp(c,"<=")==0 || strcmp(c,">=")==0 || strcmp(c,"!=")==0 || strcmp(c,"==")==0)
			temp->type='b';}
	else 
	{	puts("type mismatch-arth-op");
		printf("op:%s\n",c);
		printf("left:%c\n",l->type);
		printf("right:%c\n",r->type);
		exit(1);}
//	else{boo}
//	temp->num = ;
//	temp->id = ;
	temp->func = c;
	temp->left = l;
	temp->down = NULL;
	temp->right = r;
	indent();
	//printf("Node	%s\n",temp->func);
	return temp;
}

struct tnode* makeFunc(char *c,struct tnode *t){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 'f';
//	temp->num = ;
//	temp->id = ;
	temp->func = c;
//	temp->left = ;
	temp->down = t;
//	temp->right = ;
	indent();	
	//printf("Func	%s\n",temp->func);
	return temp;
}

struct tnode* twoTree(struct tnode *l, struct tnode *r,char* s){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 's';
//	temp->num = ;
//	temp->id = ;
	temp->func = s;
	temp->left = l;
//	temp->down = ;
	temp->right = r;
	indent();
	//printf("Tree--%s\n",temp->func);
	return temp;
}

struct tnode* threeTree(struct tnode *l, struct tnode *d, struct tnode *r, char *s){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 's';
//	temp->num = ;
//	temp->id = ;
	temp->func = s;
	temp->left = l;
	temp->down = d;
	temp->right = r;
	indent();
	//printf("Tree--%s\n",temp->func);
	return temp;
}

struct tnode* createTree(struct tnode* l, struct tnode* r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 'n';
//	temp->num = ;
//	temp->id = ;
//	temp->func = ;
	temp->left = l;
	temp->down=NULL;
	temp->right = r;
	indent();
	//printf("Tree--NODE\n");
	return temp;
}	

struct tnode* makeNode(char* str){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 'f';
//	temp->num = ;
//	temp->id = ;
	temp->func = str;
	temp->left = NULL;
	temp->down=NULL;
	temp->right = NULL;
	indent();
	//printf("Tree--NODE\n");
	return temp;
}

struct Gsymbol *Lookup(char * name){
	printf("Searching...\n");
	struct Gsymbol* temp;
	temp=head;
	while(temp!=tail){
		printf("name:'%s'\ttype:'%s'\tsize:'%d'\n",temp->name,temp->type,temp->size);
		if(strcmp(temp->name,name)==0){
			printf("Found!\n");
			return temp;}
		temp=temp->next;
	}
	return NULL;
}

void Install(char *name, char* type, int size){
	printf("Install-ing...");
	if(Lookup(name)!=NULL){
		printf("variable:'%s' redeclared\n",name);
		exit(1);
	}
	tail->name=name;
	tail->type=type;
	tail->size=size;
	struct Gsymbol* temp=malloc(sizeof(struct Gsymbol));
	temp->next=NULL;
	tail->next=temp;
	tail=temp;
	printf("name:'%s'\ttype:'%s'\tsize:'%d'\n",tail->name,tail->type,tail->size);
	printf("Install-ed\n");
}

void indent(){
	int in;
	in=indents;
	while(in-->0)
	//printf("  ");
	;
}


int evaluate(struct tnode *t){
	if(t == NULL)
		return ;
	switch(t->type){
		case 'i':
			printf("int	%d\n",t->num);
			return t->num;
			break;
		case 'c':	
			printf("char	%c\t(val=%d)\n",t->id,var[t->id-'a']);
			return var[t->id-'a'];
			break;
		case 'b':			
			printf("bool	%s\n",t->func);
			if(strcmp((t->func),"<")==0){return evaluate(t->left)<evaluate(t->right)?1:0;}
			if(strcmp((t->func),">")==0){return evaluate(t->left)>evaluate(t->right)?1:0;}
			if(strcmp((t->func),"<=")==0){return evaluate(t->left)<=evaluate(t->right)?1:0;}	
			if(strcmp((t->func),">=")==0){return evaluate(t->left)>=evaluate(t->right)?1:0;}	
			if(strcmp((t->func),"!=")==0){return evaluate(t->left)!=evaluate(t->right)?1:0;}		
			if(strcmp((t->func),"==")==0){return evaluate(t->left)==evaluate(t->right)?1:0;}
			printf("operater-boo\n");
			exit(0);
			break;
		case 'n':			
			printf("Node\n");
			evaluate(t->left);
			evaluate(t->right);
			return;
			break;
		case 'a':			
			printf("op	%s\n",t->func);
			if(strcmp((t->func),"+")==0){return evaluate(t->left) + evaluate(t->right);}
			if(strcmp((t->func),"-")==0){return evaluate(t->left) - evaluate(t->right);}
			if(strcmp((t->func),"*")==0){return evaluate(t->left) * evaluate(t->right);}
			if(strcmp((t->func),"/")==0){return evaluate(t->left) / evaluate(t->right);}
			if(strcmp((t->func),"=")==0){printf("\t%c\n",t->left->id);var[t->left->id-'a'] = evaluate(t->right);return;}
			printf("arithmetic-boo\n");
			exit(0);
			break;
		case 'f':			
			if(strcmp(t->func,"read")==0){
				printf("Read to '%c'\n",t->down->id);
				scanf("%d",&var[t->down->id-'a']);
				return;}
			if(strcmp(t->func,"write")==0){
				printf("Write\n");
				printf("%d\n",evaluate(t->down));}
			break;
		case 's':
			if(strcmp(t->func,"if")==0){
				printf("if\n");
				if(evaluate(t->left)){
					printf("true");
					evaluate(t->right);}
				return;}
			else if(strcmp(t->func,"ifelse")==0){
				printf("ifelse\n");
				if(evaluate(t->left)){
					printf("if");
					evaluate(t->down);}
				else{
					printf("else\n");
					evaluate(t->right);}
				return;}
			else if(strcmp(t->func,"while")==0){
				printf("while\n");
				while(evaluate(t->left)){
					printf("true\n");
					evaluate(t->right);}
				return;}
			break;
		default:
			printf("type	%c\n",t->type);
			;
	}
}

*/
