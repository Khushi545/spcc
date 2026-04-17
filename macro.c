#include <stdio.h>
#include <string.h>

struct {
    char name[10];
    int mdt_index;
} mnt[10];

char mdt[50][50];

int main() {

    // Hardcoded input
    char code[][20] = {
        "MACRO",
        "INCR",
        "A 1",
        "MEND",
        "START",
        "INCR",
        "END"
    };

    int mntc = 0, mdtc = 0;

    for (int i = 0; i < 7; i++) {

        // Macro Definition
        if (!strcmp(code[i], "MACRO")) {
            i++;
            strcpy(mnt[mntc].name, code[i]);
            mnt[mntc++].mdt_index = mdtc;

            i++;
            while (strcmp(code[i], "MEND")) {
                strcpy(mdt[mdtc++], code[i]);
                i++;
            }
            strcpy(mdt[mdtc++], "MEND");
        }

        // Macro Call (Expansion)
        else if (!strcmp(code[i], "INCR")) {
            for (int j = mnt[0].mdt_index; strcmp(mdt[j], "MEND"); j++)
                printf("Expanded: %s\n", mdt[j]);
        }
    }

    // MNT
    printf("\nMNT:\nName\tMDT Index\n");
    for (int i = 0; i < mntc; i++)
        printf("%s\t%d\n", mnt[i].name, mnt[i].mdt_index);

    // MDT
    printf("\nMDT:\n");
    for (int i = 0; i < mdtc; i++)
        printf("%d\t%s\n", i, mdt[i]);

    return 0;
}