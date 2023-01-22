#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;
long long n;
long long k;

int main()
{
	scanf("%d", &n);
	scanf("%d", &k);
	printf("%.6lf", (float)n*(n-1)/2 * k * pow(k,n-2));
}