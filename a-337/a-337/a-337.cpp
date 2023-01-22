﻿#define mod 1000000007
#include <iostream>

using ll = long long;
using namespace std;

ll t;
ll r, b;
ll ans;
ll dp[510][51010];
ll pre[510][51010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	dp[0][0] = 1;
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 50000; j++) {
			dp[i + 1][j + i + 1] = (dp[i + 1][j + i + 1] + dp[i][j]) % mod;
			dp[i + 1][j] = (dp[i][j] + dp[i + 1][j]) % mod;
		}
	}
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 50000; j++) {
			ll k = (j == 0) ? 0 : pre[i][j-1];
			pre[i][j] = (dp[i][j] + k)%mod;
		}
	}
	while (t--) {
		ans = 0;
		cin >> r >> b;
		for (int i = 1; i <= 500; i++) {
			ll all = (i + 1) * i / 2;
			ll k = (all-b-1>=0)?pre[i][all - b - 1]:0;
			if(all-b <= r){
				ans = (ans+ (pre[i][r] - k)+ mod) % mod;
			}
		}
		cout << ans << '\n';
	}
}