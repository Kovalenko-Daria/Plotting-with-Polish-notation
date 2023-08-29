#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <string.h>

struct queue {
    int begin;
    int end;
    char** data;
};

struct queue* queue_init();
void queue_push(struct queue* queue, char* elem);
void queue_destroy(struct queue* queue);
#endif