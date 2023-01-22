#include <iostream>

using namespace std;
int n, m;
string arr[1000];
int cnt = 0;
int ans;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
			cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int cnt = 0;
			for (int k = 0; k < m; k++) {
				if (arr[i][k] == 'o' || arr[j][k] == 'o') {
					cnt++;
				}
			}
			if (cnt == m) {
				ans++;
			}
		}
	}
	cout << ans;
}