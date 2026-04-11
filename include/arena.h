#ifndef ARENA_ALLOCATER_DEMO
#define ARENA_ALLOCATER_DEMO

#include <stddef.h>
#include <stdlib.h>

typedef struct {
        int marks;
        char *initial;
        char *current;
        char** checkpoints; // a stack
        size_t capacity;
} Arena;

Arena* arena_create(size_t size); 
void *arena_alloc(Arena *a, size_t size);
void arena_dealloc(Arena *a);
void arena_reset(Arena* a);
void arena_mark(Arena* a);
void arena_rewind(Arena* a);

#endif
