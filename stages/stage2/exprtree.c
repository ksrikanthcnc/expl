struct tnode* makeLeafNum(int n){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 'i';
	temp->num = n;
//	temp->id = ;
//	temp->op = ;
//	temp->func = ;
	temp->left = NULL;
	temp->down = NULL;
	temp->right = NULL;
	//printf("Num:%d\n",temp->num);
	return temp;
}

struct tnode* makeLeafID(char id){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 'c';
//	temp->num = ;
	temp->id=id;
//	temp->op = ;
//	temp->func = ;
	temp->left = NULL;
	temp->down = NULL;
	temp->right = NULL;
	//printf("ID:%c\n",temp->id);
	return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
//	temp->type = ;
//	temp->num = ;
//	temp->id = ;
	temp->op = c;
//	temp->func = ;
	temp->left = l;
	temp->down = NULL;
	temp->right = r;
	//printf("Node:%c\n",temp->op);
	return temp;
}

struct tnode* makeFunc(char *c,struct tnode *t){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
//	temp->type = ;
//	temp->num = ;
//	temp->id = ;
//	temp->op = c;
	temp->func = c;
//	temp->left = ;
	temp->down = t;
//	temp->right = ;
	//printf("Func:%s\n",temp->func);
	return temp;
}

struct tnode* createTree(struct tnode *l, struct tnode *r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 'n';
//	temp->num = ;
//	temp->id = ;
//	temp->op = ;
//	temp->func = ;
	temp->left = l;
//	temp->down = ;
	temp->right = r;
	//printf("Tree");
	return temp;
}


int evaluate(struct tnode *t){
	if(t == NULL){
		return ;
	}
	else if(t->type=='n'){
		//printf("Node\n");
		evaluate(t->left);
		evaluate(t->right);
		return;
	}
	else if(t->type=='i'){
		//printf("int:%d\n",t->num);
		return t->num;
	}
	else if(t->type=='c'){
		//printf("char:%c\n",t->id);
		return var[t->id-'a'];
	}
	else if(t->op=='+' || t->op=='-' || t->op=='*' || t->op=='/'){
		//printf("op:%c\n",t->op);
		switch(t->op){
			case '+' : return evaluate(t->left) + evaluate(t->right);
					   break;
			case '-' : return evaluate(t->left) - evaluate(t->right);
					   break;
			case '*' : return evaluate(t->left) * evaluate(t->right);
					   break;
			case '/' : return evaluate(t->left) / evaluate(t->right);
					   break;
		}
		return;
	}
	else if(t->op=='='){
		//printf("Ass to %c\n",t->left->id);
		var[t->left->id-'a'] = evaluate(t->right);
		return;
	}
	else if(strcmp(t->func,"read")==0){
		//printf("Read to '%c'\n",t->down->id);
		scanf("%d",&var[t->down->id-'a']);
		return;
	}
	else if(strcmp(t->func,"write")==0){
		//printf("Write\n");
		printf("%d\n",evaluate(t->down));
	}
	else{
		puts("evaluate-end-boo");
	}
}


