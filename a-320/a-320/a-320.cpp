#include <iostream>
#include <vector>

using namespace std;

int t;

int main()
{
	cin >> t;
	while (t--) {
		vector<int> vc;
		bool use = false;
		int k, n;
		cin >> k >> n;
		int sum = 1;
		int i;
		for (i = 0; sum <= n && i <= k; i++) {
			sum += i;
			vc.push_back(sum);
		}i--;
		sum -= i;
		 
		vc.pop_back();
		if (sum == n && i<=k-1) {
			vc.pop_back();
			sum -= --i;
		}
		while (i <= k - 1) {
			sum += 1;
			vc.push_back(sum);
			i++;
		}
		for (int i = 0; i < vc.size(); i++) {
			cout << vc[i] << ' ';
		}
		cout << '\n';
	}
}