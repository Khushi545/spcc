#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct symtab {
    char sym[10];
    int addr;
} s[10];

int main() {

    // Hardcoded input
    char label[][10]  = {"**","LOOP","**","X","Y","**"};
    char opcode[][10] = {"START","MOVER","ADD","DS","DC","END"};
    char operand[][10]= {"100","AREG,X","BREG,Y","2","5","**"};

    int locctr, start, i = 0, n = 6;

    printf("%-6s%-10s%-10s%-20s\n", "ADDR", "LABEL", "OPCODE", "OPERAND");

    for (int j = 0; j < n; j++) {

        if (strcmp(opcode[j], "START") == 0) {
            start = atoi(operand[j]);
            locctr = start;
            printf("%-6d%-10s%-10s%-20s\n", locctr, label[j], opcode[j], operand[j]);
            continue;
        }

        printf("%-6d%-10s%-10s%-20s\n", locctr, label[j], opcode[j], operand[j]);

        // Store symbol
        if (strcmp(label[j], "**") != 0) {
            strcpy(s[i].sym, label[j]);
            s[i].addr = locctr;
            i++;
        }

        // Update LC
        if (strcmp(opcode[j], "DS") == 0)
            locctr += atoi(operand[j]);
        else if (strcmp(opcode[j], "DC") == 0)
            locctr += 1;
        else if (strcmp(opcode[j], "END") == 0)
            break;
        else
            locctr += 1;
    }

    printf("\nSYMBOL TABLE:\n");
    for (int j = 0; j < i; j++)
        printf("%s\t%d\n", s[j].sym, s[j].addr);

    printf("\nPROGRAM LENGTH = %d\n", locctr - start);

    return 0;
}