#define MAIN_H
#ifndef MAIN_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
}
instruction_t;
typedef struct stack_s
{
    int data;
    struct stack_s *next;
}
stack_t;
int main(int argc, char *argv[]);
void push(int value, int line_number);
int stack[STACK_SIZE];
void pall();
void push(int value, int line_number);
void push(int line_number);
int main(int argc, char *argv[]);
void pint(stack_t **stack, unsigned int line_number);
#endif
