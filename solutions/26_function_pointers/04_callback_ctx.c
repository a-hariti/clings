#include <stddef.h>
#include "clings.h"

typedef void (*ForEachFn)(int value, void *ctx);

void for_each(int *values, size_t len, ForEachFn fn, void *ctx) {
    for (size_t i = 0; i < len; i++) {
        fn(values[i], ctx);
    }
}

typedef struct {
    int sum;
} SumCtx;

void add_to_sum(int value, void *ctx) {
    SumCtx *s = (SumCtx *)ctx;
    s->sum += value;
}

int main(void) {
    int values[] = {1, 2, 3, 4};
    SumCtx ctx = {0};

    for_each(values, 4, add_to_sum, &ctx);

    check_int_msg(ctx.sum, 10, "Sum should be 10");

    return 0;
}
