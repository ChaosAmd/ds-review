#ifndef VECTOR_H
#define VECTOR_H

#define INIT_CAPACITY 16

typedef struct vector {
    void **val_array;
    int size;
    int capacity;
} vector;

void vector_init(vector *v); // Initializes vector
int vector_size(vector *v); // get the size of vector
int vector_capacity(vector *v); // gets the number of items it can hold
int is_empty_vector(vector *v); // self explanatory
int find(vector * v, void * value); // searchs for the value and return index of the file searched, else returns -1
void *vector_at(vector *v, int index); // gets the item of a vector given an index info
void vector_push(vector *v, void * value); // insert an item at the end of the file
void vector_insert(vector *v, int index, void * value); // insert the value with from the given index
void vector_prepend(vector *v, void * value); // insert at the head of the vector
void vector_pop(vector *v); // erases the content of the end of vector
void vector_delete(vector *v, int index); // erases the content of the index value and then shifts to the left
void vector_remove(vector *v, void * value); // Search for the value and then removes the value(even if multiples places)
void vector_free(vector *v); // self explanatory


#endif