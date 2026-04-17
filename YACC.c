%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(char *s);
int yylex();
%}

%token NUM

%%
E : E '+' T
  | E '-' T
  | T
  ;

T : T '*' F
  | T '/' F
  | F
  ;

F : '(' E ')'
  | NUM
  ;

%%

int main() {
    printf("Enter expression:\n");
    if(yyparse()==0)
        printf("Valid Expression\n");
    return 0;
}

void yyerror(char *s) {
    printf("Invalid Expression\n");
}

int yywrap() {
    return 1;
}

// save as parser.y

%{
#include "y.tab.h"
%}

%%
[0-9]+     { return NUM; }
[+\-*/()]  { return yytext[0]; }
[ \t\n]    ;
.          { return yytext[0]; }
%%

// save as lexer.l

// sudo apt update
// sudo apt install flex bison gcc

// HOW TO COMPILE AND RUN:

// bison -d parser.y
// flex lexer.l
// gcc y.tab.c lex.yy.c -o output -lfl
// ./output

// NOTE :
// If you get:fatal error: y.tab.h: No such file Then change your LEX file line:
// #include "y.tab.h" to: #include "parser.tab.h"