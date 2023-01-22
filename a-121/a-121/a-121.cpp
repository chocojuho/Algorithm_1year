#include <iostream>

using namespace std;
int n, m;
long long arr[100000];
long long tree[1<<22];

pair<long long,long long> maketree(int start,int end,int node) {

}
pair<long long, long long> update() {

}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	maketree();
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		update(a,b);
	}
}