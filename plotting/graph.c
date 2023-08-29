#include "plot_polish_not.h"

int main() {
    char exp[MAX_LEN];
    struct queue* lexems = queue_init();
    int f = to_lexems(lexems, exp);
    if (f) {
        struct queue* postfix = to_postfix(lexems, f);
        show_graph(postfix);
        queue_destroy(postfix);
    } else {
        printf("n/a");
    }
    queue_destroy(lexems);
    return 0;
}