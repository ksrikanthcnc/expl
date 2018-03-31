#ifndef INCL
	#include "headers.h"
	#endif
//----------------variables
	int reg=-1,tempreg;
	int label=0;
	int break2[100];
	int cont1[100];
	int top=-1;
	int readflag=0;
int getReg(){
	reg++;
	#ifdef BUG
	printf("\t\t\t\t+");
	for(int s=reg;s>-1;s--) printf("#");
	printf("\n");
	#endif
	if(reg>19){
		printf("Out of registers\n");
		exit(1);}
	return reg;}
void freeReg(){
	reg--;
	#ifdef BUG
	printf("\t\t\t\t-");
	for(int s=reg;s>-1;s--) printf("#");
	printf("\n");
	#endif
	}
int getLabel(){label++;return label;}
void generate(){
	puts("\t\t\t\t+Generating Code");
	fprintf(target_file,"F%d: \n",TMAIN);
	fprintf(target_file,"MOV SP,%d --'start'\n",gbinding-1);
	fprintf(target_file,"MOV BP,%d --start\n",gbinding);
	fprintf(target_file,"PUSH R0 --ret.val\n");
	struct Classtable *ctemp=chead;
	struct Memberfunclist *mtemp;
	int base;
	if(chead!=NULL){
		base=4096+chead->index*8;
		int *func;
		func=malloc(sizeof(int)*8);
		while(ctemp){
			mtemp=ctemp->memberfunc;
			for(int i=0;i<8;i++)	func[i]=0;
			while(mtemp){
				if(func[mtemp->funcposition]==0)
					fprintf(target_file,"MOV [%d],F%d  --vfunc\n",base+mtemp->funcposition,mtemp->flabel);
				func[mtemp->funcposition]=1;
				mtemp=mtemp->next;}
			base-=8;
			ctemp=ctemp->next;}}
	fprintf(target_file,"CALL F%d  --'main'\n",FMAIN);
	Halt(target_file);
	puts("\t\t\t\t-Generated");
	;}
