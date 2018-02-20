typedef struct tnode { 
	char type;
/*
i	int
c	char
n	just a node
b	boolean
a	arth
o	comp oper
*/
	int num;
	char id;
	char* op;
	char* func;
	struct tnode *left,*right,*down;
}tnode;

struct tnode* makeLeafNum(int n);
struct tnode* makeLeafID(char ID);
struct tnode* makeOperatorNode(char* c,struct tnode *l,struct tnode *r);
struct tnode* makeFunc(char *c,struct tnode *t);
struct tnode* twoTree(struct tnode *l, struct tnode *r);
struct tnode* threeTree(struct tnode *l, struct tnode *d, struct tnode *r);

