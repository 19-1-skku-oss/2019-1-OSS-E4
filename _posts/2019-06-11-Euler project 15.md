---
layout: post
title: "Project Euler Prob.15"
date: 2019-06-11
excerpt: "This is Problem 15"
tags: [Project Euler]
comments: true
---

## Problem

Starting in the top left corner of a 2X2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20X20 grid?

## Sol. 1

```c
#include <stdio.h>
using namespace std;
int main()
{
	long long arr[22][22];
	for (int i = 1; i <= 21; i++)
	{
		arr[i][1] = 1;
		arr[1][i] = 1;
	}
	for (int i = 2; i <= 21; i++)
	{
		for (int j = 2; j <= 21; j++)
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
	}
	printf("%lld", arr[21][21]);
}
```