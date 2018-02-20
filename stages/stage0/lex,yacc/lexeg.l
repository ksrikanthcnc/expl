%{
	#include<stdio.h>
	char *file1;
%}

%%

[0-9]+ 	printf("number");

%%

int yywrap()
{
  	FILE *newfile_pointer;
  	char *file2="file2";
  	newfile_pointer = fopen("file2","r");
  	if(strcmp(file1,file2)!=0)
  	{
  		file1=file2;  
//  		yyin = newfile_pointer;
			yyin=stdin;
    		return 0;
  	}
  	else
  		return 1;
}

int main()
{
	file1="file1";
//  	yyin = fopen("file1","r");
  	yylex();
  	return 1;
}
