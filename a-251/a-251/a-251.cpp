#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int arr[100010];
int sum = 0;

int function(int mid) {
	int go = 0;
	int start = 0;
	pair<int, int> pr;
	int mini = 0;
	for (int i = 0; i < n; i++) {
		arr[i] -
	}
}

int main()
{
	cin >> n;
	cin >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr,arr+n);
	int l = 0;
	int r = 2000000;
	int mid = (l+r)/2;
	while (l<=r) {
		mid = (l + r) / 2;
		if (function(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
}