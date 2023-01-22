#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <math.h>


using namespace std;

int lis[1010] = { 1, };
int input[1010];
int mmx = -99999;
int midx = 0;

int answer(int target,int now) {
	if (now < 0) {
		return 0;
	}
	if (lis[now] == target) {
		answer(target - 1, now - 1);
		printf("%d ", input[target]);
	}
	else {
		answer(target, now - 1);
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &input[i]);
	}

	for (int i = 0; i < num; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++) {
			if (input[i] > input[j]) {
				lis[i] = max(lis[j] + 1, lis[i]);
			}

		}
	}
	for (int i = 0; i < num; i++) {
		if (mmx < lis[i]) {
			mmx = lis[i];
			midx = i;
		}
	}
	printf("%d\n", mmx);
	answer(mmx,midx);
	
}