---
layout: post
title: "Project Euler Prob.1"
date: 2019-06-09
excerpt: "This is Problem 1"
tags: [Project Euler]
comments: true
---

## Problem

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.


## Sol. 1

```c
#include <stdio.h>

int main(){
    int t; 
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long N,p=0,sum=0;	
         
        scanf("%lld",&N);	//Take input of N from user
        p = (N-1)/3;
        sum = ((3*p*(p+1))/2);

        p = (N-1)/5;
        sum = sum + ((5*p*(p+1))/2);

        p = (N-1)/15;
        sum = sum - ((15*p*(p+1))/2);
        printf("%lld\n", sum);		//print the sum of all numbers that are multiples of 3 & 5 below N
    }
    return 0;
}
```

## Sol. 2

```c
#include <stdio.h>

int main() {
	int n = 0;
	int sum = 0;
	scanf("%d", &n);

	int terms = (n - 1) / 3;
	sum += ((terms)*(6 + (terms - 1) * 3)) / 2; //sum of an A.P.
	terms = (n - 1) / 5;
	sum += ((terms)*(10 + (terms - 1) * 5)) / 2;
	terms = (n - 1) / 15;
	sum -= ((terms)*(30 + (terms - 1) * 15)) / 2;

	printf("%d\n", sum);
}
```

## Sol. 3

```c
#include <stdio.h>

int main() {
	int n = 0;
	int sum = 0;
	int num = 0;
	scanf("%d", &n);
	
	while (1) {
		num += 3;
		if (num >= n)
			break;
		sum += num;
		num += 2;
		if (num >= n)
			break;
		sum += num;
		num += 1;
		if (num >= n) 
			break;
		sum += num;
		num += 3;
		if (num >= n) 
			break;
		sum += num;
		num += 1;
		if (num >= n) 
			break;
		sum += num;
		num += 2;
		if (num >= n) 
			break;
		sum += num;
		num += 3;
		if (num >= n) 
				break;
		sum += num;
	}

	printf("%d\n", sum);
}
```