int sequentialSearch(int array[], int n, int m, int value) { // Starts from n to m

    int i;

    for (i = n; i <= m; i++)

        if (array[i] == value)

            return i;

    return -1;

}
