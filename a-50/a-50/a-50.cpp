﻿#include <iostream>

using namespace std;

int n;
int arr[100010];
int dp[100010];
int mmx;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	mmx = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}
	for (int i = 1; i < n; i++) {
		mmx = max(dp[i], mmx);
	}
	cout << mmx;
}