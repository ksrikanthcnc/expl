#define type_int 1
#define type_bool 2
#define type_char 3
#define type_null 4
#define type_arrint 5
#define type_str 6

#define nodetype_LEAF 0
#define nodetype_ID 1
#define nodetype_PLUS 2
#define nodetype_MINUS 3
#define nodetype_MUL 4
#define nodetype_DIV 5 
#define nodetype_ASGN 6
#define nodetype_READ 7
#define nodetype_WRITE 8
#define nodetype_NULL 9
#define nodetype_IF 10
#define nodetype_THEN 11
#define nodetype_ELSE 12
#define nodetype_ENDIF 13
#define nodetype_WHILE 14
#define nodetype_DO 15
#define nodetype_ENDWHILE 16
#define nodetype_LT 17
#define nodetype_LE 18
#define nodetype_GT 19
#define nodetype_GE 20
#define nodetype_EQ 21
#define nodetype_NE 22

#define nodetype_ARRID 23
#define nodetype_ARRASGN 24
#define nodetype_ARRREAD 25

int *val[26];

typedef struct tnode 
{
	int type;
	int nodetype;
	int val;
	char *varname;	
	struct tnode *left,*right,*end;
	struct Gsymbol *Gentry;
}tnode;

struct tnode* createtree(int val, int nodetype,int type, char *c,struct tnode *l, struct tnode *r,struct tnode *d);
int abst_evaluate(struct tnode *t);
