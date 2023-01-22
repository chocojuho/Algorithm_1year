#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int a, b;

int main()
{
	scanf("%d %d", &a, &b);
	printf("%.3lf", (double)b / a);
}