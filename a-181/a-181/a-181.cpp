#include <iostream>
#include <algorithm>

using namespace std;

int sum;
int n;
int arr[100010];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	stable_sort(arr, arr + n);
	if (arr[0] > 1) {
		cout << 1;
	}
	else {
		for (int i = 1; i < n; i++) {
			if ( sum-arr[i] > 1) {
				cout << sum + 1;
				break;
			}
			else {
				sum += arr[i];
			}
		}
	}
}