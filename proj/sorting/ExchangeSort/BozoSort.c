#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE (10)

void printArray(int num[], int size) {
    /* Print array num[] */
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}
int isSorted(int num[], int size) {
    int i;

    for (i = 0; i < size - 1; i++) {
        if (num[i] > num[i + 1]) return 0;  // not sorted
    }
    return 1;   // sorted
}
void bozoSort(int num[], int size) {
    while (!isSorted(num, size)) {
        int idx1 = rand() % size;
        int idx2 = rand() % size;
        
        int swap = num[idx1];
        num[idx1] = num[idx2];
        num[idx2] = swap;
    }
}
int main(void) {
    int num[SIZE];
    int i;

    srand(time(NULL));

    /* Get SIZE random numbers (range : 0 <= n <= 100) */
    for (i = 0; i < SIZE; i++) {
        num[i] = rand() % 101;
    }

    /* Print initial array */
    printArray(num, SIZE);

    bozoSort(num, SIZE);

    /* Print sorted array */
    printArray(num, SIZE);
    return 0;
}
