#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int data;
    Node *parent;
    Node *left;
    Node *right;
} Node;

void printArray(int num[], int size) {
    /* Print array num[] */
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}
Node *buildCartesianTree(int num[], int size) {
    Node *root = (Node *)malloc(sizeof(Node));
    Node *rightmost;
    int i;

    /* root initialization */
    root->data = num[0];
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;
    rightmost = root;

    for (i = 1; i < size; i++) {
        Node *newnode = (Node *)malloc(sizeof(Node));

        newnode->data = num[i];
        newnode->parent = rightmost;
        rightmost->right = newnode;

        while (newnode->parent != NULL && newnode->parent->data > newnode->data) {
            newnode->parent = newnode->parent->parent;
            newnode->right = newnode->parent;
        }

        if (newnode->parent == NULL) {
        }   // newnode has the biggest number as data
        else {
            newnode->left = newnode->parent->right;
            newnode->parent->right = newnode;
        }   // Insert newnode
    }
    return root;
}
asdf int depth) {
    /* num : array to be sorted
     * left : lower index in the range to be sorted
     * right : higher index in the range to be sorted
     * depth : depth cannot be a negative number
               if depth is not zero, partition the array
               if depth is zero, stop partitioning and perform heapsort
     */

    if (left >= right) return; // The range contains only one or zero numbers

    if (maxdepth == 0) {
        // heapsort();
    }   // Perform heapsort
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

    Node *root = buildCartesianTree(num, SIZE);
    CartesianTreeSort
    introSort(num, 0, SIZE - 1, depth);

    /* Print sorted array */
    printArray(num, SIZE);
    return 0;
}
