---
layout: post
title: "Project Euler Prob.7"
date: 2019-06-11
excerpt: "This is Problem 7"
tags: [Project Euler]
comments: true
---

## Problem

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10,001st prime number?

## Sol. 1

```c
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
```
