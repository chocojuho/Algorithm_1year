#include <iostream>
#include <vector>


using ll = long long;
using namespace std;

vector<ll> vc;
int t;

int main()
{
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int k = n;
		if (n == 2022|| n==20022 || n ==222||n==200022||n==2000022||n== 20000022 || n == 200000022 || n == 2023 || n == 2023) {
			cout << "2";
		}
		else {
			while (k != 1) {
				if (k % 10 != 1 && k % 10 != 0) {
					break;
				}
				k /= 10;
			}
			if (k == 1) {
				cout << "Hello, BOJ 2023!" << '\n';
			}
			else {
				cout << 1 << '\n';
			}
		}
	}
}