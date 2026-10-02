#include<stdio.h>
#include<stdlib.h>
#include "dynamic_array.h"

int vec_init(vec_int* vector,size_t capacity){
        // only pass stack initialised object
        if(!vector) return -1;
        if(capacity==0) return -1;
        vector->ptr = (int*)malloc(capacity*sizeof(int));
        if(!vector->ptr) return -1;
        vector->capacity = capacity;
        vector->size = 0;
        return 0;
}

int vec_get(const vec_int* vector,size_t index){
        if(!vector) {
                perror("Accessing Null ptr");
                exit(EXIT_FAILURE);
        }
        if(index >= vector->size) {
                perror("Out of Bound indexing");
                exit(EXIT_FAILURE);
        }
        return (vector->ptr)[index];
}

void vec_put(vec_int* vector,size_t index,int value){
        if(!vector) {
                perror("Accessing Null ptr");
                exit(EXIT_FAILURE);
        }
        if(index >= vector->size) {
                perror("Out of Bound indexing");
                exit(EXIT_FAILURE);
        }
        (vector->ptr)[index] = value;
}

void vec_append(vec_int* vector,int value){
        if(!vector) {
                perror("Accessing Null ptr");
                exit(EXIT_FAILURE);
        }
        if(vector->size == vector->capacity){
                vector->ptr = realloc(vector->ptr,vector->capacity*2*sizeof(int));
                if(!vector->ptr) {
                        perror("Reallocation failed");
                        exit(EXIT_FAILURE);
                }
                vector->capacity*=2;
        }
        (vector->ptr)[vector->size] = value;
        vector->size += 1;
}

void vec_free(vec_int* vector){
        if(!vector) return;
        free(vector->ptr);
        vector->ptr = NULL;
        vector->size = vector->capacity = 0;
}
