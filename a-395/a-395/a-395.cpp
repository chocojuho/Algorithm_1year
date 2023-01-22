#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int t;
int n, m;
vector<int> vc;
set<int> st;
int mmn;
int mmx;
bool chk(int mid,int i) {
	if (!(vc[mid] % i)) {
		return 1;
	}
	return 0;
}

int main()
{
	cin >> t;
	while (t--) {
		mmn = 9999999;
		mmx = -9999999;
		st.clear();
		vc.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			vc.push_back(k);
		}
		sort(vc.begin(), vc.end(), [&](auto a, auto b) {return a < b; });
		for (int i = 2; i <= m; i++) {
			int l = 0;
			int r = vc.size() - 1;
			while (l < r) {
				int mid = (l + r+1) / 2;
				if (chk(mid,i)) {
					l = mid;
				}
				else {
					r = mid - 1;
				}
			}
			if (vc[l] % i==0) {
				st.insert(vc[l]);
				mmn = min(mmn, vc[l]);
				mmx = max(mmx, vc[l]);
			}
		}
		if (st.size() == 1) {
			cout << "0" << '\n';
		}
		else if (st.size() == 0) {
			cout << "-1" << '\n';
		}
		else {
			cout << mmx - mmn << '\n';
		}
	}
}