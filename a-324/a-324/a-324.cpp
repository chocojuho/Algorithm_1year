#include <iostream>

using namespace std;

int t;

int main()
{
	cin >> t;
	while (t--) {
		int arr[1101] = {0, };
		int n;
		int mmx = 0;
		int mmn = 1023;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
			for (int k = 0; k < n; k++) {
				mmx |= arr[k];
				mmn &= arr[k];
			}
		cout << mmx - mmn<< '\n';
	}
}