/*
Problem

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 ¡¿ 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>
using namespace std;
int main()
{
	int a, b, maxx = 0;
	int arr[10];
	for (a = 999; a >= 100; a--)
	{
		for (b = 999; b >= 100; b--)
		{
			int i, cnt = 0, v;
			v = a * b;
			while (v > 0)
			{
				arr[cnt] = v % 10;
				cnt++;
				v /= 10;
			}
			cnt--;
			for (i = 0; i <= cnt; i++)
			{
				if (arr[i] != arr[cnt - i])
					break;
			}
			if (i > cnt)
			{
				if (a * b > maxx)
					maxx = a * b;
			}
		}
	}
	printf("%d\n", maxx);
}