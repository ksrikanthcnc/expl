#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#define brkp	raise(SIGINT);
//#define BUG
//------------------nt
	#define FMAIN 1000
	#define TMAIN 999
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
	#define nt_NEW 50
	#define nt_DELETE 51
	#define nt_SELF 52
#ifdef BUG
	#define puts(str) tabtemp=0; while(tabtemp++<tabs) printf("\t"); printf(str); printf("\n");
	#define target_file stdout
	#endif
#ifndef BUG
	#define puts //puts
	FILE *target_file;
	#endif
//-------------global variables
	int line=1;
	char *funcname;
	int tabs=0,tabtemp;
	int binding=0;
	int gbinding=4096;
	int flabel=1;
	int funcposition=0;
	int fieldindex=0;
	int classflag=0;
	int cindex=0;
	int heapbinding=0;
	int fieldcount,methodcount;
	struct Classtable *class;
	struct Classtable *ctype;
union Constant{
	int intval;
	char* strval;};
typedef struct tnode {
	struct Typetable *t;
	int num;
	char *str;
	int nt;
	union Constant value;
	struct tnode *left,*right,*down,*arglist;
	struct Gsymbol *Gentry;
	struct Lsymbol *Lentry;
	struct Classtable *class;}tnode;
struct Gsymbol{
	char* name;
	struct Typetable *type;
	struct Classtable *class;
	int size;
	int binding;
	struct Paramstruct *paramlist;
	int flabel;
	int arr;
	char *tuplename;
	struct Gsymbol* next;}*ghead=NULL;
struct Paramstruct{
	char* name;
	struct Typetable *type;
	struct Paramstruct* next;}*phead=NULL;
struct Lsymbol{
	char *name;
	struct Typetable *type;
	struct Classtable *class;
	int binding;
	struct Lsymbol *next;}*lhead=NULL;
struct Typetable{
	char *name;
	int size;
	struct Fieldlist *fields;
	struct Typetable *next;}*thead=NULL;
struct Fieldlist{
	char *name;
	int fieldindex;
	struct Typetable *type;
	struct Classtable *ctype;
	struct Fieldlist *next;}*fhead=NULL;
struct Classtable {
 	char *name;
	struct Fieldlist *memberfield;
	struct Memberfunclist *memberfunc;
	struct Classtable *parent;
	int index;
	int fieldcount;
	int methodcount;
	struct Classtable *next;}*chead=NULL;
struct Memberfunclist {
 	char *name;
	struct Typetable *type;
	struct Paramstruct *paramlist;
	int funcposition;
 	int flabel;
	struct Memberfunclist *next;}*mhead=NULL;
//-------------------debug nodes
	struct tnode *dnode,*ddnode;
	struct Gsymbol *gnode;
	struct Paramstruct *pnode;
	struct Lsymbol *lnode;
	struct Typetable *Tnode;
	struct Fieldlist *fnode;
	struct Classtable *cnode;
//-------------------astree.c
	struct tnode* createtree(struct Typetable *type, int num,char *str,int nt, struct tnode *l, struct tnode *r,struct tnode *d,struct Gsymbol *gentry,struct tnode *arglist,struct Lsymbol *lentry);
	struct Classtable* CInstall(char *name,char *parent);
	struct Classtable* CLookup(char *name);
	void CFInstall(char *typename, char *name);
	struct Fieldlist *CFLookup(struct Classtable *class, char *name);
	void CMInstall(char *name, struct Typetable *type, struct Paramstruct *Paramlist);
	struct Memberfunclist *CMLookup(struct Classtable *class, char *name);
	struct Gsymbol *GLookup(char * name);
	void GInstall(char *name, struct Typetable *type, int size);
	void PInstall(char* name,struct Typetable *type);
	struct Paramstruct* PLookup(char *name);
	void LInstall(char *name, struct Typetable *type);
	struct Lsymbol *LLookup(char* name);
	void TypeTableCreate();
	void TInstall(char *name,int size, struct Fieldlist *fields);
	struct Typetable* TLookup(char *name);
	void FInstall(char *name,int fieldIndex,struct Typetable *type);
	struct Fieldlist* FLookup(struct Typetable *type, char *name);
	struct Fieldlist* FLookmember(struct Typetable *type, char *name);
	int GetSize (struct Typetable * type);
//-----------------codegen.c
	void generate();
	int getReg();
	void freeReg();
	int getLabel();
	int codeGen(struct tnode *t);
	void funcGen(char *g);
	void Write(int reg,	int ret);
	void Read(int addr,	int ret);
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
	void fetch_local_loc_to(struct tnode *t,int i);
//--------------------expl.y
	void checkid(struct tnode *t);
	void checkidid(struct tnode *t1,struct tnode *t3);
	void checktype(struct Typetable *t1, char *member);
	void checkmember(struct tnode *parent, struct tnode *member);
	void yyerror(char const *s);
	void func(struct Paramstruct* phead);
	void tprint();
	void gprint();
	void lprint();
	void cprint();
	void ldealloc(struct Lsymbol *lhead);
	void bdealloc(struct tnode *body);
//