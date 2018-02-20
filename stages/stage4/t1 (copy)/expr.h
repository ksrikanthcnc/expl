
//#include <signal.h>
//#define brkp	raise(SIGINT);
//#define boo 	printf("\t\t\t\tERROR:\t(File:%s\tfunc:%s\tLine:%d)\n",__FILE__,__func__,__LINE__);

#define t_NULL 0
#define t_INT 1
#define t_BOOL 2
#define t_CHAR 3
#define t_OTHER 4
//#define t_null 4
//#define t_arrint 5
//#define t_str 6

#define nt_NUM 0
#define nt_ID 1
#define nt_PLUS 2
#define nt_MINUS 3
#define nt_MUL 4
#define nt_DIV 5 
#define nt_ASGN 6
#define nt_READ 7
#define nt_WRITE 8
#define nt_NODE 9
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
#define nt_EE 21
#define nt_NE 22
#define nt_BREAK 23
#define nt_CONT 24
#define nt_IFELSE 25
#define nt_REPEAT 26
#define nt_UNTIL 27

/*
#define nt_ARRID 23
#define nt_ARRASGN 24
#define nt_ARRREAD 25
*/

int val[26];

typedef struct tnode 
{
	int t;	//int,bool,char,null,arr,str
	int num;	//value of  int,bool
	char *str;	//value of char,str

	int nt;	//num,id,plus,minus,....
	struct tnode *left,*right,*down;
	struct Gsymbol *Gentry;
}tnode;

struct Gsymbol{
	char* name;
	int type;
	int size;
	int binding;
	struct Gsymbol* next;
}*head,*tail;

struct Gsymbol *Lookup(char * name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void Install(char *name, int type, int size); // Creates a symbol table entry.
//symbol
struct tnode* createtree(int type, int num,char *str,int nt, struct tnode *l, struct tnode *r,struct tnode *d);
int evaluate(struct tnode *t);



