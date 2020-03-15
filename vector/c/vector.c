#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(vector * v) {
    v->capacity = INIT_CAPACITY;
    v->size = 0;
    v->val_array = malloc(sizeof(void *) * v->capacity);
}

int vector_size(vector * v) {
    return v->size;
}

int vector_capacity(vector *v) {
    return v->capacity;
}

int is_empty_vector(vector *v) {
    return v->size == 0;
}

void vector_free(vector *v) {
    free(v->val_array);
}