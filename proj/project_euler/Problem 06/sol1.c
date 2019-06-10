#include <stdio.h>

int main(void)
{
    int number = 100;
    int sum = 0, result1 = 0, result2 = 0;
    for (int i = 1; i <= number; i++) {
        sum += i;
        result1 += i * i;
    }
    result2 = sum * sum;
    printf("%d", result2 - result1);
}
