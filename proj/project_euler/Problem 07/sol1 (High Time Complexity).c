#include <stdio.h>

int main(void)
{
    int but, i;
    int count = 0;
    for (i = 2; ; i++) {
        but = 0;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) but = 1;
        }
        if (but == 0) count++;
        if (count == 10001) break;
    }
    printf("%d", i);
}