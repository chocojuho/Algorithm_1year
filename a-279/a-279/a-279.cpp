﻿#include <iostream>

using namespace std;

int n;
pair<int,int> arr[100101];
int dp[100010];
int mmx;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	for (int i = 1; i <= n; i++) {
		if (i + arr[i].first <= n+1) {
			dp[i + arr[i].first] = max(dp[i] + arr[i].second, dp[i + arr[i].first]);
		}
		dp[i + arr[i].first] = max(dp[i], dp[i+arr[i].first]);
	}
	for (int i = 1; i <= n+1; i++) {
		mmx=max(dp[i],mmx);
	}
	cout << mmx;
}