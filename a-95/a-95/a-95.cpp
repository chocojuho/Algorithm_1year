#include <iostream>
#include <math.h>

using namespace std;

int arr[100][100];
int n, m;
int all;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = arr[i][j];
			for (int k = 1; k <= m; k++) {
				if (i + k < n) {
					sum += arr[i + k][j];
				}
				if (j + k < n) {
					sum += arr[i][j + k];
				}
				if (i - k >= 0) {
					sum += arr[i - k][j];
				}
				if (j - k >= 0) {
					sum += arr[i][j - k];
				}
			}
			all = max(sum, all);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = arr[i][j];
			for (int k = 1; k <= m; k++) {
				if (i + k < n && j + k < n) {
					sum += arr[i + k][j + k];
				}
				if (i - k >= 0 && j + k < n) {
					sum += arr[i - k][j + k];
				}
				if (i - k >= 0 && j - k >= 0) {
					sum += arr[i - k][j - k];
				}
				if (i + k < n && j - k >= 0) {
					sum += arr[i + k][j - k];
				}
			}
			all = max(sum, all);
		}
	}
	cout << all;
}