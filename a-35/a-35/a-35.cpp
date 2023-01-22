#include <iostream>

using namespace std;
int n, m;
int arr[10010];
int sum;
int cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sum = arr[0];
	int i = 0,j = 0;
	while (j<n) {
		if (sum == m) {
			sum += arr[j++];
			cnt++;
		}
		else if (sum < m) {
			sum += arr[j++];
		}
		else if (sum > m) {
			sum -= arr[i++];
		}
	}
	cout << cnt;
}