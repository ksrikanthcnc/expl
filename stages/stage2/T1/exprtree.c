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
	return temp;
}

struct tnode* makeFunc(char *c,struct tnode *t){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
//	temp->type = ;
//	temp->num = ;
//	temp->id = ;
//	temp->op = c;
	temp->func = strdup(c);
//	temp->left = ;
	temp->down = t;
//	temp->right = ;
	return temp;
}

struct tnode* createTree(struct tnode *l, struct tnode *r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
//	temp->type = ;
//	temp->num = ;
//	temp->id = ;
//	temp->op = ;
//	temp->func = ;
	temp->left = l;
//	temp->down = ;
	temp->right = r;
	return temp;
}

/*
int evaluate(struct tnode *t){
	if(t->op == NULL){
		return t->val;
	}
	else{
		switch(*(t->op)){
			case '+' : return evaluate(t->left) + evaluate(t->right);
					   break;
			case '-' : return evaluate(t->left) - evaluate(t->right);
					   break;
			case '*' : return evaluate(t->left) * evaluate(t->right);
					   break;
			case '/' : return evaluate(t->left) / evaluate(t->right);
					   break;
		}
	}
}
*/

