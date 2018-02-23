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
	printf("Num	%d\n",temp->num);
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
	printf("ID	%c\n",temp->id);
	return temp;
}

struct tnode* makeOperatorNode(char* c,struct tnode *l,struct tnode *r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	if(strcmp(c,"+")==0 || strcmp(c,"-")==0 || strcmp(c,"*")==0 || strcmp(c,"/")==0 || strcmp(c,"=")==0){
		temp->type='a';
	}
	else if(strcmp(c,"<")==0 || strcmp(c,">")==0 || strcmp(c,"<=")==0 || strcmp(c,">=")==0 || strcmp(c,"!=")==0 || strcmp(c,"==")==0){
		temp->type='b';
	}
//	temp->num = ;
//	temp->id = ;
	temp->func = c;
	temp->left = l;
	temp->down = NULL;
	temp->right = r;
	{
		int in;
		in=indent;
		while(--in>0)
			printf("  ");
	}
	printf("Node	%s\n",temp->func);
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
	{
		int in;
		in=indent;
		while(--in>0)
			printf("  ");
	}
	printf("Func	%s\n",temp->func);
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
	{
		int in;
		in=indent;
		while(--in>0)
			printf("  ");
	}
	printf("Tree--%s\n",temp->func);
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
	{
		int in;
		in=indent;
		while(--in>0)
			printf("  ");
	}
	printf("Tree--%s\n",temp->func);
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
	temp->right = r;
	{
		int in;
		in=indent;
		while(--in>0)
			printf("  ");
	}
	printf("Tree--NODE\n");
	return temp;
}	

int evaluate(struct tnode *t){
	if(t == NULL){
		return ;
	}
	else if(t->type=='i'){
		printf("int	%d\n",t->num);
		return t->num;
	}
	else if(t->type=='c'){
		printf("char	%c\t(val=%d)\n",t->id,var[t->id-'a']);
		return var[t->id-'a'];
	}
	else if(t->type=='b'){
		printf("bool	%s\n",t->func);
		if(strcmp((t->func),"<")==0){return evaluate(t->left)<evaluate(t->right)?1:0;}
		if(strcmp((t->func),">")==0){return evaluate(t->left)>evaluate(t->right)?1:0;}
		if(strcmp((t->func),"<=")==0){return evaluate(t->left)<=evaluate(t->right)?1:0;}	
		if(strcmp((t->func),">=")==0){return evaluate(t->left)>=evaluate(t->right)?1:0;}	
		if(strcmp((t->func),"!=")==0){return evaluate(t->left)!=evaluate(t->right)?1:0;}		
		if(strcmp((t->func),"==")==0){return evaluate(t->left)==evaluate(t->right)?1:0;}
		printf("operater-boo\n");
		exit(0);
	}
	else if(t->type=='n'){
		printf("Node\n");
		evaluate(t->left);
		evaluate(t->right);
		return;
	}
	else if(t->type=='a'){
		printf("op	%s\n",t->func);
		if(strcmp((t->func),"+")==0){return evaluate(t->left) + evaluate(t->right);}
		if(strcmp((t->func),"-")==0){return evaluate(t->left) - evaluate(t->right);}
		if(strcmp((t->func),"*")==0){return evaluate(t->left) * evaluate(t->right);}
		if(strcmp((t->func),"/")==0){return evaluate(t->left) / evaluate(t->right);}
		if(strcmp((t->func),"=")==0){printf("\t%c\n",t->left->id);var[t->left->id-'a'] = evaluate(t->right);return;}
		printf("arithmetic-boo\n");
		exit(0);
	}
	else if(t->type=='f'){
		if(strcmp(t->func,"read")==0){
			printf("Read to '%c'\n",t->down->id);
			scanf("%d",&var[t->down->id-'a']);
			return;
		}
		if(strcmp(t->func,"write")==0){
			printf("Write\n");
			printf("%d\n",evaluate(t->down));
		}
	}
	else if(t->type=='s'){
		if(strcmp(t->func,"if")==0){
			printf("if\n");
			if(evaluate(t->left)){
				printf("true");
				evaluate(t->right);
			}
			return;
		}
		else if(strcmp(t->func,"ifelse")==0){
			printf("ifelse\n");
			if(evaluate(t->left)){
				printf("if");
				evaluate(t->down);
			}
			else{
				printf("else\n");
				evaluate(t->right);
			}
			return;
		}
		else if(strcmp(t->func,"while")==0){
			printf("while\n");
			if(evaluate(t->left)){
				printf("true\n");
				evaluate(t->right);
			}
			return;
		}
	}
	else{
		puts("evaluate-end-boo");
		printf("type	%c\n",t->type);
	}
}


