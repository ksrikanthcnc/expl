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
int glabel1[100];
int glabel2[100];
int top=-1;

reg_index reg;
int label;
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

int getLabel(){
	label++;
	return label;
}


reg_index codeGen( struct tnode *t) {
	if(t==NULL){
		//puts("Null");
		return;
	}
	reg_index regno,ret;
	reg_index r1,r2;
	switch(t->type){
		case 'i':
			//puts("read-int");
			regno = getReg();
			fprintf(target_file, "MOV R%d, %d\n", regno,t->num);
			//puts("read-ed-int");
			return regno;
			break;
		case 'c':
			//puts("read-char");
			regno = getReg();
			fprintf(target_file, "MOV R%d, [%d]\n", regno,4096+(t->id-'a'));
			//puts("read-ed-char");
			return regno;
			break;
		case 'b':
			r1=codeGen(t->left);
			r2=codeGen(t->right);
			if(strcmp((t->func),"<")==0){fprintf(target_file,"LT R%d, R%d\n",r1,r2);freeReg();return r1;}
			if(strcmp((t->func),">")==0){fprintf(target_file,"GT R%d, R%d\n",r1,r2);freeReg();return r1;}
			if(strcmp((t->func),"<=")==0){fprintf(target_file,"LE R%d, R%d\n",r1,r2);freeReg();return r1;}
			if(strcmp((t->func),">=")==0){fprintf(target_file,"GE R%d, R%d\n",r1,r2);freeReg();return r1;}
			if(strcmp((t->func),"!=")==0){fprintf(target_file,"NE R%d, R%d\n",r1,r2);freeReg();return r1;}
			if(strcmp((t->func),"==")==0){fprintf(target_file,"EQ R%d, R%d\n",r1,r2);freeReg();return r1;}
			break;
		case 'n':
			//puts("left-ing");
			codeGen(t->left);
			//puts("lefted");
			//puts("righting");
			codeGen(t->right);
			//puts("righted");
			return;
			break;
		case 'a':
			//puts("op");
			r2=codeGen(t->right);
			if(strcmp((t->func),"=")==0){fprintf(target_file,"MOV [%d], R%d\n",4096+(t->left->id-'a'),r2);freeReg();return;}
			r1=codeGen(t->left);
			if(strcmp((t->func),"+")==0){fprintf(target_file,"ADD R%d, R%d\n",r1,r2);freeReg();return r1;}
			if(strcmp((t->func),"-")==0){fprintf(target_file,"SUB R%d, R%d\n",r1,r2);freeReg();return r1;}
			if(strcmp((t->func),"*")==0){fprintf(target_file,"MUL R%d, R%d\n",r1,r2);freeReg();return r1;}
			if(strcmp((t->func),"/")==0){fprintf(target_file,"DIV R%d, R%d\n",r1,r2);freeReg();return r1;}
			break;
		case 'f':
			if(strcmp(t->func,"read")==0){
				//puts("read");
				ret=getReg();
				Read(4096+(t->down->id-'a'),ret);
				freeReg();
				//puts("read-ed");
				return;}
			if(strcmp(t->func,"write")==0){
				//puts("write");
				ret=getReg();
				Write(codeGen(t->down),ret);
				freeReg();
				//puts("written");
				return;}
			if(strcmp(t->func,"break")==0){
				//puts("break");
				fprintf(target_file, "JMP L%d\n",glabel2[top]);
				return;}
			if(strcmp(t->func,"continue")==0){
				//puts("break");
				fprintf(target_file, "JMP L%d\n",glabel1[top]);
				return;}
			break;
		case 's':
			if(strcmp(t->func,"while")==0){
				//puts("while");
				top++;
				int label_1=getLabel();
				glabel1[top]=label_1;
				int label_2=getLabel();
				glabel2[top]=label_2;
				int result;
//				printf("L%d\n",label_1);
				fprintf (target_file, "L%d:\n", label_1);
				//puts("condition");
				result=codeGen(t->left);
				fprintf(target_file, "JZ R%d, L%d\n",result,label_2);
				//puts("body");
				codeGen(t->right);
				fprintf(target_file, "JMP L%d\n", label_1);
//				printf("L%d\n",label_2);
				fprintf(target_file, "L%d:\n", label_2);
				top--;
				//puts("while-ed");
				return;
			}
			if(strcmp(t->func,"if")==0){
				//puts("if");
				int label_1=getLabel();
				int result;
				//puts("condition");
				result=codeGen(t->left);
				fprintf(target_file, "JZ R%d, L%d\n",result,label_1);
				//puts("body");
				codeGen(t->right);
//				printf("L%d\n",label_1);
				fprintf(target_file, "L%d:\n", label_1);
				//puts("if-ed");
				return;
			}
			if(strcmp(t->func,"ifelse")==0){
				//puts("ifelse");
				int label_1=getLabel();
				int label_2=getLabel();
				int result;
				//puts("condition");
				result=codeGen(t->left);
				fprintf(target_file, "JZ R%d, L%d\n",result,label_1);
				//puts("then");
				codeGen(t->down);
				fprintf(target_file, "JMP L%d\n", label_2);
				fprintf(target_file, "L%d:\n", label_1);
				//puts("else");
				codeGen(t->right);
				fprintf(target_file, "L%d:\n", label_2);
				//puts("ifelse-ed");
				return;
			}
			break;
		default:
			//puts("codeGen-boo");
			;
	}
}

void Write(reg_index reg,reg_index ret){
	reg_index t;
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

void halt(){
	reg_index t;
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Exit\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, \"\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
}

void brkp(){
	fprintf(target_file, "BRKP\n");
}

void debrkp(){
	fprintf(target_file, "BRKP--DEBUG\n");
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
	halt();
	puts("Compilation successful");
	return 0;
}
