#include <stdio.h>
#include <ctype.h>

int main() {
    char str[200];
    int chars=0, words=0, lines=0, spaces=0, tabs=0, nums=0, sent=0;
    int inword=0;

    printf("Enter text:\n");
    fgets(str, sizeof(str), stdin);

    lines = 1; // since single input line

    for (int i=0; str[i]!='\0'; i++) {
        chars++;

        if (str[i]==' ') spaces++;
        if (str[i]=='\t') tabs++;
        if (str[i]=='.'||str[i]=='!'||str[i]=='?') sent++;

        if (isalnum(str[i])) {
            if (!inword) { words++; inword=1; }
        } else inword=0;

        if (isdigit(str[i])) {
            nums++;
            while (isdigit(str[i+1])) i++;
        }
    }

    printf("\nCharacters: %d", chars);
    printf("\nWords: %d", words);
    printf("\nLines: %d", lines);
    printf("\nSentences: %d", sent);
    printf("\nSpaces: %d", spaces);
    printf("\nTabs: %d", tabs);
    printf("\nNumbers: %d\n", nums);

    return 0;
}