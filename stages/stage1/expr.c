#include <stdio.h>
#include "y.tab.c"
#define reg_index int
/*
typedef struct tnode{
	int val;			//value of for the expression tree
	char *op;			//indicates the opertor branch
	struct tnode *left,*right;  	//left and right branches
};
*/

reg_index reg;
FILE *target_file;

reg_index getReg(){
	reg++;
	if(reg>20){
		printf("Out of Registers");
		exit(0);
	}	return reg;
}

void freeReg(){
	reg--;
}


reg_index codeGen( struct tnode *t) {
	if (t->val!=NULL){
		reg_index reg;
		reg = getReg();
		fprintf(target_file, "MOV R%d, %d\n", reg,t->val);
		return reg;
	}
	reg_index p;
	reg_index q;
	p=codeGen(t->left);
	q=codeGen(t->right);
    switch(*(t->op)){
        case '+' : 	fprintf(target_file, "ADD R%d, R%d\n", p,q);
                   break;
        case '-' : 	fprintf(target_file, "SUB R%d, R%d\n", p,q);
                   break;
        case '*' : 	fprintf(target_file, "MUL R%d, R%d\n", p,q);
                   break;
        case '/' : 	fprintf(target_file, "DIV R%d, R%d\n", p,q);
                   break;
	}
	freeReg();
	return p;
}

int main(){
	reg_index ans;
	struct tnode *t;
	t = yyparse();
//	printf("%d\n",__LINE__);
	char *targetfile="x.xsm";
	target_file=fopen(targetfile,"w+");
	fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(target_file, "BRKP\n");
	reg=-1;
	ans=codeGen(t);
	fprintf(target_file, "BRKP \t\tans:R%d\n",ans);
	fprintf(target_file, "MOV [4096],R%d\n",ans);
	Write(ans);
	Exit();
}

void Write(reg){
	reg_index t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Write\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, -2\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",reg);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d\n",reg);
	t=getReg();
	fprintf(target_file, "POP R1\n",t);
	fprintf(target_file, "POP R1\n",t);
	fprintf(target_file, "POP R1\n",t);
	fprintf(target_file, "POP R1\n",t);
}

void Exit(){
	fprintf(target_file, "INT 10\n");
}
