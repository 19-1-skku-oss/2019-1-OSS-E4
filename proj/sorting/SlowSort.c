#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int num[], int size) {
    /* Print array num[] */
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}
void slowSort(int num[], int left, int right) {
    /* num : array to be sorted
     * left : lower index in the range to be sorted
     * right : higher index in the range to be sorted
     */

    if (left >= right) return; // The range contains only one or zero numbers

    /* Call slowSort() recursively */
    int mid = (left + right) / 2;
    slowSort(num, left, mid);
    slowSort(num, mid + 1, right);

    if (num[right] < num[mid]) {
        int swap = num[right];
        num[right] = num[mid];
        num[mid] = swap;
    } // The maximum value of num in range from left to right is now in num[right]

    /* Sort the array without the local maximum value */
    slowSort(num, left, right - 1);
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

    slowSort(num, 0, 9);

    /* Print sorted array */
    printArray(num, 10);
    return 0;
}
