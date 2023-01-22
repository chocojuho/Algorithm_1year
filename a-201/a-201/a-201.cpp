#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int t;

int cmp(int a, int b) {
	return a > b;
}

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		int sum = 0;
		int before = 0;
		int cnt1 = 0;
		int cnt2 = 0;
		int arr[100010] = {0,};
		int arr2[100010] = { 0, };
		priority_queue<int> vc;
		priority_queue<int> vc2;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> arr[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> arr2[j];
		}
		for (int j = 0; j < n; j++) {
			if (arr[j] == 0) {
				vc.push(-arr2[j]);
			}
			else {
				vc2.push(-arr2[j]);
			}
		}
		if (vc2.size() < vc.size()) {
			for (int j = 1; j < n; j++) {
				//갯수가 더 많은거는 더많은 거 먼저
				//갯수가 더 같을때는 작은거 먼저


			}
		}
		else if (vc2.size() > vc.size()) {

		}
		else {

		}
		cout << sum << '\n';
	}
}