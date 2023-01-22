#define mod 1000000007
#include <iostream>


using ll = long long;
using namespace std;

ll dp[5010];
int t,n;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	dp[2] = 1;
	dp[4] = 2;
	for (int i = 6; i <= 5000; i += 2) {
		cout << i << ": ";
		dp[i] = (dp[i - 2]%mod+dp[i]%mod)%mod;
		cout << dp[i] << ' ';
		for (int j = i-2; j > 2; j -= 2) {
			dp[i] = ((dp[j]%mod + dp[i - j]%mod)%mod+dp[i]%mod)%mod;
			cout << dp[i] << ' ';
		}
		cout << '\n';
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}