%{
      #include <stdio.h>
//      #define YYSTYPE char
      #define YYSTYPE char*
      int tabs,t;
%}

%token DIGIT NEWLINE CHAR
 
%%

start : expr NEWLINE  {
                        printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr:  expr '+' expr        {printf("+ ");}
  | expr '-' expr     {printf("- ");}
  | expr '*' expr     {printf("* ");}
  | expr '/' expr     {printf("/ ");}
 | '(' expr ')'		//{tabs++;t=tabs;while(t){t--;printf("\t");}}
/*  | DIGIT             {printf("%d ",$1);}*/
/*  | CHAR             {printf("%c ",$1);}*/
  | CHAR             {printf("%s ",$1);}
  ;

%%

void yyerror(char const *s)
{
    printf("yyerror  %s\n",s);
    return ;
}
int main()
{
	tabs=0;
  yyparse();
  return 1;
}
