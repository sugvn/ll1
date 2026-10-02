#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY
#include<stddef.h>

typedef struct {
        int *ptr;
        size_t size;
        size_t capacity;
}vec_int;

// returns 0 on success, -1 on error
int  vec_init(vec_int *vector, size_t capacity);
void vec_free(vec_int *vector);
int  vec_get(const vec_int *vector, size_t index);
void vec_put(vec_int *vector, size_t index, int value);
void vec_append(vec_int *vector, int value);

#endif
