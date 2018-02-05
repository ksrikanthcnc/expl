#include <signal.h>
#define brkp	raise(SIGINT);
//#define boo 	printf("\t\t\t\tERROR:\t(File:%s\tfunc:%s\tLine:%d)\n",__FILE__,__func__,__LINE__);
//#define debug	{printf("debug\n");}

#define t_NULL 0
#define t_BOOL 1
#define t_INT 2
#define t_CHAR 3
#define t_INARR 4
#define t_CHARR 5
#define t_INPTR 6
#define t_CHPTR 7

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
#define nt_PTR 33
#define nt_FUNC 34
#define nt_RET 35
#define nt_BRKP 37
#define nt_EXIT 38

int val[26];
int line=1;
//

typedef struct tnode {
	int t;
	int num;//offset,address for pointer,no.of arguements
	char *str;
	int nt;
	struct tnode *left,*right,*down, *arglist;
	struct Gsymbol *Gentry;
	struct Lsymbol *Lentry;
}tnode;
struct tnode *qwer;



struct Gsymbol{
	char* name;
	int type;
	int size;
	int binding;
	struct Paramstruct *paramlist;
	int flabel;
	int arr;
	struct Gsymbol* next;
}*ghead;
int binding=4096;
struct Gsymbol *GLookup(char * name);
void GInstall(char *name, int type, int size);



struct Paramstruct{
	char* name;
	int type;
	struct Paramstruct* next;
}*phead;

void Pinstall(char* name,int type);
struct Paramlist* PLookup(char *name);



struct Lsymbol{
	char *name;
	int type;//struct Typetable
	int binding;
	struct Lsymbol *next;
}*lhead;
//void LInstall(char *name, struct Typetable *type);
void LInstall(char *name, int type);
struct Lsymbol *LLookup(char* name);



struct tnode* createtree(int type, int num,char *str,int nt, struct tnode *l, struct tnode *r,struct tnode *d,struct Gsymbol *gentry,struct tnode *arglist,struct Lsymbol *lentry);
void LocalParam(struct Paramstruct* phead,struct Gsymbol *g);

int generate(FILE *target_file);
int gerReg();
void freeReg();
int getLabel();

int codeGen(struct tnode *t,FILE *target_file);

void Write(int reg,FILE *target_file,int ret);
void Read(int addr,FILE *target_file,int ret);
void Halt(FILE *target_file);
void Brkp(FILE *target_file);
void Debrkp(FILE * target_file);

void mismatch(int n, int l, int r);

int evaluate(struct tnode * t);

void debg(struct Gsymbol * g);
void debt(struct tnode * t);
