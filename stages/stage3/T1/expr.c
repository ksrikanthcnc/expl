#include <stdio.h>
#include "y.tab.c"
#define reg_index int
#include <string.h>
//int stack[26];
/*
typedef struct tnode{
	int val;			//value of for the expression tree
	char *op;			//indicates the opertor branch
	struct tnode *left,*right;  	//left and right branches
};
*/
reg_index getReg();
void freeReg();
reg_index codeGen( struct tnode *t) ;
void Write(reg_index reg,reg_index ret);
void Read(int addr,reg_index ret);
void Exit();
void brkp();

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
	if(t==NULL){
		//puts("Null");
		return;
	}
	reg_index regno,ret;
	if(t->type=='n'){
		//puts("left-ing");
		codeGen(t->left);
		//puts("lefted");
		//puts("righting");
		codeGen(t->right);
		//puts("righted");
		return;
	}
	else if(t->type=='i'){
		//puts("read-int");
		regno = getReg();
		fprintf(target_file, "MOV R%d, %d\n", regno,t->num);
		//puts("read-ed-int");
		return regno;}
	else if(t->type=='c'){
		//puts("read-char");
		regno = getReg();
		fprintf(target_file, "MOV R%d, [%d]\n", regno,4096+(t->id-'a'));
		//puts("read-ed-char");
		return regno;}
	else if(t->op=='+' || t->op=='-' || t->op=='*' || t->op=='/'){
		//puts("op");
		reg_index p;
		reg_index q;
		p=codeGen(t->left);
		q=codeGen(t->right);
		switch(t->op){
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
		return p;}
	else if(t->op == '='){
		//puts("eq");
		reg_index r;
		r = getReg();
		r=codeGen(t->right);
		fprintf(target_file, "MOV [%d], R%d\n", 4096+(t->left->id-'a'),r);
		debrkp();
		freeReg();
		//puts("eq");
		return ;}
	else if(strcmp(t->func,"read")==0){
		//puts("read");
		ret=getReg();
		Read(4096+(t->down->id-'a'),ret);
		freeReg();
		//puts("read-ed");
		return;}
	else if(strcmp(t->func,"write")==0){
		//puts("write");
		ret=getReg();
		Write(codeGen(t->down),ret);
		freeReg();
		//puts("written");
		return;}
	else{
		//puts("codeGen-boo");
	}
}

void Write(reg_index reg,reg_index ret){
	reg_index t;
	ret=getReg();
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Write\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, -2\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",reg);
	fprintf(target_file, "MOV R%d,\"\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d\n",t);
	fprintf(target_file, "POP R%d\n",t);
	fprintf(target_file, "POP R%d\n",t);
	fprintf(target_file, "POP R%d\n",t);
	freeReg();
	fprintf(target_file, "BRKP\n");
}

void Read(int addr,reg_index ret){
	reg_index t;
	ret=getReg();
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Read\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, -1\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, %d\n",t,addr);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, \"\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d\n",t);
	fprintf(target_file, "POP R%d\n",t);
	fprintf(target_file, "POP R%d\n",t);
	fprintf(target_file, "POP R%d\n",t);
	freeReg();
	fprintf(target_file, "BRKP\n");
}

void Exit(){
	fprintf(target_file, "INT 10\n");
}

void brkp(){
	fprintf(target_file, "BRKP\n");
}

void debrkp(){
	fprintf(target_file, "BRKP--DEBUG\n");
}

int evaluate(struct tnode *t){
    if(t->type == 'i'){
        return t->num;
    }
    else{
        switch(t->op){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
}

int main(){
	reg_index ans,ret;
	struct tnode *t;
	t = yyparse();
	char *targetfile="x.xsm";
	target_file=fopen(targetfile,"w+");
	fprintf(target_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(target_file, "MOV SP, 4200\n");
	fprintf(target_file, "BRKP\n");
	reg=-1;
	//puts("");
	ans=codeGen(t);
	brkp();
	Exit();
}

