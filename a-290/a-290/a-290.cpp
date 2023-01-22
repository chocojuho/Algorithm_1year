#include <iostream>


using ll = long long;
using namespace std;

ll t;

int main()
{
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		if (n % 3 == 0) {
			cout << pow(n / 3, 3);
		}
		else if (n % 4 == 0) {
			cout << pow(n, 3) / 32;
		}
		else {
			cout << -1 << '\n';
		}
	}
}