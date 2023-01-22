#include <iostream>
#define mod 1000000007

using ll = long long;
using namespace std;

ll fact[1000100];
int t;

int main()
{
	fact[0] = 1;
	for (int i = 1; i <1000100; i++) {
		fact[i] = (i % mod * fact[i - 1] % mod) % mod;
	}
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll k = ((((n - 1) % mod * (n % mod))  % mod)*fact[n] % mod)%mod;
		cout << k << '\n';
	}
}