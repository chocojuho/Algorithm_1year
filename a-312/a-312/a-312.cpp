#include <iostream>
#include <queue>

using ll = long long;
using namespace std;

ll n, s;
ll arra[1000100];
ll arrb[1000100];
ll sum[1000100];
ll tree[1 << 22];

ll maketree(ll start, ll end, ll node) {
	if (start == end) {
		return tree[node] = arra[start];
	}
	ll mid = (start + end) / 2;
	return tree[node] = min(maketree(start, mid, node * 2) , maketree(mid + 1, end, node * 2 + 1));
}
ll query(ll start, ll end, ll left, ll right, ll node) {
	if (right < start || left > end) {
		return 100000000000010;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	ll mid = (start + end) / 2;
	return min(query(start, mid, left, right, node * 2), query(mid + 1, end, left, right, node * 2 + 1));
}
int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arra[i];
	}
	for (int i = n; i < 1000100; i++) {
		arra[i] = 100000000000010;
	}
	for (int j = 1; j <= n; j++) {
		cin >> arrb[j];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arrb[i];
	}
	//ll sum = 0;
	ll i = 0;
	ll j = 0;
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (sum[j + 1] - sum[i] + query(0, n - 1, i, j, 1) <= s) {
				cnt++;
			}
		}
	}
	/*while (j <= n) {
		if (sum[j + 1] - sum[i] + query(0, n - 1, i, j, 1) <= s) {
			cnt++;
			j++;
			cout << i << ' ' << j << '\n';
			while (sum[j + 1] - sum[i] + query(0, n - 1, i, j, 1) <= s && j<=n) {
				j++;
				cnt++;
				cout << i << ' ' << j << '\n';
			}
		}
		else {
			i++;
		}
	}*/
	cout << cnt;
}