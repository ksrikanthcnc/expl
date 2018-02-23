%{
	#include <stdio.h>
	#include <stdlib.h>
	struct label{
		char *l;
		int line;
		struct label* next;
	}*present,*head;
	int lin=1;
	int flag=0;
	FILE* filex;
	FILE* filey;
	char* a,b;
	void new(char* l, int line, struct label* present,struct label* temp);
	int search(char*);
	char* concat(const char *s1, const char *s2);
%}

%%

[L][1-9]+":"	{
	printf("line:%d\tfunc:%s\t\n",__LINE__,__func__);
				if(flag==0){
					struct label* temp;
					temp=(struct label*)malloc(sizeof(struct label));
					lin--;
					new(yytext,lin,present,temp);
					present=present->next;
				printf("line:%d\tfunc:%s\t\n",__LINE__,__func__);
		}
				else{
					//puts(yytext);
					//puts("---");
}
				}

[L][1-9]+[^:]	{
	printf("line:%d\tfunc:%s\t\n",__LINE__,__func__);
				if(flag==1){
					int line;
					line=search(yytext);
//					printf("%d",line);
					fprintf(filey,"%d\n",line);
					}
				else{
					lin++;
				}
				}

[\n]	{lin++;	if(flag==1)fprintf(filey,"%s",yytext);}

. {	if(flag==1)fprintf(filey,"%s",yytext);}
%%

int yywrap(void) {
	if(flag==0){
	printf("line:%d\tfunc:%s\t\n",__LINE__,__func__);
		flag=1;
		yyin=fopen("intermediate.xsm","r");
		return 0;
	}
	else
		return 1;
}

int search(char *l){
	printf("line:%d\tfunc:%s\t\n",__LINE__,__func__);
	struct label* temp;
	temp=head;
	while(temp){
		if(strcmp(concat(temp->l,"\n"),l)==0)
			return temp->line;
		else
			temp=temp->next;
	}
}

void new(char* l, int line, struct label* present,struct label* temp){
	printf("line:%d\tfunc:%s\t\n",__LINE__,__func__);
	char *str;
	str=malloc(sizeof(l)-1);
	strncpy(str,l,strlen(l)-1);
	present->l=str;
	present->line=2056+2*(lin-8);
//	printf("%d\n",lin);
	present->next=temp;
	temp->next=NULL;
}

char* concat(const char *s1, const char *s2)
{
	printf("line:%d\tfunc:%s\t\n",__LINE__,__func__);
    char *result = malloc(strlen(s1)+strlen(s2)+1);//+1 for the null-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main(){
	printf("line:%d\tfunc:%s\t\n",__LINE__,__func__);
	filex=fopen("intermediate.xsm","r");
	filey=fopen("output.xsm","w+");
	yyin=fopen("intermediate.xsm","r");
	head=(struct label*)malloc(sizeof(struct label));
	present=head;
	yylex();

/*
	struct label* a;
	a=head;
	while(a){
		printf("%d:%s\n",a->line,a->l);
		a=a->next;
	}
*/
	return 0;
}
