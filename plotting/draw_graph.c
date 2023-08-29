#include "plot_polish_not.h"

void show_graph(struct queue* postfix) {
    char** matrix = NULL;
    create_matrix(&matrix, postfix);
    draw_matrix(matrix);
    free(matrix);
}

void create_matrix(char*** matrix, struct queue* postfix) {
    *matrix = malloc(WIDTH * HEIGHT * sizeof(char) + HEIGHT * sizeof(char*));
    char* start = (char*)(*matrix + HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        (*matrix)[i] = start + i * WIDTH;
    }
    set_empty_matr(matrix);
    for (int i = 0; i < WIDTH; i++) {
        double x = i * X_CHANGE;
        double y = solve_exp(postfix, x);
        int j = round(y / Y_CHANGE + 12);
        if (y <= 1 && y >= -1 && j < HEIGHT && j >= 0) {
            (*matrix)[j][i] = '*';
        }
    }
}

void set_empty_matr(char*** matrix) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            (*matrix)[i][j] = '.';
        }
    }
}

void draw_matrix(char** matrix) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", matrix[i][j]);
        }
        if (i != HEIGHT - 1) {
            printf("\n");
        }
    }
}