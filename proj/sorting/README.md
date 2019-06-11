## Sorting Algorithms

 In computer science, a sorting algorithm is an algorithm that puts elements of a list in a certain order. The most frequently used orders are numerical order and lexicographical order. Efficient sorting is important for optimizing the efficiency of other algorithms (such as search and merge algorithms) which require input data to be in sorted lists. Sorting is also often useful for canonicalizing data and for producing human-readable output. More formally, the output of any sorting algorithm must satisfy two conditions:

1. The output is in nondecreasing order (each element is no smaller than the previous element according to the desired total order);
2. The output is a permutation (a reordering, yet retaining all of the original elements) of the input.

 Further, the input data is often stored in an array, which allows random access, rather than a list, which only allows sequential access; though many algorithms can be applied to either type of data after suitable modification.

### Exchange Sort

 Exchange sorting algorithms keep exchanging two values. To optimize the operation, the algorithm should find the optimal values to change. Bubble sort, quick sort, and comb sort are exchange sort algorithms.

### Selection Sort

 Selection sorting algorithms choose proper value, and fix its location. For example, heap sort, which is one of selection sort algorithm, choose the maximum value in heap and put it in the last position of sorted array. Selection sort, heap sort, and cycle sort are the examples of selection sort algorithms.

### Insertion Sort

 Insertion sorting algorithms keep putting the value in partially sorted array. To do this, the algorithm should have partially sorted array in the intermediate process. Insertion sort, shell sort, and library sort are insertion sort algorithms.

### Merge Sort

 This is just original merge sort and variation of it. Main idea is same: 1. Partition the array, 2. Merge them. The difference is in how to merge partitioned arrays. There are merge sort, cascade merge sort, and polyphase merge sort in merge sorting algorithms.

### Distribution Sort

 Distribution sorting algorithms set proper position for every element by distributing their key, and sort them in detail. Selecting key is very important for distribution sorting algorithms. Bucket sort, proxmap sort, and counting sort are the examples.

### Concurrent Sort

 In concurrent sorting algorithms, many values are exchanged in the same step. Bitonic sort, batcher odd-even sort, and pairwise sorting network are concurrent sorting algorithms.

### Hybrid Sort

 Hybrid sorting algorithms combine two sorting algorithms and take the advantages of both. These are very efficient for many cases. Timsort is insertion + merge, and introsort is quicksort + heapsort.

### Others

 Not included in any method. Topological sort, pancake sort, and spaghetti sort are here.
