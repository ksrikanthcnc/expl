%{
      #include <stdio.h>
      #define YYSTYPE char*
      yydebug=0;
%}

%token DIGIT CHAR
 
%%

start : CHAR next  { 
						puts("Valid variable");
                        exit(1);
                      }
  ;

next:	CHAR next
	|	DIGIT next
	|	'\n'
	;

%%

 yyerror() 
{ 
	puts("Invalid variable");
    return ;
} 

yylex(){
	char c;
	c=getchar();
	if(isalpha(c))
		return CHAR;
	else if(isdigit(c))
		return DIGIT;
	else
		return c;
}

int main()
{
  yyparse();
  return 1;
}
  
