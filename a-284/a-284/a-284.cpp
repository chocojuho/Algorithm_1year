#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

ll n, q;
ll a[1000010];
map<ll, int> g;
map<ll, int> d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; i++) {
		d[a[i] - a[i - 1]]++;
		if (a[i] % a[i - 1] == 0) {
			g[a[i] / a[i - 1]]++;
		}
	}
	for (int i = 1; i <= q; i++) {
		ll x, v;
		cin >> x >> v;
		if (x > 1) {
			d[a[x] - a[x - 1]]--;
			if (a[x] % a[x - 1] == 0) {
				g[a[x] / a[x - 1]]--;
			}
			if (d[a[x] - a[x - 1]] == 0) {
				d.erase(d.find(a[x] - a[x - 1]));
			}
			if (g[a[x] / a[x - 1]] == 0 && a[x] % a[x - 1] == 0) {
				g.erase(g.find(a[x] / a[x - 1]));
			}
		}
		if (x < n) {
			d[a[x + 1] - a[x]]--;
			g[a[x + 1] / a[x]]--;
			if (d[a[x + 1] - a[x]] == 0) {
				d.erase(d.find(a[x + 1] - a[x]));
			}
			if (g[a[x + 1] / a[x]] == 0) {
				g.erase(g.find(a[x + 1] / a[x]));
			}
		}
		a[x] = v;
		if (x > 1) {
			d[a[x] - a[x - 1]]++;
			g[a[x] / a[x - 1]]++;
		}
		if (x < n) {
			d[a[x + 1] - a[x]]++;
			g[a[x + 1] / a[x]]++;
		}
		if (d.size() == 1 && (*d.begin()).first > 0) {
			cout << "+" << '\n';
		}
		else if (g.size() == 1 && (*g.begin()).first > 0) {
			cout << "*" << '\n';
		}
		else {
			cout << "?" << '\n';
		}
	}
}