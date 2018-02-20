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
	printf("Num:%d\n",temp->num);
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
	printf("ID:%c\n",temp->id);
	return temp;
}

struct tnode* makeOperatorNode(char* c,struct tnode *l,struct tnode *r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	if(strcmp(c,"+")==0 || strcmp(c,"-")==0 || strcmp(c,"*")==0 || strcmp(c,"/")==0){
		temp->type='a';
	}
	else if(strcmp(c,"<")==0 || strcmp(c,">")==0 || strcmp(c,"<=")==0 || strcmp(c,">=")==0 || strcmp(c,"!=")==0 || strcmp(c,"==")==0){
		temp->type='b';
	}
//	temp->num = ;
//	temp->id = ;
	temp->op = c;
//	temp->func = ;
	temp->left = l;
	temp->down = NULL;
	temp->right = r;
	printf("Node:%s\n",temp->op);
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
	printf("Func:%s\n",temp->func);
	return temp;
}

struct tnode* twoTree(struct tnode *l, struct tnode *r,char* s){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 'n';
//	temp->num = ;
//	temp->id = ;
//	temp->op = ;
	temp->func = s;
	temp->left = l;
//	temp->down = ;
	temp->right = r;
	printf("Tree\n");
	return temp;
}

struct tnode* threeTree(struct tnode *l, struct tnode *d, struct tnode *r, char *s){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->type = 'n';
//	temp->num = ;
//	temp->id = ;
//	temp->op = ;
	temp->func = s;
	temp->left = l;
	temp->down = d;
	temp->right = r;
	printf("Tree\n");
	return temp;
}



int evaluate(struct tnode *t){
	if(t == NULL){
		return ;
	}
	else if(t->type=='n'){
		printf("Node\n");
		if(strcmp(t->func,"stmt")==0){
			printf("stmt\n");
			evaluate(t->left);
			evaluate(t->right);
			return;
		}
		else if(strcmp(t->func,"if")==0){
			printf("if\n");
			printf("\t%s\n",t->left->func);
//			raise(SIGABRT);
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
				printf("true");
				evaluate(t->right);
			}
			return;
		}
	}
	else if(t->type=='i'){
		printf("int:%d\n",t->num);
		return t->num;
	}
	else if(t->type=='c'){
		printf("char:%c\n",t->id);
		return var[t->id-'a'];
	}
	else if(t->op=='+' || t->op=='-' || t->op=='*' || t->op=='/'){
		printf("op:%c\n",t->op);
		if(strcmp(t->op),"+"){return evaluate(t->left) + evaluate(t->right);}
		if(strcmp(t->op),"-"){return evaluate(t->left) - evaluate(t->right);}
		if(strcmp(t->op),"*"){return evaluate(t->left) * evaluate(t->right);}
		if(strcmp(t->op),"/"){return evaluate(t->left) / evaluate(t->right);}

		if(strcmp(t->op),"<"){return evaluate(t->left)<evaluate(t->right)?1:0;}
		if(strcmp(t->op),">"){return evaluate(t->left)>evaluate(t->right)?1:0;}
		if(strcmp(t->op),"<="){return evaluate(t->left)<=evaluate(t->right)?1:0;}	
		if(strcmp(t->op),">="){return evaluate(t->left)>=evaluate(t->right)?1:0;}	
		if(strcmp(t->op),"!="){return evaluate(t->left)!=evaluate(t->right)?1:0;}		
		if(strcmp(t->op),"=="){return evaluate(t->left)==evaluate(t->right)?1:0;}
		else{
			printf("operater-boo\n");
			exit(0);
		}
	}
	else if(t->op=="="){
		printf("Ass to %c\n",t->left->id);
		var[t->left->id-'a'] = evaluate(t->right);
		return;
	}
	else if(strcmp(t->func,"read")==0){
		printf("Read to '%c'\n",t->down->id);
		scanf("%d",&var[t->down->id-'a']);
		return;
	}
	else if(strcmp(t->func,"write")==0){
		printf("Write\n");
		printf("%d\n",evaluate(t->down));
	}
	else{
		puts("evaluate-end-boo");
	}
}


