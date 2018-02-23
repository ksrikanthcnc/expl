%option noyywrap
%{
    #include <stdio.h> 
    int lines,words,chars;
%}

%%

[a-zA-Z0-9]+ {printf("%s",yytext);words++;chars=chars+yyleng;}
\n {printf("------%d%s%d.",words,yytext,lines);lines++;}


%%

int main(){
	lines=words=chars=0;
	yyin=fopen("file1","r");
	yylex();
	printf("\nlines=%d\nwords=%d\nchars=%d\n",lines,words,chars);
	return 1;
}
