#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("samvmam");

    int i, j;
    int lines = 3;
    int memorySlots = 0;
    
    for (i = 0; i <= lines; i++) memorySlots += i;
    
    int** pnumbers;

    pnumbers = (int **) malloc(memorySlots * sizeof(int*));
    
    for (i = 1; i <= lines; i++)
        pnumbers[0] = (int*) malloc(i * sizeof(int));
    
    //pnumbers[0] = (int *) malloc(1 * sizeof(int));
    
    ///*
    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    for (i = 0; i < lines; i++) {
        for (j = 0; j < i; j++) {
            printf("%d", pnumbers[i][j]);
            if(j < i) printf(", ");
        }
        printf("\n");
    }
    //*/

    for (i = 0; i < lines; i++) {
        free(pnumbers[i]);
    }

    free(pnumbers);
    
    
    return 0;
}
