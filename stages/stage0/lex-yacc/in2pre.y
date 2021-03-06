%{
      #include <stdio.h>
      #define YYSTYPE char*
      yydebug=0;
      char* concat(const char *s1, const char *s2);
      #define concaat(a,b) concat(concat(a," "),concat(b," "))
%}

%token CHAR NEWLINE
%left '+' '-'
%left '*' '/'
 
%%

start : expr NEWLINE  {printf("\n%s",$1);
                        printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr:  expr '+' expr        {$$ = concat("+ ",concaat($1,$3));}
  | expr '-' expr        {$$ = concat("- ",concaat($1,$3));}
  | expr '*' expr        {$$ = concat("* ",concaat($1,$3));}
  | expr '/' expr        {$$ = concat("/ ",concaat($1,$3));}
  | '(' expr ')'		{$$=$2;}
  | CHAR             {$$=$1;}
  ;

%%

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void yyerror(char const *s)
{
    printf("yyerror  %s\n",s);
    return ;
}
int main()
{
  yyparse();
  return 1;
}
