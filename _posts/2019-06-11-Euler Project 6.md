---
layout: post
title: "Project Euler Prob.6"
date: 2019-06-11
excerpt: "This is Problem 6"
tags: [Project Euler]
comments: true
---

## Problem

The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

## Sol. 1

```c
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

```
