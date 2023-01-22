#include <iostream>
#include <algorithm>

using namespace std;

long long n;
short arr[10000010];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
}