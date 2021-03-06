#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#define brkp	raise(SIGINT);
//#define boo 	printf("\t\t\t\tERROR:\t(File:%s\tfunc:%s\tLine:%d)\n",__FILE__,__func__,__LINE__);
//#define debug	{printf("debug\n");}

//-------------------t
	/*
	#define t_NULL 0
	#define t_BOOL 1
	#define t_INT 2
	#define t_CHAR 3
	#define t_INARR 4
	#define t_CHARR 5
	#define t_INPTR 6
	#define t_CHPTR 7
	#define t_AINT	8
	#define t_ACHAR	9
	#define t_TUPLE 10
	#define t_TUPPTR 11
	*/
//------------------nt_
//NULL=0;

	#define nt_NUM 36
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
	#define nt_CONTINUE 24
	#define nt_IFELSE 25
	#define nt_REPEAT 26
	#define nt_UNTIL 27
	#define nt_ARR 28
	#define nt_STR 29
	#define nt_MOD 30
	#define nt_APTR 31
	#define nt_SPTR 32
	//#define nt_PTR 33
	#define nt_FUNC 34
	#define nt_RET 35
	#define nt_BRKP 37
	#define nt_EXIT 38
	#define nt_INIT 39
	#define nt_ALLOC 40
	#define nt_FREE 41
	#define nt_USERROOT 42
	#define nt_USERNODE 43
	#define nt_TRUE 44
	#define nt_FALSE 45
	#define nt_AND 46
	#define nt_OR 47
	#define nt_NOT 48
	#define nt_NUL 49

int val[26];
int line=1;
char *funcname;
FILE *target_file;//comment for consoling
int tabs=0,tabtemp;
//char *target_file="stdout";

union Constant{
	int intval;
	char* strval;
};
typedef struct tnode {
	struct Typetable *t;
	int num;
	char *str;
	int nt;
	union Constant value;
	struct tnode *left,*right,*down,*arglist;
	struct Gsymbol *Gentry;
	struct Lsymbol *Lentry;
}tnode;

struct Gsymbol{
	char* name;
	struct Typetable *type;
	int size;
	int binding;
	struct Paramstruct *paramlist;
	int flabel;
	int arr;
	char *tuplename;
	struct Gsymbol* next;
}*ghead;
int binding=0;
int gbinding=4096;
struct Gsymbol *GLookup(char * name);
void GInstall(char *name, struct Typetable *type, int size);

struct Paramstruct{
	char* name;
	struct Typetable *type;
	struct Paramstruct* next;
}*phead;
void PInstall(char* name,struct Typetable *type);
struct Paramstruct* PLookup(char *name);

struct Lsymbol{
	char *name;
	struct Typetable *type;
	int binding;
	struct Lsymbol *next;
}*lhead;
void LInstall(char *name, struct Typetable *type);
struct Lsymbol *LLookup(char* name);

struct Typetable{
    char *name;
    int size;
    struct Fieldlist *fields;
    struct Typetable *next;
}*thead;
struct Fieldlist{
  char *name;
  int fieldIndex;
  struct Typetable *type;
  struct Fieldlist *next;
}*fhead;
void TypeTableCreate();
void TInstall(char *name,int size, struct Fieldlist *fields);
struct Typetable* TLookup(char *name);
void FInstall(char *name,int fieldIndex,struct Typetable *type);
struct Fieldlist* FLookup(struct Typetable *type, char *name);
struct Fieldlist* FLookmember(struct Typetable *type, char *name);
int GetSize (struct Typetable * type);

struct tnode* createtree(struct Typetable *type, int num,char *str,int nt, struct tnode *l, struct tnode *r,struct tnode *d,struct Gsymbol *gentry,struct tnode *arglist,struct Lsymbol *lentry);

struct tnode *dnode;
struct Gsymbol *gnode;
struct Paramstruct *pnode;
struct Lsymbol *lnode;
struct Typetable *Tnode;
struct Fieldlist *fnode;


void generate();
int getReg();
void freeReg();
int getLabel();

int codeGen(struct tnode *t);
void funcGen(struct Gsymbol *g);
void Write(int reg,  int ret);
void Read(int addr,  int ret);
void ReadReg(int reg_addr,int ret);
void Halt();
void Brkp();
void Debug(int i);
void init(int ret);
void SDebug(char *func);
void alloc_to(int size,int i);
void freee(int reg_addr);
void saveReg();
void restReg();

void mismatch(int n, struct Typetable *l, struct Typetable *r);

int evaluate(struct tnode * t);

void fetch_local_loc_to(struct tnode *t,int i);
/*
void debg(struct Gsymbol * g);
void debt(struct tnode * t);
*/


void checkid(struct tnode *t);
void checkidid(struct tnode *t1,struct tnode *t3);
void checktype(struct Typetable *t1, char *member);
void yyerror(char const *s);
void func(struct Paramstruct* phead);
void tprint();
void gprint();
void lprint();

void ldealloc(struct Lsymbol *lhead);
void bdealloc(struct tnode *body);