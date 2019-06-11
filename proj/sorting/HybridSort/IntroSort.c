#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 10

void printArray(int num[], int size) {
    /* Print array num[] */
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}
void heapSort(int num[], int n) {
    int i;
    int j;
    
    /* heapify */
    for (i = n / 2 - 1; i >= 0; i--) {
        j = i;
        while (j <= n / 2 - 1) {
            int left_child = ((j + 1) * 2) - 1;
            int right_child = left_child + 1;
            if (num[j] < num[left_child] || (right_child < n && num[j] < num[right_child])) {
                if (right_child < n && num[j] < num[right_child]) {
                    int swap = num[j];
                    num[j] = num[right_child];
                    num[right_child] = swap;
                    
                    j = right_child;
                }
                else {
                    int swap = num[j];
                    num[j] = num[left_child];
                    num[left_child] = swap;

                    j = left_child;
                }
            }
            else break;
        }
    }

    /* sorting */
    for (i = n - 1; i >= 1; i--) {
        int swap = num[0];
        num[0] = num[i];
        num[i] = swap;
        
        /* heapify */
        j = i;
        while (j <= i / 2 - 1) {
            int left_child = ((j + 1) * 2) - 1;
            int right_child = left_child + 1;
            if (num[j] < num[left_child] || (right_child < i && num[j] < num[right_child])) {
                if (right_child < n && num[j] < num[right_child]) {
                    int swap = num[j];
                    num[j] = num[right_child];
                    num[right_child] = swap;

                    j = right_child;
                }
                else {
                    int swap = num[j];
                    num[j] = num[left_child];
                    num[left_child] = swap;

                    j = left_child;
                }
            }
            else break;
        }
    }
}
int partition(int num[], int left, int right) {
    /* Partition the array using Hoare partition scheme */
    int pivot = num[(left + right) / 2];
    int i = left - 1;
    int j = right + 1;

    while (1) {
        do {
            i++;
        } while (i <= right && pivot > num[i]);
        do {
            j--;
        } while (j >= left && pivot < num[j]);
        if (i >= j) return j;

        int swap = num[i];
        num[i] = num[j];
        num[j] = swap;
    }
}
void introSort(int num[], int left, int right, int depth) {
    /* num : array to be sorted
     * left : lower index in the range to be sorted
     * right : higher index in the range to be sorted
     * depth : depth cannot be a negative number
               if depth is not zero, partition the array
               if depth is zero, stop partitioning and perform heapsort
     */

    if (left >= right) return; // If the range contains only one or zero numbers

    if (depth == 0) {
        heapSort(num + left, right - left + 1);
    }   // Perform heapsort from num[left] to num[right]
    else {
        int p = partition(num, left, right);
        introSort(num, left, p, depth - 1);
        introSort(num, p + 1, right, depth - 1);
    }   // Call introSort() recursively perfoming partition
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

    int depth = (log(SIZE) / log(2)) * 2;
    introSort(num, 0, SIZE - 1, depth);

    /* Print sorted array */
    printArray(num, SIZE);
    return 0;
}
