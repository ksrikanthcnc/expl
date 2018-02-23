typedef struct tnode { 
	char type;
	int num;
	char id;
	char op;
	char* func;
	struct tnode *left,*right,*down;
}tnode;

struct tnode* makeLeafNum(int n);
struct tnode* makeLeafID(char ID);
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
struct tnode* makeFunc(char *c,struct tnode *t);
struct tnode* createTree(struct tnode *l, struct tnode *r);