int codeGen(struct tnode *t){
	tabs++;
	int i,j,k,ret,label1,label2,result,regtemp;
	struct Gsymbol *node,*temp;
	struct tnode *atemp;
	struct Lsymbol *ltemp;
	switch(t->nt){
	//--------------nodes
		case nt_NODE:
			puts("\t\t\t\t+node");
			puts("\t\t\t\t+left");
			codeGen(t->left);
			puts("\t\t\t\t+right");
			codeGen(t->right);
			break;
		case nt_IF:
			puts("\t\t\t\t+if");
			result=codeGen(t->left);
			label1=getLabel();
			fprintf(target_file,"JZ R%d,L%d \n",result,label1);
			freeReg();
			codeGen(t->right);
			fprintf(target_file,"L%d: \n",label1);
			puts("\t\t\t\t-if");
			break;
		case nt_IFELSE:
			puts("\t\t\t\t+ifelse");
			label1=getLabel();
			label2=getLabel();
			result=codeGen(t->left);
			fprintf(target_file,"JZ R%d,L%d \n",result,label1);
			freeReg();
			codeGen(t->down);
			fprintf(target_file,"JMP L%d \n",label2);
			fprintf(target_file,"L%d: \n",label1);
			codeGen(t->right);
			fprintf(target_file,"L%d: \n",label2);
			puts("\t\t\t\t-ifelse");
			break;
		case nt_WHILE:
			puts("\t\t\t\t+while");
			top++;
			break2[top]=label1=getLabel();
			cont1[top]=label2=getLabel();
			fprintf(target_file,"L%d: \n",label1);
			result=codeGen(t->left);
			fprintf(target_file,"JZ R%d,L%d \n",result,label2);
			freeReg();
			codeGen(t->right);
			fprintf(target_file,"JMP L%d \n",label1);
			fprintf(target_file,"L%d: \n",label2);
			top--;
			puts("\t\t\t\t-while");
			break;
		case nt_BREAK:
			puts("\t\t\t\t+break");
			if(top<0) {puts("\t\t\t\tbreak not in loop");
						;}
			else{puts("\t\t\t\tbreak");
				fprintf(target_file, "JMP L%d \n",break2[top]);}
			puts("\t\t\t\t-break");
			break;
		case nt_CONTINUE:
			puts("\t\t\t\t+cont");
			if(top<0) {puts("\t\t\t\tcontinue not in loop");
						;}
			else{puts("\t\t\t\tcontinue");
				fprintf(target_file, "JMP L%d \n",cont1[top]);}
			puts("\t\t\t\t-cont");
			break;
	//--------------id
		case nt_NUM:
			puts("\t\t\t\t+num");
			i=getReg();
			fprintf(target_file, "MOV R%d,%d --num\n",i,t->num);
			puts("\t\t\t\t-num");
			tabs--;
			return i;
			break;
		case nt_STR:
			puts("\t\t\t\t+str");
			i=getReg();
			fprintf(target_file, "MOV R%d,%s --str\n",i,t->str);//----------------
			puts("\t\t\t\t-str");
			tabs--;
			return i;
			break;
		case nt_ID:
			puts("\t\t\t\t+id");
			i=getReg();
			if(t->Lentry==NULL){
				j=t->Gentry->binding+t->num;
				fprintf(target_file, "MOV R%d,[%d] --Gid\n",i,j);}
			else{
				j=getReg();
				fetch_local_loc_to(t,j);
				fprintf(target_file, "MOV R%d,[R%d] --Lid.fetch\n",i,j);
				freeReg();}
			puts("\t\t\t\t-id");
			tabs--;
			return i;
			break;
		case nt_APTR:
			puts("\t\t\t\t+pointer-&");
			i=getReg();
			if(t->Lentry==NULL){
				fprintf(target_file, "MOV R%d, %d --Gaptr\n",i,t->Gentry->binding+t->num);}
			else{
				j=getReg();
				fetch_local_loc_to(t,j);
				fprintf(target_file, "MOV R%d,R%d --Laptr\n",i,j);
				freeReg();}
			puts("\t\t\t\t-pointer-&");
			tabs--;
			return i;
			break;
		case nt_SPTR:
			puts("\t\t\t\t+pointer-*");
			i=getReg();
			if(t->Lentry==NULL){
				fprintf(target_file, "MOV R%d, [%d] --Gaddr\n",i,t->Gentry->binding+t->num);
				fprintf(target_file, "MOV R%d, [R%d] --Gval\n",i,i);}
			else{
				j=getReg();
				fetch_local_loc_to(t,j);
				fprintf(target_file, "MOV R%d,[R%d] --Laddr\n",i,j);
				fprintf(target_file, "MOV R%d, [R%d] --Lval\n",i,i);
				freeReg();}
			puts("\t\t\t\t-pointer-*");
			tabs--;
			return i;
			break;
		case nt_ARR:
			puts("\t\t\t\t+arr");
			i=getReg();
			node=t->Gentry;
			if((t->num)>node->size)
				printf("WARNING:Accessing beyond declaration!\n");
			j=codeGen(t->down);
			k=getReg();
			fprintf(target_file, "MOV R%d,%d --offset\n",k,(node->binding));
			fprintf(target_file, "ADD R%d,R%d --base+off\n",k,j);
			fprintf(target_file, "MOV R%d,[R%d] --fetch\n",i,k);
			freeReg();
			puts("\t\t\t\t-arr");
			tabs--;
			return i;
			break;
		case nt_USERROOT:
			puts("\t\t\t\t+user");
			j=codeGen(t->left);
			k=getReg();
			fprintf(target_file, "ADD R%d,%d --off\n",j,t->num);
			if(!readflag)
				fprintf(target_file, "MOV R%d,[R%d] --fetch\n",k,j);
			fprintf(target_file, "MOV R%d,[R%d] --user\n",j,j);
			puts("\t\t\t\t-user");
			freeReg();
			tabs--;
			return j;
			break;
		case nt_USERNODE:
			puts("\t\t\t\t+usernode");
			if(t->left==NULL){//root node
				puts("\t\t\t\t-user");
				if(t->Lentry==NULL){
					i=getReg();
					fprintf(target_file,"MOV R%d,[%d] --groot\n",i,t->Gentry->binding);
					puts("\t\t\t\t-usernode");
					tabs--;
					return i;}
				else{
					j=getReg();
					i=getReg();
					fetch_local_loc_to(t,i);
					fprintf(target_file, "MOV R%d,[R%d] --lroot\n",j,i);
					freeReg();
					puts("\t\t\t\t-usernode");
					tabs--;
					return j;}}
			else{
				j=codeGen(t->left);
				fprintf(target_file, "ADD R%d,%d --addr\n",j,t->num);
				fprintf(target_file, "MOV R%d,[R%d] --addr\n",j,j);
				puts("\t\t\t\t-usernode");
				tabs--;
				return j;}
			break;
		case nt_NUL:
			puts("\t\t\t\t+null");
			i=getReg();
			fprintf(target_file, "MOV R%d, \"null\" --null\n",i);
			puts("\t\t\t\t-null");
			tabs--;
			return i;
		case nt_SELF:
			puts("\t\t\t\t+self");
			i=getReg();
			fprintf(target_file, "MOV R%d,BP --(BP-?)\n",i);
			fprintf(target_file, "ADD R%d, %d --heapbind\n",i,t->num-1);
			fprintf(target_file, "MOV R%d,[R%d] --self\n",i,i);
			puts("\t\t\t\t-self");
			tabs--;
			return i;
			break;
	//--------------arth
		case nt_PLUS:
			puts("\t\t\t\t+'+'");
			i=codeGen(t->left);
			j=codeGen(t->right);
			fprintf(target_file, "ADD R%d,R%d\n",i,j );
			freeReg();
			puts("\t\t\t\t-'+'");
			tabs--;
			return i;
			break;
		case nt_MUL:
			puts("\t\t\t\t+'*'");
			i=codeGen(t->left);
			j=codeGen(t->right);
			fprintf(target_file, "MUL R%d,R%d\n",i,j );
			freeReg();
			puts("\t\t\t\t-'*'");
			tabs--;
			return i;
			break;
		case nt_MINUS:
			puts("\t\t\t\t+'-'");
			i=codeGen(t->left);
			j=codeGen(t->right);
			fprintf(target_file, "SUB R%d,R%d\n",i,j );
			freeReg();
			puts("\t\t\t\t-'-'");
			tabs--;
			return i;
			break;
		case nt_DIV:
			puts("\t\t\t\t+'/'");
			i=codeGen(t->left);
			j=codeGen(t->right);
			fprintf(target_file, "DIV R%d,R%d\n",i,j );
			freeReg();
			puts("\t\t\t\t-'/'");
			tabs--;
			return i;
			break;
		case nt_MOD:
			puts("\t\t\t\t+'mod'");
			i=codeGen(t->left);
			j=codeGen(t->right);
			fprintf(target_file, "MOD R%d,R%d\n",i,j );
			freeReg();
			puts("\t\t\t\t-'mod'");
			tabs--;
			return i;
			break;
		case nt_ASGN:
			puts("\t\t\t\t+'='");
			if(t->left->class!=NULL && t->right->class!=NULL){
				i=getReg();
				k=getReg();
				fprintf(target_file,"MOV R%d,%d --rclabind\n",i,t->right->Gentry->binding);
				fprintf(target_file,"MOV R%d,[R%d] --rclabind\n",k,i);
				j=getReg();
				fprintf(target_file,"MOV R%d,%d --lclabind\n",j,t->left->Gentry->binding);
				fprintf(target_file,"MOV [R%d],R%d --rtolcla\n",j,k);
				fprintf(target_file,"ADD R%d,1 --vfunc\n",i);
				fprintf(target_file,"MOV R%d,[R%d] --rvfunc\n",k,i);
				fprintf(target_file,"ADD R%d,1 --vfunc\n",j);
				fprintf(target_file,"MOV [R%d],R%d --lvfunc\n",j,k);
				freeReg();
				freeReg();
				freeReg();}
			else if(t->left->Lentry==NULL){//------------------------
				node=t->left->Gentry;
				if(t->left->nt==nt_SPTR){
					i=codeGen(t->right);
					j=(node->binding+t->left->num);
					k=getReg();
					fprintf(target_file,"MOV R%d,[%d] --Gsptr\n",k,j);
					fprintf(target_file,"MOV [R%d],R%d --Gsptr\n",k,i );
					freeReg();
					freeReg();//---------------------
					;}
				else if(t->left->nt==nt_STR){
					j=(node->binding)+(t->left->num);
					fprintf(target_file,"MOV [%d],\"%s\" --\"str\"\n",j,t->right->str);}
				else if(t->left->nt==nt_USERROOT){
					i=codeGen(t->left->left);
					if(t->left->left->nt==nt_SELF){
						fprintf(target_file, "ADD R%d,%d --off\n",i,t->left->num);
						j=codeGen(t->right);
						fprintf(target_file, "MOV [R%d],R%d --asgn\n",i,j);
						freeReg();}
					else{
						fprintf(target_file, "ADD R%d,%d --off\n",i,t->left->num);
						j=codeGen(t->right);
						fprintf(target_file, "MOV [R%d],R%d --asgn\n",i,j);
						freeReg();}
					freeReg();}
				else{
					if(t->left->down!=NULL)
						i=codeGen(t->left->down);
					else{
						i=getReg();
						fprintf(target_file, "MOV R%d,0 --extra\n",i);}
					j=codeGen(t->right);
					k=getReg();
					fprintf(target_file,"MOV R%d,%d --Gbind\n",k,node->binding);
					fprintf(target_file,"ADD R%d,R%d --Goff\n",k,i);
					fprintf(target_file,"MOV [R%d],R%d --Gasgn\n",k,j);
					if(t->left->class!=NULL){//class
						fprintf(target_file,"ADD R%d,1 --vfunc\n",k);
						fprintf(target_file,"MOV [R%d],%d --vfunc\n",k,t->right->down->class->index*8+4096);}
					freeReg();
					freeReg();
					freeReg();}
				}
			else if(t->left->Gentry==NULL){//Local
				k=getReg();
				if(t->left->nt==nt_SPTR){
					fetch_local_loc_to(t->left,k);
					i=codeGen(t->right);
					fprintf(target_file,"MOV R%d,[R%d] --Lsptr\n",k,k);
					fprintf(target_file,"MOV [R%d],R%d --Lsptr\n",k,i);
					freeReg();}
				else if(t->left->nt==nt_STR){
					fetch_local_loc_to(t->left,k);
					fprintf(target_file,"MOV [R%d],\"%s\" --\"str\"\n",k,t->right->str);}
				else if(t->left->nt==nt_USERROOT){
					i=codeGen(t->left->left);
					fprintf(target_file, "ADD R%d,%d --off\n",i,t->left->num);
					j=codeGen(t->right);
					fprintf(target_file, "MOV [R%d],R%d --asgn\n",i,j);
					freeReg();
					freeReg();
				}
				else{
					fetch_local_loc_to(t->left,k);
					i=codeGen(t->right);
					fprintf(target_file,"MOV [R%d],R%d --Lasgn\n",k,i);
					freeReg();}
				freeReg();}
			else{//Class
				i=getReg();
				fprintf(target_file, "MOV R%d,BP --(BP-?)\n",i);
				fprintf(target_file, "ADD R%d, %d --heapbind\n",i,t->left->left->num-1);
				fprintf(target_file,"MOV [R%d],R%d --self\n",i,i);
				fprintf(target_file,"ADD R%d,%d --off\n",i,t->left->num);
				j=codeGen(t->right);
				fprintf(target_file,"MOV [R%d],R%d --new\n",i,j);
				fprintf(target_file,"ADD R%d,1 --vfunc\n",i);
				fprintf(target_file,"MOV [R%d], %d --vfunc\n",i,CFLookup(t->left->class,t->str)->ctype->index*8+4096);
			}
			puts("\t\t\t\t-'='");
			break;
	//--------------comp
		case nt_LT:
			puts("\t\t\t\t+'<'");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "LT R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'<'");
			tabs--;
			return i;
			break;
		case nt_LE:
			puts("\t\t\t\t+'<='");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "LE R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'<='");
			tabs--;
			return i;
			break;
		case nt_GT:
			puts("\t\t\t\t+'>'");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "GT R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'>'");
			tabs--;
			return i;
			break;
		case nt_GE:
			puts("\t\t\t\t+'>='");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "GE R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'>='");
			tabs--;
			return i;
			break;
		case nt_EE:
			puts("\t\t\t\t+'=='");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "EQ R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'=='");
			tabs--;
			return i;
			break;
		case nt_NE:
			puts("\t\t\t\t+'!='");
			i = codeGen(t->left);
			j = codeGen(t->right);
			fprintf(target_file, "NE R%d,R%d\n", i, j);
			freeReg();
			puts("\t\t\t\t-'!='");
			tabs--;
			return i;
			break;
		case nt_TRUE:
			puts("\t\t\t\t+true");
			i=getReg();
			fprintf(target_file, "MOV R%d, 1 --true\n",i);
			puts("\t\t\t\t-true");
			tabs--;
			return i;
		case nt_FALSE:
			puts("\t\t\t\t+false");
			i=getReg();
			fprintf(target_file, "MOV R%d, 0 --false\n",i);
			puts("\t\t\t\t-false");
			tabs--;
			return i;
		case nt_NOT:
			puts("\t\t\t\t+not");
			label1=getLabel();
			label2=getLabel();
			j=codeGen(t->down);
			i=getReg();
			fprintf(target_file, "MOV R%d,0 --not\n",i);
			fprintf(target_file, "EQ R%d,R%d --not\n",j,i);
			freeReg();
			fprintf(target_file, "JZ R%d,L%d \n",j,label1);
			fprintf(target_file, "MOV R%d, 1 --set1\n",j);
			fprintf(target_file, "JMP L%d \n",label2);
			fprintf(target_file, "L%d: \n",label1);
			fprintf(target_file, "MOV R%d,0 --set0\n",j);
			fprintf(target_file, "L%d: \n",label2);
			puts("\t\t\t\t-not");
			tabs--;
			return j;
		case nt_AND:
			puts("\t\t\t\t+and");
			label1=getLabel();
			label2=getLabel();
			k=getReg();
			fprintf(target_file, "MOV R%d,1 --and\n",k);
			i=codeGen(t->left);
			fprintf(target_file, "EQ R%d,R%d --cond1?\n",i,k);
			fprintf(target_file, "JZ R%d,L%d \n",i,label1);
			freeReg();
			fprintf(target_file, "MOV R%d,1 \n",k);
			j=codeGen(t->right);
			fprintf(target_file, "EQ R%d,R%d --cond2?\n",j,k);
			fprintf(target_file, "JZ R%d,L%d \n",j,label1);
			freeReg();
			freeReg();
			result=getReg();
			fprintf(target_file, "MOV R%d,1 --ans1\n",result);
			fprintf(target_file, "JMP L%d \n",label2);
			fprintf(target_file, "L%d: \n",label1);
			fprintf(target_file, "MOV R%d,0 --ans0\n",result);
			fprintf(target_file, "L%d: \n",label2);
			puts("\t\t\t\t-and");
			tabs--;
			return result;
		case nt_OR:
			puts("\t\t\t\t+or");
			label1=getLabel();
			label2=getLabel();
			k=getReg();
			fprintf(target_file, "MOV R%d,0 --or\n",k);
			i=codeGen(t->left);
			fprintf(target_file, "EQ R%d,R%d --cond1?\n",i,k);
			fprintf(target_file, "JZ R%d,L%d \n",i,label1);
			freeReg();
			fprintf(target_file, "MOV R%d,0 \n",k);
			j=codeGen(t->right);
			fprintf(target_file, "EQ R%d,R%d --cond2?\n",j,k);
			fprintf(target_file, "JZ R%d,L%d \n",j,label1);
			freeReg();
			freeReg();
			result=getReg();
			fprintf(target_file, "MOV R%d,0 --ans0\n",result);
			fprintf(target_file, "JMP L%d \n",label2);
			fprintf(target_file, "L%d: \n",label1);
			fprintf(target_file, "MOV R%d,1 --ans1\n",result);
			fprintf(target_file, "L%d: \n",label2);
			puts("\t\t\t\t-or");
			tabs--;
			return result;
	//--------------syscalls
		case nt_READ:
			puts("\t\t\t\t+read");
			readflag=1;
			saveReg();
			if(t->down->Lentry!=NULL){
				j=getReg();
				if(t->down->nt==nt_USERROOT){
					i=codeGen(t->left);
					fprintf(target_file, "MOV R%d,R%d --rluser\n",j,i);
					freeReg();
				}
				else{
					fetch_local_loc_to(t->down,j);}
				ret = getReg();
				ReadReg(j, ret);
				freeReg();
				freeReg();}
			else if(t->down->Gentry!=NULL){
				if(t->down->nt!=nt_ARR)
					i=codeGen(t->down);
				else
					i=codeGen(t->down->down);
				k=getReg();
				if(t->down->nt!=nt_USERROOT){
					fprintf(target_file,"MOV R%d,%d --Rbind\n",k,t->down->Gentry->binding);
					fprintf(target_file,"ADD R%d,R%d --Roff\n",k,i);}
				else{
					fprintf(target_file,"MOV R%d,R%d --Roff\n",k,i);
				}
				freeReg();
				ret=getReg();
				ReadReg(k,ret);
				freeReg();
				freeReg();}
			else{
				i=getReg();
				fprintf(target_file, "MOV R%d,BP --(BP-?)\n",i);
				fprintf(target_file, "ADD R%d, %d --heapbind\n",i,t->down->left->num-1);
				fprintf(target_file,"MOV R%d,[R%d] --self\n",i,i);
				fprintf(target_file,"ADD R%d,%d --off\n",i,t->down->num);
				ReadReg(i,i);
				freeReg();}
			readflag=0;
			restReg();
			puts("\t\t\t\t-read");
			break;
		case nt_WRITE:
			puts("\t\t\t\t+write");
			saveReg();
			i=codeGen(t->down);
			ret=getReg();
			Write(i,ret);
			freeReg();
			freeReg();//--------------------------
			restReg();
			puts("\t\t\t\t-write");
			break;
		case nt_RET:
			puts("\t\t\t\t+ret");
			ltemp=lhead;
			i=getReg();
			while(ltemp!=NULL){
				if(ltemp->binding>0)
					fprintf(target_file, "POP R%d --locals\n",i);
				ltemp=ltemp->next;}
			freeReg();
			j=getReg();
			i=codeGen(t->down);
			fprintf(target_file, "MOV R%d,BP\n",j);
			fprintf(target_file, "SUB R%d,2 --(BP-2)\n",j);
			fprintf(target_file, "MOV [R%d],R%d --sav.result\n",j,i);
			freeReg();//--------------------------------
			freeReg();
			j=getReg();
			fprintf(target_file, "MOV BP,[SP] --old.bp\n");
			fprintf(target_file, "POP R%d --bp\n",j);
			freeReg();
			fprintf(target_file, "RET\n");
			puts("\t\t\t\t-ret");
			break;
		case nt_EXIT:
			puts("\t\t\t\t+exit");
			i=getReg();
			fprintf(target_file, "MOV R%d, \"Exit\"\n",i);
			fprintf(target_file, "PUSH R%d --\"exit\"\n",i);
			fprintf(target_file, "MOV R%d, \"\"\n",i);
			fprintf(target_file, "PUSH R%d  --\"\"\n",i);
			fprintf(target_file, "PUSH R%d  --\"\"\n",i);
			fprintf(target_file, "PUSH R%d  --\"\"\n",i);
			fprintf-(target_file, "PUSH R%d  --\"\"\n",i);
			freeReg();
			fprintf(target_file, "CALL 0\n");
			puts("\t\t\t\t-exit");
			break;
		case nt_INIT:
			puts("\t\t\t\t+init");
			i=getReg();
			init(i);
			j=getReg();
			if(t->down->Lentry==NULL){
				fprintf(target_file, "MOV R%d, %d\n",j,t->down->Gentry->binding);
				fprintf(target_file, "MOV R%d,R%d --ret\n",j,i);}
			else{fetch_local_loc_to(t->down,j);
				fprintf(target_file, "MOV [R%d],R%d --ret\n",j,i);}
			freeReg();
			freeReg();
			puts("\t\t\t\t-init");
			break;
		case nt_ALLOC:
			puts("\t\t\t\t+alloc");
			saveReg();
			i=getReg();
			if(t->down->Lentry==NULL){
				alloc_to(t->num,i);
				if(t->down->down==NULL){
					fprintf(target_file,"MOV [%d],R%d --Galloc\n",t->down->Gentry->binding+t->down->num,i);}
				else{
					j=codeGen(t->down->down);
					fprintf(target_file, "ADD R%d,%d --base+off\n",j,t->down->num);
					fprintf(target_file,"MOV [R%d],R%d --Galloc\n",j,i);
					freeReg();}}
			else{
				alloc_to(t->num,i);
				if(t->down->down==NULL){
					j=getReg();
					fetch_local_loc_to(t->down,j);}
				else{
					j=codeGen(t->down->down);
					fprintf(target_file, "ADD R%d,%d --base+off\n",j,t->down->num);}
				fprintf(target_file,"MOV [R%d],R%d --Lalloc\n",j,i);
				freeReg();}
			freeReg();
			restReg();
			puts("\t\t\t\t-alloc");
			break;
		case nt_FREE:
			puts("\t\t\t\t+free");
			saveReg();
			if(t->down->Lentry==NULL){
				i=codeGen(t->down);
				freee(i);
				freeReg();}
			else{
				i=getReg();
				fetch_local_loc_to(t->down,i);
				fprintf(target_file,"MOV R%d,[R%d]\n",i,i);
				freee(i);
				freeReg();}
			restReg();
			puts("\t\t\t\t-free");
			break;
		case nt_NEW:
			puts("\t\t\t\t+new");
			i=getReg();
			alloc_to(8,i);
			puts("\t\t\t\t-new");
			tabs--;
			return i;
			break;
		case nt_DELETE:
			puts("\t\t\t\t+delete");
			saveReg();
			i=codeGen(t->down);
			freee(i);
			freeReg();
			restReg();
			tabs--;
			puts("\t\t\t\t-delete");
			break;
	//--------------func
		case nt_FUNC://-------------------------------------------------------------------
			puts("\t\t\t\t+function");
			regtemp=reg;
			while(reg>-1){
				fprintf(target_file, "PUSH R%d --save.reg\n",reg);
				freeReg();}
			atemp=t->arglist;
			if(t->class!=NULL){//class
				k=getReg();
				i=getReg();
				j=getReg();
				if(t->left->nt!=nt_SELF){//not in class
					fprintf(target_file,"MOV R%d, %d --clasloc\n",i,t->left->Gentry->binding);
					fprintf(target_file,"MOV R%d,[R%d] --clasheap\n",j,i);
					fprintf(target_file,"PUSH R%d --clasheap\n",j);
					fprintf(target_file,"ADD R%d, 1 --vfunc\n",i);
					fprintf(target_file,"MOV R%d,[R%d]\n",j,i);
					fprintf(target_file,"MOV R%d,[R%d]\n",k,i);
					fprintf(target_file,"PUSH R%d --vfunc\n",j);}
				else{//in class		self.set(25,49);
					fprintf(target_file,"MOV R%d,BP --class\n",i);
					if(phead!=NULL){//phead
						fprintf(target_file,"ADD R%d,%d --clabind\n",i,(lhead->binding)-2);}
					else{//no params
						fprintf(target_file,"ADD R%d,%d --clabind\n",i,-4);}
					fprintf(target_file,"MOV R%d,[R%d] --clasheap\n",j,i);
					fprintf(target_file,"PUSH R%d --clasheap\n",j);
					fprintf(target_file,"ADD R%d, 1 --vfunc\n",i);
					fprintf(target_file,"MOV R%d,[R%d] --clasheap\n",j,i);
					fprintf(target_file,"MOV R%d,[R%d] --clasheap\n",k,i);
					fprintf(target_file,"PUSH R%d --clasheap\n",j);}
				freeReg();
				freeReg();}
			while(atemp){
				i=getReg();
				j=codeGen(atemp);
				fprintf(target_file, "MOV R%d,R%d --arg.val\n",i,j);
				freeReg();
				fprintf(target_file, "PUSH R%d --arg\n",i);
				freeReg();
				atemp=atemp->down;}
			i=getReg();
			fprintf(target_file, "MOV R%d,\"\"\n",i);
			fprintf(target_file, "PUSH R%d --for.ret\n",i);
			freeReg();
			if(t->class!=NULL){//obj.f0()
				fprintf(target_file, "ADD R%d, %d --vfunc\n",k, CMLookup(t->class,t->str)->funcposition);//-------------------------
				fprintf(target_file, "MOV R%d,[R%d] --vfunc\n",k,k);
				fprintf(target_file, "CALL R%d\n",k);
				freeReg();}
			else if(t->left!=NULL && t->left->class!=NULL){//self.o1.fact()//---------------------------------------------------------???????something striked
				fprintf(target_file, "CALL F%d  --'%s'\n",CMLookup(CFLookup(t->left->class,t->left->str)->ctype,t->str)->flabel,CMLookup(CFLookup(t->left->class,t->left->str)->ctype,t->str)->name);
			}
			else
				fprintf(target_file, "CALL F%d  --'%s'\n",t->Gentry->flabel,t->Gentry->name);
			fprintf(target_file, "POP R%d --result\n",regtemp+1);
			atemp=t->arglist;
			i=getReg();
			if(t->class!=NULL){
				fprintf(target_file, "POP R%d --clasargs\n",i==0?19:0);
				fprintf(target_file, "POP R%d --clasargs\n",i==0?19:0);}
			while(atemp){
				fprintf(target_file, "POP R%d --args\n",i==0?19:0);
				atemp=atemp->down;}
			freeReg();
			while(regtemp!=-1){
				regtemp--;
				i=getReg();
				fprintf(target_file, "POP R%d --old.regs\n",i);}
			i=getReg();
			puts("\t\t\t\t-function");
			tabs--;
			return i;
			break;
	//--------------extra
		case nt_BRKP:
			puts("\t\t\t\t+brkp");
			fprintf(target_file, "BRKP\n");
			puts("\t\t\t\t-brkp");
			break;
		default:
			printf("\tNO CODE-GEN MATCHING FOUND\ttype:'%d'\n",t->nt);
			exit(1);
			}
	tabs--;
	puts("\t\t\t\t-done");
	return -1;}
