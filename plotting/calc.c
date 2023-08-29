#include "plot_polish_not.h"

double solve_exp(struct queue* postfix, double x) {
    double* znach = malloc(15 * sizeof(double));
    int beg = postfix->begin;
    int end = postfix->end;
    int count = 0;
    while (postfix->begin != postfix->end + 1) {
        while ((is_digit(postfix->data[postfix->begin][0]) || postfix->data[postfix->begin][0] == 'x') &&
               postfix->begin != postfix->end + 1) {
            if (postfix->data[postfix->begin][0] == 'x') {
                znach[count] = x;
            } else {
                znach[count] = make_num(postfix->data[postfix->begin]);
            }
            count++;
            postfix->begin++;
        }
        if (postfix->begin != postfix->end + 1 && kind_oper(postfix->data[postfix->begin])) {
            count--;
            znach[count] = un_num_oper(znach[count], postfix->data[postfix->begin]);
            count++;
            postfix->begin++;
        } else if (postfix->begin != postfix->end + 1) {
            count -= 2;
            znach[count] = bi_num_oper(znach[count], znach[count + 1], postfix->data[postfix->begin]);
            count++;
            postfix->begin++;
        }
    }
    double ans = znach[0];
    free(znach);
    postfix->begin = beg;
    postfix->end = end;
    return ans;
}

double make_num(char* num) {
    int len = (int)strlen(num);
    int k = 1;
    double sum = 0;
    for (int i = len - 1; i >= 0; i--) {
        sum = sum + (double)(num[i] - '0') * k;
        k *= 10;
    }
    return sum;
}

int kind_oper(char* oper) {
    return (strcmp(oper, "+") && strcmp(oper, "-") && strcmp(oper, "*") && strcmp(oper, "/"));
}

double bi_num_oper(double first, double second, char* oper) {
    double ans = 0;
    if (!strcmp(oper, "+")) {
        ans = first + second;
    } else if (!strcmp(oper, "-")) {
        ans = first - second;
    } else if (!strcmp(oper, "*")) {
        ans = first * second;
    } else {
        ans = first / second;
    }
    return ans;
}

double un_num_oper(double first, char* oper) {
    double ans = 0;
    if (!strcmp(oper, "~")) {
        ans = -1 * first;
    } else if (!strcmp(oper, "sin")) {
        ans = sin(first);
    } else if (!strcmp(oper, "cos")) {
        ans = cos(first);
    } else if (!strcmp(oper, "tan")) {
        ans = tan(first);
    } else if (!strcmp(oper, "ctg")) {
        ans = 1.0 / tan(first);
    } else if (!strcmp(oper, "sqrt")) {
        ans = sqrt(first);
    } else {
        ans = log(first);
    }
    return ans;
}