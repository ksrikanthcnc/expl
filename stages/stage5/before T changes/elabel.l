%{
	#include <stdio.h>
	#include <stdlib.h>
	#define debug  //printf("line:%d\tfunc:%s\t\n",__LINE__,__func__);

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

[L][0-9]+":"	{debug
				if(flag==0){
					struct label* temp;
					temp=(struct label*)malloc(sizeof(struct label));
					lin--;
					new(yytext,lin,present,temp);
					present=present->next;
					debug}
				else{
					//puts(yytext);
					//puts("---");
					;
					}
				}

[L][0-9]+[^:]	{debug
				if(flag==1){
					int line;
					line=search(yytext);
//					printf("%d",line);
					fprintf(filey,"%d\n",line);
					}
				else 
					lin++;
				}

[F][0-9]+":"	{debug
				if(flag==0){
					struct label* temp;
					temp=(struct label*)malloc(sizeof(struct label));
					lin--;
					new(yytext,lin,present,temp);
					present=present->next;
					debug}
				else{
					//puts(yytext);
					//puts("---");
					;
					}
				}

[F][0-9]+[^:]	{debug
				if(flag==1){
					int line;
					line=search(yytext);
//					printf("%d",line);
					fprintf(filey,"%d\n",line);
					}
				else 
					lin++;
				}

[\n]			{lin++;	if(flag==1)fprintf(filey,"%s",yytext);}

. 				{if(flag==1) fprintf(filey,"%s",yytext);}
%%

int yywrap(void) {
	if(flag==0){
		debug
		flag=1;
		yyin=fopen("intermediate.xsm","r");
		return 0;
	}
	else
		return 1;}

int search(char *l){
	debug
	struct label* temp;
	temp=head;
	while(temp){
		if(temp->l==NULL){
			printf("Function number (starts from 0) :%s\tnot defined, but called :(\n",l);
			exit(1);}
		if(strcmp(concat(temp->l,"\n"),l)==0)
			return temp->line;
		else
			temp=temp->next;
	}}

void new(char* l, int line, struct label* present,struct label* temp){
	debug
	char *str;
	str=malloc(sizeof(l)-1);
	strncpy(str,l,strlen(l)-1);
	present->l=str;
	present->line=2056+2*(lin-8);
	present->next=temp;
	temp->next=NULL;}

char* concat(const char *s1, const char *s2){
	debug
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;}

int main(){
	debug

	filex=fopen("intermediate.xsm","r");
	filey=fopen("output.xsm","w+");

	yyin=fopen("intermediate.xsm","r");

	head=(struct label*)malloc(sizeof(struct label));
	present=head;

	yylex();

	return 0;
}
