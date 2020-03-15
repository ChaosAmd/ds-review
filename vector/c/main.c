#include <stdio.h>
#include "vector.h"

int main() {
    vector vec;
    vector_init(&vec);

    printf("1. The initialization of vector: \n");
    printf("\t1.1 Initial Size: %d.\n", vector_size(&vec));
    printf("\t1.2 Initial capacity: %d.\n", vector_capacity(&vec));
    printf("\t1.3 Is empty: %d\n", is_empty_vector(&vec));

    vector_free(&vec);
    return 0;
}