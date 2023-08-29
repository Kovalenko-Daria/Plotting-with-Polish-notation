#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <string.h>

struct stack {
    int count;
    char** data;
};

struct stack* stack_init();

void stack_push(struct stack* stack, char* elem);

char* stack_pop(struct stack* stack);
void stack_destroy(struct stack* stack);

#endif