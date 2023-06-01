#include <stdio.h>


int size_of_int_array(int* arr) {
    return (*(&arr + 1) - arr) / sizeof(int);
}

int size_of_matrix(int** m) {
    return (*(&m + 1) - m) / sizeof(int*);
}

int** create_matrix() {
    int l0[3] = {1, 0, 0};
    int l1[3] = {0, 1, 0};
    int l2[3] = {0, 0, 1};
    
    int* m[3] = {l0, l1, l2};
    return m;
}

void print_matrix(int** m) {
    int length = size_of_matrix(m);
    printf("AOBA");
    
    for (int i = 0; i < length; i++) {
        printf("[");
        for (int j = 0; j < size_of_int_array(&m[i]); j++) {
            printf("%i", m[i][j]);
            
            if (j < length - 1)
                printf(", ");
            else
                printf("]");
        }
    }
}

int main() {
    int l0[3] = {1, 0, 0};
    int l1[3] = {0, 1, 0};
    int l2[6] = {0, 0, 1};
    
    int* m[3] = {l0, l1, l2};
    
    for (int i = 0; i < 3; i++) {
        printf("[");
        for (int j = 0; j < 3; j++) {
            printf("%i", m[i][j]);
            
            if (j < 2)
                printf(", ");
            else
                printf("]\n");
        }
    }
    
    printf("%i", size_of_int_array(l2));
    
    int** m1 = create_matrix();
    
    //print_matrix(m1);

    return 0;
}
