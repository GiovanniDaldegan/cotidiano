#include <stdio.h>

int main()
{
    long unsigned int fibonacci_sequence[94] = {1, 1};

    for (int i = 2; i < 94; i++)
        fibonacci_sequence[i] = fibonacci_sequence[i-2] + fibonacci_sequence[i-1];
    

    printf("[");

    for (int i = 0; i < 94; i++) {
        printf("%lu", fibonacci_sequence[i]);
        
        if (i < 93) printf(", ");
    }

    printf("]\n(o último valor não é válido; por quê? não sei)");

    return 0;
}
