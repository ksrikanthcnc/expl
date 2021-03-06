//#include <signal.h>
//#define brkp	raise(SIGINT);
//#define boo 	printf("\t\t\t\tERROR:\t(File:%s\tfunc:%s\tLine:%d)\n",__FILE__,__func__,__LINE__);

#define t_int 1
#define t_bool 2
#define t_char 3
#define t_null 4
#define t_arrint 5
#define t_str 6

#define nt_NUM 0
#define nt_ID 1
#define nt_PLUS 2
#define nt_MINUS 3
#define nt_MUL 4
#define nt_DIV 5 
#define nt_ASGN 6
#define nt_READ 7
#define nt_WRITE 8
#define nt_NULL 9
#define nt_IF 10
#define nt_THEN 11
#define nt_ELSE 12
#define nt_ENDIF 13
#define nt_WHILE 14
#define nt_DO 15
#define nt_ENDWHILE 16
#define nt_LT 17
#define nt_LE 18
#define nt_GT 19
#define nt_GE 20
#define nt_EQ 21
#define nt_NE 22
#define nt_BREAK 23
#define nt_CONT 24
#define nt_IFELSE 25

/*
#define nt_ARRID 23
#define nt_ARRASGN 24
#define nt_ARRREAD 25
*/

int val[26];

typedef struct tnode 
{
	int type;	//int,bool,char,null,arr,str
	int num;	//value of  int,bool
	char *str;	//value of char,str

	int nodetype;	//num,id,plus,minus,....
	struct tnode *left,*right,*down;
//	struct Gsymbol *Gentry;
}tnode;

struct tnode* createtree(int val, int nt,int t, char *c,struct tnode *l, struct tnode *r,struct tnode *d);
int evaluate(struct tnode *t);



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

