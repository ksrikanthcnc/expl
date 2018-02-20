%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#include "labels.c"
	FILE *yyin,*output;
	int pass,num;
%}


%%

[L]([0-9])+			{if(pass==2) {num=findline(yytext+1);fprintf(output,"%d",entry[num].adrs);}}

[L]([0-9])+[' ']*[:][\n]  {if (pass==1){	
							int num=findline(yytext+1);
							entry[num].adrs=(linecnt*2)+2048-8;
							//printf("%s line=%d %d %d\n",yytext,linecnt,num,entry[num].adrs );
							}
						}
[\n]				{linecnt++; if(pass==2) fprintf(output,"\n");}
(.)					{if(pass==2) fprintf(output,"%s",yytext);}







%%


int yywrap()
{
	if(pass==1)
	{
		yyin=fopen("intermediate.xsm","r");
		pass=2;
		return 0;
	}
	return 1;
}

int main()
{
	FILE *fp=fopen("intermediate.xsm","r");
	if(fp)
		yyin=fp;
	else
		printf("Error opening input file\n");
	output=fopen("output.xsm","w");
	pass=1;
	linecnt=0;
	yylex();
	return 1;
}