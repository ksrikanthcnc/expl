struct tnode* createtree(int val, int nodetype,int type,char *c,struct tnode *l, struct tnode *r,struct tnode *d)
{
	switch(nodetype)
	{
		case nodetype_NULL:
			break;
		case nodetype_PLUS:	if(l->type!=type_int||r->type!=type_int)
			{		printf("type mismatch1\n"); exit(1);}
			break;
		case nodetype_MUL:
			if(l->type!=type_int||r->type!=type_int)
			{		printf("type mismatch2\n"); exit(1);}
			break;
		case nodetype_MINUS:
			if(l->type!=type_int||r->type!=type_int)
			{		printf("type mismatch3\n"); exit(1);}
			break;
		case nodetype_DIV:
			if(l->type!=type_int||r->type!=type_int)
			{		printf("type mismatch4\n"); exit(1); }
			break;
		case nodetype_LEAF:
			break;
		case nodetype_ID:
			break;
		case nodetype_ASGN:
			if(l->nodetype!=nodetype_ID||(r->type!=type_int&&r->type!=type_bool))
			{		printf("type mismatch7\n"); exit(1); }
			break;
		case nodetype_LT:
			if(l->type!=type_int||r->type!=type_int)
			{		printf("type mismatch8\n"); exit(1);}
			break;
		case nodetype_LE:
			if(l->type!=type_int||r->type!=type_int)
			{		printf("type mismatch9\n");	exit(1);}
			break;
		case nodetype_GT:
			if(l->type!=type_int||r->type!=type_int)
			{		printf("type mismatch10\n"); exit(1);}
			break;
		case nodetype_GE:
			if(l->type!=type_int||r->type!=type_int)
			{		printf("type mismatch11\n"); exit(1);}
			break;
		case nodetype_EQ:
			if(l->type!=type_int||r->type!=type_int)
			{		printf("type mismatch12\n"); exit(1);}
			break;
		case nodetype_NE:
			if(l->type!=type_int||r->type!=type_int)
			{		printf("type mismatch13\n"); exit(1);}
			break;
		case nodetype_IF:
			if(l->type!=type_bool)
			{		printf("type mismatch14\n"); exit(1);}
			break;
		case nodetype_WHILE:
			if(l->type!=type_bool)
			{		printf("type mismatch15\n");	exit(1);}
			break;
	}
	
	
	struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
	temp->val=val;
	temp->type=type;
	temp->nodetype=nodetype;
	if(c!=NULL)
	{
		temp->varname=(char *)malloc(sizeof(c));
		strcpy(temp->varname,c);
	}
	else
		temp->varname=NULL;
	temp->Gentry=NULL;
	temp->left=l;
	temp->right=r;
	temp->end=d;
	return temp;
}

int abst_evaluate(struct tnode *t)
{
	switch(t->nodetype)
	{
		case nodetype_NULL:
			abst_evaluate(t->left);
			abst_evaluate(t->right);
			return 1;
			break;
		case nodetype_PLUS:
			return abst_evaluate(t->left)+abst_evaluate(t->right);
			break;
		case nodetype_MUL:
			return abst_evaluate(t->left)*abst_evaluate(t->right);
			break;
		case nodetype_MINUS:
			return abst_evaluate(t->left)-abst_evaluate(t->right);
			break;
		case nodetype_DIV:
			return abst_evaluate(t->left)/abst_evaluate(t->right);
			break;
		case nodetype_LEAF:
			return t->val;
			break;
		case nodetype_ID:
			if(val[*(t->varname)-'a']!=NULL)
				return *val[*(t->varname)-'a'];
			else
			{
				printf("error\n");
				exit(1);
			}
			break;
		case nodetype_READ:
			if(val[*(t->left->varname)-'a']==NULL)
				val[*(t->left->varname)-'a']=malloc(sizeof(int*));
			scanf("%d",val[*(t->left->varname)-'a']);
			return 1;
			break;
		case nodetype_WRITE:
			printf("%d\n",abst_evaluate(t->left));
			break;
		case nodetype_ASGN:
			if(val[*(t->left->varname)-'a']==NULL)
				val[*(t->left->varname)-'a']=malloc(sizeof(int*));
			*val[*(t->left->varname)-'a']=abst_evaluate(t->right);
			return 1;
			break;
		case nodetype_LT:
			return abst_evaluate(t->left)<abst_evaluate(t->right);
			break;
		case nodetype_LE:
			return abst_evaluate(t->left)<=abst_evaluate(t->right);
			break;
		case nodetype_GT:
			return abst_evaluate(t->left)>abst_evaluate(t->right);
			break;
		case nodetype_GE:
			return abst_evaluate(t->left)>=abst_evaluate(t->right);
			break;
		case nodetype_EQ:
			return abst_evaluate(t->left)==abst_evaluate(t->right);
			break;
		case nodetype_NE:
			return abst_evaluate(t->left)!=abst_evaluate(t->right);
			break;		
		case nodetype_IF:
			if(abst_evaluate(t->left))
				abst_evaluate(t->right);
			else if(t->end!=NULL)
				abst_evaluate(t->end);
			break;
		case nodetype_WHILE:
			while(abst_evaluate(t->left))
				abst_evaluate(t->right);
			break;

	}
}	
