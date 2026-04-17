%{
#include <stdio.h>

int chars=0, words=0, lines=0, spaces=0, tabs=0, nums=0, sent=0;
%}

%%
[0-9]+        { nums++; chars += yyleng; }
\n            { lines++; chars++; }
[ ]           { spaces++; chars++; }
\t            { tabs++; chars++; }
[.!?]         { sent++; chars++; }
[a-zA-Z]+     { words++; chars += yyleng; }
.             { chars++; }
%%

int main() {
    printf("Enter text (Ctrl+D to end):\n");
    yylex();

    printf("\nCharacters: %d", chars);
    printf("\nWords: %d", words);
    printf("\nLines: %d", lines);
    printf("\nSentences: %d", sent);
    printf("\nSpaces: %d", spaces);
    printf("\nTabs: %d", tabs);
    printf("\nNumbers: %d\n", nums);

    return 0;
}

int yywrap() { return 1; }

//Save your LEX code as: filename.l

//How to Compile & Run 
// sudo apt update
// sudo apt install flex bison gcc

// flex filename.l
// gcc lex.yy.c -o output -lfl
// ./output

// Enter text (Ctrl+D to end):
// Hello world.
// This is 2026.
// ^D








