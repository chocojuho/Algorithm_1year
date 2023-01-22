#include <iostream>

using namespace std;
int t;
int n;
int arr[110];
int same = 0;
int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int cnt = 0;
		same = 0;
		for (int i = 0; i < n-1; i++) {
			if ((arr[i] % 2) == (arr[i + 1] % 2)) {
				//cout << arr[i] << ' ' << arr[i + 1] << '\n';
				same++;
			}
			else {
				if (same != 0) {
					cnt += same;
				}
				same = 0;
			}
		}
		if (same != 0) {
			cnt += same;
		}
		cout << cnt << '\n';
	}
}