void funcGen(char *g){
	puts("\t\t\t\t+funcGen");
	if(GLookup(g)!=NULL){
		fprintf(target_file, "F%d: \n",GLookup(g)->flabel);
		fprintf(target_file, "PUSH BP --'%s'\n",GLookup(g)->name);
		fprintf(target_file, "MOV BP,SP --act.rec\n");
		struct Lsymbol *temp=lhead;
		int i;
		i=getReg();
		while(temp){
			if(temp->binding>0){
				fprintf(target_file, "MOV R%d,\"\" --blank\n",i);
				break;}
			temp=temp->next;}
		temp=lhead;
		while(temp){
			if(temp->binding>0)
				fprintf(target_file, "PUSH R%d --for.locals\n",i);
			temp=temp->next;}
		freeReg();}
	else{
		fprintf(target_file, "F%d: \n",CMLookup(class,g)->flabel);
		fprintf(target_file, "PUSH BP --'%s'\n",CMLookup(class,g)->name);
		fprintf(target_file, "MOV BP,SP --act.rec\n");
		struct Lsymbol *temp=lhead;
		int i;
		i=getReg();
		while(temp){
			if(temp->binding>0){
				fprintf(target_file, "MOV R%d,\"\" --blank\n",i);
				break;}
			temp=temp->next;}
		temp=lhead;
		while(temp){
			if(temp->binding>0)
				fprintf(target_file, "PUSH R%d --for.locals\n",i);
			temp=temp->next;}
		freeReg();}
	puts("\t\t\t\t-funcGen");
	;}
