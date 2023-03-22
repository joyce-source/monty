#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

#define STACK_SIZE 1024

int stack[STACK_SIZE];
int sp = -1; // stack pointer

void push(int value, int line_number) {
    if (sp == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    sp++;
    stack[sp] = value;
}

void pall() {
    int i;
    for (i = sp; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main(int argc, char *argv[]) {
    char line[1024];
    int line_number = 0;
    while (fgets(line, sizeof(line), stdin)) {
        line_number++;
        char *opcode = strtok(line, " \t\n");
        if (opcode == NULL || strncmp(opcode, "#", 1) == 0) {
            // empty line or comment
            continue;
        }
        if (strncmp(opcode, "push", 4) == 0) {
            // push opcode
            char *arg = strtok(NULL, " \t\n");
            if (arg == NULL || atoi(arg) == 0) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            int value = atoi(arg);
            push(value, line_number);
        } else if (strncmp(opcode, "pall", 4) == 0) {
            // pall opcode
            pall();
        } else {
            fprintf(stderr, "L%d: unknown opcode %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
}

