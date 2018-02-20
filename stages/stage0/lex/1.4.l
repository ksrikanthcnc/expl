%option noyywrap

%{
  #include<stdlib.h>
  #include<stdio.h>
  int i;
%}

star [^*]
slash	[^/]

%%

"/*"([^*/]|(\*[^/])|(\/))*"*/"	{//printf("%d\n",i++);
						puts(yytext);
						puts("---------------------------------");
						//system("sleep 1");
						;}
"//".* {puts(yytext);
	puts("-------------");}
. 
"\n" 

%%

int main(){
	i=0;
//	yyin=fopen("file1","r");
	yylex();
	return 1;
}


