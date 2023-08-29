#ifndef PLOT_POLISH_NOT_H
#define PLOT_POLISH_NOT_H

#include <stdio.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "queue.h"
#include "stack.h"

#define WIDTH 80
#define HEIGHT 25
#define X_CHANGE (4 * M_PI) / 79
#define Y_CHANGE 0.08333
#define MAX_LEN 100

void read_expression(char* str);
struct queue* to_postfix(struct queue* exp, int n);
void output_stack(struct stack* stack);
int is_digit(char c);
int is_oper(char c);
int is_func(char c);
void get_number(char** exp, struct queue* lexems);
int operation_priority(char* c);
void get_func(char** exp, struct queue* oper);
int to_lexems(struct queue* lexems, char* exp);

void show_graph(struct queue* postfix);

void create_matrix(char*** matrix, struct queue* postfix);

void draw_matrix(char** matrix);

void set_empty_matr(char*** matrix);

double solve_exp(struct queue* postfix, double x);

double make_num(char* num);

int kind_oper(char* oper);

double bi_num_oper(double first, double second, char* oper);

double un_num_oper(double first, char* oper);

#endif