#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
int t;
int main()
{
	cin >> t;
	while (t--) {
		int arr[2][2] = {0,};
		bool flag = false;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			int brr[2][2] = { 0, };
			brr[0][0] = arr[1][0];
			brr[0][1] = arr[0][0];
			brr[1][0] = arr[1][1];
			brr[1][1] = arr[0][1];
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					arr[j][k] = brr[j][k];
				}
			}
			if (arr[0][0] < arr[0][1] && arr[0][1] < arr[1][1] && arr[1][0] < arr[1][1] && arr[0][0] < arr[1][0]) {
				flag = true;
			}
		}
		if (flag) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
}