void Write(int reg,int ret){
	int t;
	puts("\t\t\t\t(write)");
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Write\"\n",t);
	fprintf(target_file, "PUSH R%d--\"write\"\n",t);
	fprintf(target_file, "MOV R%d, -2\n",t);
	fprintf(target_file, "PUSH R%d--(-2)\n",t);
	fprintf(target_file, "PUSH R%d--data\n",reg);
	fprintf(target_file, "MOV R%d,\"\"\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d--ret\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();
	puts("\t\t\t\t(write)");
	;}
void ReadReg(int reg_addr,int ret){
	int t;
	puts("\t\t\t\t(read)");
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Read\"\n",t);
	fprintf(target_file, "PUSH R%d\n",t);
	fprintf(target_file, "MOV R%d, -1\n",t);
	fprintf(target_file, "PUSH R%d--(-1)\n",t);
	fprintf(target_file, "MOV R%d, R%d\n",t,reg_addr);
	fprintf(target_file, "PUSH R%d--reg.addr\n",t);
	fprintf(target_file, "MOV R%d, \"\"\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d--ret\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();
	puts("\t\t\t\t(read)");
	;}
void Halt(){
	int t;
	puts("\t\t\t\t(halt)");
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Exit\"\n",t);
	fprintf(target_file, "PUSH R%d--\"exit\"\n",t);
	fprintf(target_file, "MOV R%d, \"\"\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	puts("\t\t\t\t(halt)");
	;}
