#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
int t;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<int> vc;
		vector<int> lis;
		int sum = 0;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			vc.push_back(a);
		}
		for (int j = 0; j < n; j++) {
			if (lis.empty()) {
				lis.push_back(vc[j]);
				continue;
			}
			if (lis.back() < vc[j]) {
				lis.push_back(vc[j]);
			}
			else {
				int curser = lower_bound(lis.begin(), lis.end(), vc[j]) - lis.begin();
				lis[curser] = vc[j];
			}
		}
		cout << "Case #" << i + 1 << ": " << pow(2,lis.size())-1 << '\n';
	}
}