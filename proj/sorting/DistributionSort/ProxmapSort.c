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
void proxmapSort(int num[], int size) {
    int i;
    int j;
    int max;
    static int gap = 10;
    int *hitCount;
    int *proxMap;
    int *location = (int *)malloc(size * sizeof(int));
    int *sorted = (int *)malloc(size * sizeof(int));

    max = num[0];
    for (i = 1; i < size; i++) {
        if (num[i] > max) max = num[i];
    }
    hitCount = (int *)malloc(((max / gap) + 1) * sizeof(int));
    proxMap = (int *)malloc(((max / gap) + 1) * sizeof(int));

    for (i = 0; i < max / gap + 1; i++) {
        hitCount[i] = 0;
        proxMap[i] = 0;
    }
    for (i = 0; i < size; i++) {
        sorted[i] = -1;
    }

    for (i = 0; i < size; i++) {
        hitCount[num[i] / gap]++;
    }
    proxMap[0] = 0;
    for (i = 1; i < max / gap + 1; i++) {
        proxMap[i] = proxMap[i - 1] + hitCount[i - 1];
    }
    for (i = 0; i < size; i++) {
        location[i] = proxMap[num[i] / gap];
    }

    for (i = 0; i < size; i++) {
        int flag = 0;
        for (j = location[i]; j < location[i] + hitCount[num[i] / gap]; j++) {
            if (sorted[j] == -1)
            {
                sorted[j] = num[i];
                flag = 1;
                break;
            }
            else if (sorted[j] > num[i]) break;
        }
        if (flag) continue;
        int lbound = j;
        for (j = location[i] + hitCount[num[i] / gap] - 2; j >= lbound; j--) {
            sorted[j + 1] = sorted[j];
        }
        sorted[lbound] = num[i];
    }

    for (i = 0; i < size; i++) {
        num[i] = sorted[i];
    }
    free(hitCount);
    free(proxMap);
    free(location);
    free(sorted);
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

    proxmapSort(num, SIZE);

    /* Print sorted array */
    printArray(num, SIZE);
    return 0;
}
