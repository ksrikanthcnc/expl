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
/*
type
0	num
1	ID

nodetype
+	1
-	2
*	3
/	4
=	5

read	6
write	7

	8
	
*/
