
typedef struct Gsymbol
{
	char *name;
	int type,size,binding;
	struct Gsymbol *next;
}Gsymbol;


struct Gsymbol *Ghead,*tempst;
int varadrs;

struct Gsymbol *Lookup(char * name);
void Install(char *name, int type, int size);