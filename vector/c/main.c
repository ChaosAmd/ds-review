#include <stdio.h>
#include "vector.h"

void ivector_transversal(vector * v) {
    for (int i = 0; i < v->size; i++) {
        printf(" %d ", (int *) vector_at(v, i));
    }
    printf(".\n");
}

int main() {
    vector vec;
    vector_init(&vec);

    printf("1. The initialization of vector: \n");
    printf("\t1.1 Initial Size: %d.\n", vector_size(&vec));
    printf("\t1.2 Initial capacity: %d.\n", vector_capacity(&vec));
    printf("\t1.3 Is empty: %d\n", is_empty_vector(&vec));

    printf("2. Operations of push, insert, and preppend.\n");
    vector_push(&vec, 45);
    vector_push(&vec, 666);
    vector_push(&vec, 888);
    vector_push(&vec, 999);
    vector_push(&vec, 12121);
    printf("\t2.1 Prints some values pushed, using 'at' to show: ");
    ivector_transversal(&vec);


    vector_prepend(&vec, 23);
    vector_prepend(&vec, 22);
    vector_prepend(&vec, 1);

    printf("\t2.2 Prints some values preppended, using 'at' to show: ");
    ivector_transversal(&vec);
    

    printf("3. Delete operations.\n");
    printf("\t3.1 Values popped: ");
    for(int i = 0; i < 2; i++)
        printf(" %d", (int *) vector_pop(&vec));
    printf("\n");    

    printf("\t3.2 The new array: ");
    ivector_transversal(&vec);

    printf("\t3.3 Array after remove and delete: ");
    vector_remove(&vec, 22);
    vector_remove(&vec, 888);
    ivector_transversal(&vec);


    vector_free(&vec);
    return 0;
}

