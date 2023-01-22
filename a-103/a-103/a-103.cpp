#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
long long sum;
long long tree[1 << 22];
vector<pair<long long,long long>> arr;

void maketree(int start, int end, int node,int idx) {
	if (start == end) {
		tree[node] = 1;
		return;

	}
	if(idx<=(start+end)/2)maketree(start, (start + end) / 2, node * 2,idx);
	else maketree((start + end) / 2 + 1, end, node * 2 + 1,idx);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

long long query(int start, int end, int left, int right, int node) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}return query(start, (start + end) / 2, left, right, node * 2) + query((start + end) / 2 + 1, end, left, right, node * 2 + 1);

}
int main()
{
	cin >> n;
	arr.push_back({ -1000000001,0 });
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		arr.push_back({ a,i });
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i <= n; i++) {
		sum += query(1, n, arr[i].second + 1, n, 1);
		maketree(1,n,1,arr[i].second);
	}
	cout << sum;
}