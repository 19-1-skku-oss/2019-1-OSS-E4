#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int num[], int size) {
    /* Print array num[] */
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}
void gnomeSort(int num[], int size) {
    int pos = 0;
    while (pos < size) {
        if (pos == 0 || num[pos] >= num[pos - 1]) {
            pos++;
            continue;
        }	// No swap
        else {
            int swap = num[pos];
            num[pos] = num[pos - 1];
            num[pos - 1] = swap;
            pos--;
        }	// Swap
    }
}
int main(void) {
    int num[10];
    int i;

    srand(time(NULL));

    /* Get 10 random numbers (range : 0 <= n <= 100) */
    for (i = 0; i < 10; i++) {
        num[i] = rand() % 101;
    }

    /* Print initial array */
    printArray(num, 10);

    gnomeSort(num, 10);

    /* Print sorted array */
    printArray(num, 10);
    return 0;
}
