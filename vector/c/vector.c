#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

/**************************/
/* IMPLEMENTATION SECTION */
/**************************/


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

void vector_resize(vector *v, int new_capacity) {
    void **new_val = realloc(v->val_array, sizeof(void *) * new_capacity);

    if (new_val) {
        v->val_array = new_val;
        v->capacity = new_capacity;
    }
}

int find(vector *v, void *value) {
    for(int i = 0; i < v->size; i++) {
        if (value == v->val_array[i])
            return 1;
    }

    return -1;
}

void *vector_at(vector *v, int index) {
    if (index >= 0 && index <= v->size)
        return v->val_array[index];
    
    return NULL;
}

void vector_push(vector *v, void * value) {
    v->size++;
    check_increase(v);
    v->val_array[v->size-1] = value;
}

void vector_insert(vector *v, int index, void *value) {
    if (index < 0 || index > v->size)
        return;

    v->size++;

    check_increase(v);

    for (int i = v->size; i > index; i--) {
        v->val_array[i] = v->val_array[i-1];
    }

    v->val_array[index] = value;
}

void vector_prepend(vector *v, void * value) {
    vector_insert(v, 0, value);
}

void *vector_pop(vector *v) {
    if (v->size == 0)
        return NULL;
    
    void *value = v->val_array[v->size-1];

    v->val_array[v->size-1] = NULL;
    v->size--;
    check_decrease(v);

    return value;
}

void vector_delete(vector *v, int index) {
    if (index < 0 || index > v->size)
        return;

    v->val_array[index] == NULL;

    int i = index;
    while(i < v->size) {
        v->val_array[i] = v->val_array[i+1];
        v->val_array[i+1] = NULL;

        i++;
    }

    v->size--;

    check_decrease(v);
}

void vector_remove(vector *v, void *value) {
    for (int i = 0; i < v->size; i ++) {
        if (value == v->val_array[i]) {
            vector_delete(v, i);
        }
    }
}

void vector_free(vector *v) {
    free(v->val_array);
}

/*********************/
/* AUXILIARY SECTION */
/*********************/

void check_increase(vector *v) {
    if (v->size == v->capacity)
        vector_resize(v, v->capacity * 2);
}

void check_decrease(vector *v) {
    if (v->size > 0 && v->size < v->capacity / 4)
        vector_resize(v, v->capacity / 2);
}
