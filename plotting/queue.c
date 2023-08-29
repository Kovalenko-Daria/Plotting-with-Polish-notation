#include "queue.h"

struct queue* queue_init() {
    struct queue* new_queue = malloc(sizeof(struct queue));
    new_queue->begin = 0;
    new_queue->end = -1;
    new_queue->data = malloc(50 * sizeof(char*) + 50 * 8 * sizeof(char));
    char* start = (char*)(new_queue->data + 50);
    for (int i = 0; i < 50; i++) {
        new_queue->data[i] = start + i * 8;
    }
    return new_queue;
}

void queue_push(struct queue* queue, char* elem) {
    queue->end++;
    strcpy(queue->data[queue->end], elem);
}

void queue_destroy(struct queue* queue) {
    free(queue->data);
    free(queue);
}
