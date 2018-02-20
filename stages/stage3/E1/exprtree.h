int indent=0;
var [26];
typedef struct tnode { 
	char type;
/*
i	int
c	char
b	comp oper <,>,<=,>=,!=,==
n	just a node
a	arth	+,-,*,/,=
f	func	read,write
s	stmt	if,ifelse,while
*/
	int num;
	char id;
//	char* op;
	char* func;
/*
f,a,o,s

type='f'
read
write
type='a'
+
-
*
/
type='b'
<
>
<=
>=
!=
==
type='s'
if
ifelse
while
*/
	struct tnode *left,*right,*down;
}tnode;

struct tnode* makeLeafNum(int n);
struct tnode* makeLeafID(char ID);
struct tnode* makeOperatorNode(char* c,struct tnode *l,struct tnode *r);
struct tnode* makeFunc(char *c,struct tnode *t);
struct tnode* twoTree(struct tnode *l, struct tnode *r,char* s);
struct tnode* threeTree(struct tnode *l, struct tnode *d, struct tnode *r,char* s);

