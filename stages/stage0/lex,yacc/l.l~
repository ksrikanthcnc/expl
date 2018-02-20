%{
    #include <stdio.h> 
	  #include "y.tab.h"
%}

%%

[a-z]+	{
          yylval = yytext;
          return DIGIT;
        }
"+"	  return *yytext;
"-"	  return *yytext;
[()]	  return *yytext;
[\n]      return NEWLINE;

%%

yywrap()
{
	return 1;
}
