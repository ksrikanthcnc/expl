%{
      #include <stdio.h>
      #define YYSTYPE char*
      yydebug=0;
%}

%token DIGIT NEWLINE
 
%%

start : expr NEWLINE  { 
                        printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr:  expr '+' expr        {printf("+ ");}
  | expr '-' expr     {printf("- ");}
  | '(' expr ')'
  | DIGIT             {printf("%s ",$1);}
  ;

%%

void yyerror(char const *s) 
{ 
    printf("\nyyerror  %s\n",s); 
    return ;
} 
int main()
{
  yyparse();
  return 1;
}
  