void Brkp(){
	puts("\t\t\t\t");
	fprintf(target_file, "BRKP\n");
	puts("\t\t\t\t");
	;}
void Debug(int i){
	puts("\t\t\t\t");
	fprintf(target_file,"BRKP\n");
	fprintf(target_file,"BRKP--'%d'\n",i);
	puts("\t\t\t\t");
	;}
void init(int ret){
	int t;
	puts("\t\t\t\t(ret)");
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Heapset\"\n",t);
	fprintf(target_file, "PUSH R%d --\"heapset\"\n",t);
	fprintf(target_file, "MOV R%d, \"\" --blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--ret\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d--ret\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();
	puts("\t\t\t\t(ret)");
	;}
void alloc_to(int size,int i){
	int t;
	puts("\t\t\t\t(alloc)");
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Alloc\"\n",t);
	fprintf(target_file, "PUSH R%d --\"alloc\"\n",t);
	fprintf(target_file, "MOV R%d,%d\n",t,size);
	fprintf(target_file, "PUSH R%d--size\n",t);
	fprintf(target_file, "MOV R%d, \"\" --blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--ret\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d--ret\n",i);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();
	puts("\t\t\t\t(alloc)");
	;}
void freee(int reg_addr){
	int t,ret;
	puts("\t\t\t\t(free)");
	t=getReg();
	fprintf(target_file, "MOV R%d, \"Free\"\n",t);
	fprintf(target_file, "PUSH R%d --\"free\"\n",t);
	fprintf(target_file, "PUSH R%d--pointer\n",reg_addr);
	fprintf(target_file, "MOV R%d, \"\" --blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--blank\n",t);
	fprintf(target_file, "PUSH R%d--ret\n",t);
	freeReg();
	fprintf(target_file, "CALL 0\n");
	fprintf(target_file, "POP R%d--retfree\n",ret);
	t=getReg();
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	fprintf(target_file, "POP R%d--disc\n",t);
	freeReg();
	puts("\t\t\t\t(free)");
	;}
void fetch_local_loc_to(struct tnode *t,int i){
	puts("\t\t\t\t");
	fprintf(target_file, "MOV R%d,BP --BP+?\n",i);
	fprintf(target_file, "ADD R%d,%d --L.loc\n",i,t->Lentry->binding);
	puts("\t\t\t\t");
	;}
void saveReg(){
	tempreg=reg;
	#ifdef BUG
		if(reg>-1){
			puts("\t\t\t\tsaving regs");}
	#endif
	while(reg>-1){
		fprintf(target_file, "PUSH R%d --save.reg\n",reg);
		freeReg();}}
void restReg(){
	int t;
	#ifdef BUG
		if(reg>-1){
			puts("\t\t\t\trestoring regs");}
	#endif
	while(tempreg!=-1){
		tempreg--;
		t=getReg();
		fprintf(target_file, "POP R%d --old.regs\n",t);}}
//
