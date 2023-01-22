#include <iostream>

using namespace std;

int t;

int main()
{
	cin >> t;
	while (t--) {
		string str;
		int n = 0;
		int sum = 0;
		cin >> n;
		cin >> str;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				if (str[i] == '0') {
					sum += 0;
				}
				else {
					sum += 1;
				}
				continue;
			}
			if (str[i] == '0') {
				cout << '+';
			}
			else {
				if (sum == 1) {
					cout << '-';
					sum = 0;
				}
				else {
					sum = 1;
					cout << '+';
				}
			}
		}
		cout << '\n';
	}
}