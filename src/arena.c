#include "arena.h"
#define MAX_MARKS 16
// assume alignment is 8 bytes

// constructor
Arena *arena_create(size_t size) {
        if (!size)
                return NULL;
        size = (size + 7) & ~7;
        Arena *arena = (Arena *)malloc(sizeof(Arena));
        if (!arena)
                return NULL;
        arena->initial = malloc(size);
        if (!arena->initial) {
                free(arena);
                return NULL;
        }
        arena->checkpoints = malloc(sizeof(void*)*MAX_MARKS);
        if (!arena->checkpoints) {
                free(arena->initial);
                free(arena);
                return NULL;
        }
        arena->current = arena->initial;
        arena->capacity = size;
        arena->marks = 0; // total marks created
        return arena;
}

void *arena_alloc(Arena *arena, size_t size) {
        if (!arena)
                return NULL;
        if (!size)
                return NULL;
        size = (size + 7) & ~7;
        if ((arena->current - arena->initial + size) > arena->capacity)
                return NULL;
        void *temp = arena->current;
        arena->current += size;
        return temp;
}

void arena_dealloc(Arena *arena) {
        if (!arena)
                return;
        free(arena->checkpoints);
        free(arena->initial);
        free(arena);
}

void arena_reset(Arena *arena) {
        if (!arena)
                return;
        arena->current = arena->initial;
}

void arena_mark(Arena* arena){
        if(!arena) return;
        if(arena->marks < MAX_MARKS){
                arena->marks += 1;
                *(arena->checkpoints + arena->marks - 1) = arena->current; // you can create multiple marks continuously without ever allocating a object
        }
        return;
}

void arena_rewind(Arena* arena){
        if(!arena) return;
        if(arena->marks>0){
                arena->current = *(arena->checkpoints + arena->marks - 1);
                arena->marks-=1;
        }
        return;
}
