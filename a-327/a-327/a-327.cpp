#include <iostream>

using ll = long long;
using namespace std;

ll n;
ll arr[1000010];
ll tree[1 << 22];
ll pre[1000010];
ll mmx = 0;

ll maketree(ll start, ll end, ll node) {
	if (start == end) {
		return tree[node] = start;
	}
	ll mid = (start + end) / 2;
	ll fd = maketree(start, mid, node * 2);
	ll sd = maketree(mid + 1, end, node * 2 + 1);
	return tree[node] = (arr[fd] < arr[sd]) ? fd: sd;
}

ll query(ll start, ll end, ll left, ll right, ll node) {
	if (end < left || right < start) {
		return 1000008;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	ll mid = (start + end) / 2;
	ll fd = query(start, mid, left, right, node * 2);
	ll sd = query(mid+1, end, left, right, node * 2+1);
	return (arr[fd] < arr[sd]) ? fd : sd;
}

void DnC(ll start, ll end) {
	if (start > end) {
		return;
	}
	ll idx = query(0,n-1,start,end,1);
	mmx = max((pre[end + 1] - pre[start]) * arr[idx], mmx);
	DnC(start, idx-1);
	DnC(idx + 1, end);
}

int main()
{
	cin >> n;
	arr[1000008] = 99999999;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	maketree(0,n-1,1);
	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + arr[i-1];
	}
	DnC(0, n - 1);
	cout << mmx;
}