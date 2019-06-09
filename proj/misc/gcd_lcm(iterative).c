#include <stdio.h>
 
int main()
{
    int a, b, i, g, l;
    scanf("%d %d", &a, &b);
    for (i=1; i<=b; i++) {
        if (a % i == 0 && b % i == 0) {
              g = i;
        }
    }
    l = a * b / g;
    printf("%d %d", g, l);
    return 0;
}