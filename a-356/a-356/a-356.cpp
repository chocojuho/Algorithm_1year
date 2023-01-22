#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

using ll = long long;

struct tower {
	ll x;
	ll y;
	int inout;
}t;
vector<tower> vc;
multiset<ll,greater<ll>> st;

int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll l, h, r;
		cin >> l >> h >> r;
		vc.push_back({ l,h,1 });
		vc.push_back({ r,h,0 });
	}
	sort(vc.begin(), vc.end(), [&](auto a, auto b) {
		if (a.x == b.x) {
			if (a.inout == b.inout) {
				return a.y > b.y;
			}
			return a.inout > b.inout;
		}
		return a.x < b.x;
	});
	st.insert(0);
	for (int i = 0; i < vc.size(); i++) {
		ll mp = *(st.begin());
		if (vc[i].inout == 1) {
			st.insert(vc[i].y);
		}
		else {
			st.erase(vc[i].y);
		}
		if (mp != *(st.begin())) {
			cout << vc[i].x << ' ' << *(st.begin()) << ' ';
		}
	}
}