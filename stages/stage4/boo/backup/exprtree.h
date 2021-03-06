//#include <signal.h>
//#define brkp	raise(SIGINT);
//#define boo 	printf("\t\t\t\tERROR:\t(File:%s\tfunc:%s\tLine:%d)\n",__FILE__,__func__,__LINE__);
int indents=0;
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

struct Gsymbol{
	char* name;
	char* type;
/*
Int
Str
*/
	int size;
	int binding;
	struct Gsymbol* next;
}*head,*tail;

struct Gsymbol *Lookup(char * name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void Install(char *name, char* type, int size); // Creates a symbol table entry.

struct tnode* makeLeafNum(int n);
struct tnode* makeLeafID(char ID);
struct tnode* makeNode(char* str);
struct tnode* makeOperatorNode(char* c,struct tnode *l,struct tnode *r);
struct tnode* makeFunc(char *c,struct tnode *t);
struct tnode* twoTree(struct tnode *l, struct tnode *r,char* s);
struct tnode* threeTree(struct tnode *l, struct tnode *d, struct tnode *r,char* s);
int evaluate(struct tnode *t);

