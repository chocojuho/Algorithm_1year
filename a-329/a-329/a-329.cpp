#include <iostream>

using ll = long long;
using namespace std;

ll n;

struct Node {
	Node* l, * r;
	ll v;
	Node() {
		l = r = NULL;
		v = 0;
	}
}*root;

void update(Node* node, ll start, ll end, ll idx,ll var) {
	if (start == end) {
		node->v = var;
		return;
	}
	ll mid = (start + end) / 2;
	if (idx <= mid) {
		if (!node->l) node->l = new Node();
		update(node->l, start, mid, idx, var);
	}
	else {
		if (!node->r) node->r = new Node();
		update(node->r, mid + 1, end, idx, var);
	}
	ll t1 = node->l ? node->l->v : 0;
	ll t2 = node->r ? node->r->v : 0;
	node->v = t1 + t2;
}

ll query(Node* node, ll start, ll end, ll left, ll right) {
	if (!node) {
		return 0;
	}
	if (end < left || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return node->v;
	}
	ll mid = (start + end) / 2;
	return query(node->l, start, mid, left, right) + query(node->r, mid + 1, end, left, right);
}

int main()
{
	cin >> n;
	root = new Node();
	for (int i = 0; i < n; i++) {
		ll q;
		cin >> q;
		if (q == 0) {
			ll start, end;
			cin >> start >> end;
			cout << query(root, 1, 100000, start,end ) << '\n';
		}
		else {
			ll idx;
			cin >> idx;
			update(root, 1, 100000, idx, 1);
		}
	}
}