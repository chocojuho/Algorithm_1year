#include <iostream>

using namespace std;

int t;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		if (n<=3 && m<=3) {
			cout << n/2+1 << ' ' << m/2+1 << '\n';
		}
		else {
			cout << n << ' ' << m << '\n';
		}
	}
}
