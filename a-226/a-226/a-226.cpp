#include <iostream>

using namespace std;

long long n;
long long arr[9000010];
long long query[9000010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (long long i = 1; i <= n; i++) {
		query[2 * i] = query[arr[i-1]] + 1;
		query[2 * i + 1] = query[arr[i-1]] + 1;
	}
	cout << 0 << '\n';
	for (long long i = 0; i < n; i++) {
		cout << query[arr[i]]+1<<'\n';
		cout << query[arr[i]]+1 <<'\n';
	}
}