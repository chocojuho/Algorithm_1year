#include <iostream>
#include <vector>

using namespace std;

int t;

int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		int sum = 0;
		bool flag = false;
		vector<int> vc;
		vector<int> ans;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			vc.push_back(a);
		}
		ans.push_back(vc[0]);
		sum = vc[0];
		for (int j = 1; j < n; j++) {
			if (sum - vc[j] >= 0 && (sum-vc[j] != sum+vc[j])) {
				flag = true;
				break;
			}
			sum += vc[j];
			ans.push_back(sum);
		}
		if (flag) {
			cout << -1 << '\n';
		}
		else {
			for (int j = 0; j < ans.size(); j++) {
				cout << ans[j] << ' ';
			}
			cout << '\n';
		}
	}
}