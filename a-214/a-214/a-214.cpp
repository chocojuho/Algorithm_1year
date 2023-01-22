#include <iostream>

using namespace std;

int n, q;
int arr[100010];
int prefix[100010];
int main()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	prefix[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}
	for (int i = 0; i < q; i++) {
		int a,b;
		cin >> a >> b;
		cout << prefix[b] - prefix[a- 1] << '\n';
	}
}