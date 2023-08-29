#include "plot_polish_not.h"

int to_lexems(struct queue* lexems, char* exp) {
    int ret = 0;
    read_expression(exp);
    while (*exp != '\0') {
        char c = *exp;
        if (is_digit(c)) {
            get_number(&exp, lexems);
            ret++;
        } else if (c == 'x' || c == '(' || c == ')' || is_oper(c)) {
            char ch[2] = {c, '\0'};
            queue_push(lexems, ch);
            ret++;
            exp++;
        } else if (is_func(c)) {
            get_func(&exp, lexems);
            ret++;
        } else {
            ret = 0;
            break;
        }
    }
    return ret;
}

void read_expression(char* str) {
    printf("Enter an expression: ");
    while ((*str++ = getchar()) != '\n')
        ;
    *(str - 1) = '\0';
}

struct queue* to_postfix(struct queue* lexems, int len) {
    struct queue* output = queue_init();
    struct stack* oper = stack_init();
    for (int i = 0; i < len; i++) {
        char c = lexems->data[i][0];
        if (is_digit(c) || c == 'x') {
            queue_push(output, lexems->data[i]);
        } else if (is_func(c)) {
            stack_push(oper, lexems->data[i]);
        } else if (c == '(') {
            stack_push(oper, "(");
        } else if (c == ')') {
            while (oper->count > 0 && strcmp(oper->data[oper->count - 1], "(") != 0) {
                queue_push(output, stack_pop(oper));
            }
            stack_pop(oper);
        } else if (is_oper(c)) {
            if (c == '-' && (output->end == -1 || strcmp(lexems->data[i - 1], "(") == 0)) {
                lexems->data[i][0] = '~';
            }
            while (oper->count > 0 && strcmp(oper->data[oper->count - 1], "(") != 0 &&
                   (operation_priority(oper->data[oper->count - 1]) >= operation_priority(lexems->data[i]))) {
                queue_push(output, stack_pop(oper));
            }
            stack_push(oper, lexems->data[i]);
        }
    }
    while (oper->count > 0) {
        queue_push(output, stack_pop(oper));
    }
    stack_destroy(oper);
    return output;
}

int is_digit(char c) { return (c <= '9' && c >= '0'); }

int is_oper(char c) { return (c == '/' || c == '*' || c == '+' || c == '-'); }

int is_func(char c) { return (c <= 'z' && c >= 'a'); }

void get_number(char** exp, struct queue* lexems) {
    char* num = malloc(sizeof(char) * 8);
    int count1 = 0;
    while (is_digit(**exp)) {
        num[count1] = **exp;
        count1++;
        (*exp)++;
    }
    num[count1] = '\0';
    queue_push(lexems, num);
    free(num);
}

void get_func(char** exp, struct queue* lexems) {
    char* func = malloc(sizeof(char) * 8);
    int count1 = 0;
    while (is_func(**exp)) {
        func[count1] = **exp;
        count1++;
        (*exp)++;
    }
    func[count1] = '\0';
    queue_push(lexems, func);
    free(func);
}

int operation_priority(char* c) {
    int ret;
    if (!strcmp(c, "-") || !strcmp(c, "+")) {
        ret = 1;
    } else if (!strcmp(c, "*") || !strcmp(c, "/")) {
        ret = 2;
    } else {
        ret = 3;
    }
    return ret;
}
