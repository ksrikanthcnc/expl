%{
	#include <stdio.h>
	#include <stdlib.h>
	struct label{
		char *l;
		int line;
		struct label* next;
	}*head;
	int lin=1;
	int flag=0;
	FILE* filex;
	FILE* filey;
	void new(char* l, int line);
	int search(char* l);
	char* concat(const char *s1, const char *s2);
%}
%%
[L][0-9]+": "	{if(flag==0){
					lin--;
					new(yytext,lin);}}
[L][0-9]+[^:]	{if(flag==1){
					int line;
					line=search(yytext);
					fprintf(filey,"%d",line);}}
[F][0-9]+": "	{if(flag==0){
					lin--;
					new(yytext,lin);}}
[F][0-9]+[^:]	{if(flag==1){
					int line;
					line=search(yytext);
					fprintf(filey,"%d",line);}}
[\n]			{lin++;	if(flag==1) fprintf(filey,"%s",yytext); else ;}
. 				{if(flag==1) fprintf(filey,"%s",yytext);}
%%
int yywrap(void) {
	if(flag==0){
		flag=1;
		yyin=fopen("intermediate.xsm","r");
		return 0;}
	else
		return 1;}
void new(char* l, int line){
	char *str;
	str=malloc(sizeof(l)-2);
	strncpy(str,l,strlen(l)-2);
	struct label *neww=malloc(sizeof(struct label));
	neww->l=str;
	neww->line=2056+2*(lin-8);
	neww->next=head;
	head=neww;}
int search(char *l){
	puts("");
	struct label* temp;
	temp=head;
	while(temp){
		if(strcmp(concat(temp->l," "),l)==0)
			return temp->line;
		else
			temp=temp->next;}
	if(temp==NULL){
		printf("Function number (starts from 0) :'%s'\tnot defined, but called :(\n",l);
		exit(1);}}
char* concat(const char *s1, const char *s2){
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;}
int main(){
	filex=fopen("intermediate.xsm","r");
	filey=fopen("output.xsm","w+");
	yyin=fopen("intermediate.xsm","r");
	head=NULL;
	yylex();
	return 0;}
//
