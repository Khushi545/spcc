#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[10][20];
int n;

void FIRST(char *res, char c) {
    for (int i = 0; i < n; i++) {
        if (prod[i][0] == c) {
            char next = prod[i][2];

            if (!isupper(next)) {
                if (!strchr(res, next))
                    strncat(res, &next, 1);
            } else {
                FIRST(res, next);
            }
        }
    }
}

int main() {
    int i, j;
    char done[10] = "";

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (E=TR):\n");
    for (i = 0; i < n; i++)
        scanf("%s", prod[i]);

    printf("\nFIRST sets:\n");

    for (i = 0; i < n; i++) {
        char nt = prod[i][0];

        if (strchr(done, nt)) continue;  // already done

        char res[20] = "";
        FIRST(res, nt);

        printf("FIRST(%c) = { ", nt);
        for (j = 0; j < strlen(res); j++)
            printf("%c ", res[j]);
        printf("}\n");

        strncat(done, &nt, 1);
    }

    return 0;
}