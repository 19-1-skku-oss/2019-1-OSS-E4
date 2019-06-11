#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define COMPARE1(a, b)	(++(*cnt) && (a*2017)%10000 > (b*2017)%10000)
#define COMPARE2(a, b)	(++(*cnt) && (a*2017)%10000 >= (b*2017)%10000)
#define MAX_SIZE 1000000

void Solution(int list[], int n, int *cnt) {
  void insertionSort(int *arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (!COMPARE1(arr[j], temp) && j >= left)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
  }

  void merge(int arr[], int l, int m, int r)
  {
    // original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    int *left_start = (int*)malloc(sizeof(int) * len1);
    int *right_end = (int*)malloc(sizeof(int) * len2);
    for (int i = 0; i < len1; i++)
        left_start[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right_end[i] = arr[m + 1 + i];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < len1 && j < len2)
    {
        if (left_start[i] == right_end[j]) {
            arr[k] = left_start[i];
            i++;
        }
        else {
            if (COMPARE1(left_start[i], right_end[j]))
            {
                arr[k] = left_start[i];
                i++;
            }
            else
            {
                arr[k] = right_end[j];
                j++;
            }
            k++;
        }
    }
    while (i < len1)
    {
        arr[k] = left_start[i];
        k++;
        i++;
    }
    while (j < len2)
    {
        arr[k] = right_end[j];
        k++;
        j++;
    }
    free(left_start);
    free(right_end);
  }
  void timSort(int arr[], int n)
  {
      for (int i = 0; i < n; i+=32)
        insertionSort(arr, i, (i+31 < n - 1) ? i + 31 : n - 1);
      for (int size = 32; size < n; size = 2*size)
      {
          for (int left = 0; left < n; left += 2*size)
          {
              int mid = left + size - 1;
              int right = ((left + 2 * size - 1) < (n-1)) ? (left + 2 * size - 1) : (n - 1);
              merge(arr, left, mid, right);
          }
      }
  }
  timSort(list, n);
/* Modify to here */
}

int main() {
    int n, *list, *read, cnt = 0;
    
	scanf("%d", &n);
	list = malloc(sizeof(int)*n);
	read = malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		read[i] = list[i];
	}

	Solution(list, n, &cnt);
/*
  printf("Encrypted Data\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i]);

	}
  printf("\nDecrypted Data\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", list[i] * 2017 % 10000);

	}
*/
	printf("\nThe number of comparisons: %d\n",cnt);

	return 0;
}
