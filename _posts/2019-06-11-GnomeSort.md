---
layout: post
title: "Gnomesort"
date: 2019-06-11
excerpt: "Gnomesort is sorting algorithm"
tags: [Sorting, ExchangeSort]
comments: true
---

## Operation

Gnomesort is one of exchange sorting algorithms. The operation is very similar to Insertionsort.

1. Start at the first index of the array.
2. Keep searching until the present value is smaller than the previous value.
3. Swap the present value and previous value.
4. Decrease the present index by one, and repeat step 2 ~ 4 until the present index reaches the last index.

## Time Complexity

The average running time is O(n<sup>2</sup>), and in some good cases, it tends towards O(n). These good cases are when the array is initially almost sorted, like the best case for insertion sort.

## Image Example

![Gnomesort image](https://www.google.com/imgres?imgurl=https%3A%2F%2Fupload.wikimedia.org%2Fwikipedia%2Fcommons%2F3%2F37%2FSorting_gnomesort_anim.gif&imgrefurl=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FGnome_sort&docid=PkrhIKUNnJ3n-M&tbnid=8NtInrV4Js0q8M%3A&vet=10ahUKEwi98qef9ODiAhWMy4sBHeGGDawQMwg-KAAwAA..i&w=277&h=344&client=ubuntu&bih=855&biw=1853&q=gnome%20sort&ved=0ahUKEwi98qef9ODiAhWMy4sBHeGGDawQMwg-KAAwAA&iact=mrc&uact=8)

## Source Code by C

```c
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
```
