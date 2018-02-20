struct Gsymbol* Lookup(char * name)
{
	struct Gsymbol *temp=Ghead;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
			return temp;
		temp=temp->next;
	}
	return NULL;
}


void Install(char *name, int type, int size)
{
	if(Lookup(name)!=NULL)
	{
		printf("Variable is already defined%s\n",name);
		exit(1);
	}
	struct Gsymbol *new=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	new->name=(char *)malloc(sizeof(name));
	strcpy(new->name,name);
	new->type=type;
	new->size=size;
	new->binding=varadrs;
	varadrs=varadrs+size;
	if(Ghead==NULL)
	{
		Ghead=new;
		return;
	}
	new->next=Ghead;
	Ghead=new;
}

void printsymtab()
{
	struct Gsymbol *temp=Ghead;
	printf("%s %s %s %s\n","name","type","size","binding" );
	while(temp!=NULL)
	{
		printf("%s %d %d %d\n",temp->name,temp->type,temp->size,temp->binding );
		temp=temp->next;
	}
}