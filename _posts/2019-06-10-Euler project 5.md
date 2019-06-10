---
layout: post
title: "Project Euler Prob.5"
date: 2019-06-10
excerpt: "This is Problem 5"
tags: [Project Euler]
comments: true
---

## Problem

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

## Sol. 1

```c
#include <stdio.h>
using namespace std;
int main()
{
	int arr[21] = { 0, };
	int v = 1;
	for (int i = 2; i <= 20; i++)
	{
		if (arr[i] == 0)
		{
			int s = i;
			while (s <= 20)
			{
				arr[s] = 1;
				s *= i;
			}
			v *= s/i;
			s = i;
			while (s <= 20)
			{
				arr[s] = 1;
				s += i;
			}
		}
	}
	printf("%d\n", v);
}
```