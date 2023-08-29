#include "stack.h"

struct stack* stack_init() {
    struct stack* new_stack = malloc(sizeof(struct stack));
    new_stack->count = 0;
    new_stack->data = malloc(50 * sizeof(char*) + 50 * 8 * sizeof(char));
    char* start = (char*)(new_stack->data + 50);
    for (int i = 0; i < 50; i++) {
        new_stack->data[i] = start + i * 8;
    }
    return new_stack;
}

void stack_push(struct stack* stack, char* elem) {
    strcpy(stack->data[stack->count], elem);
    stack->count++;
}

char* stack_pop(struct stack* stack) {
    char* ans = NULL;
    if (stack->count != 0) {
        ans = stack->data[stack->count - 1];
        stack->count--;
    }
    return ans;
}

void stack_destroy(struct stack* stack) {
    free(stack->data);
    free(stack);
}