#include <iostream>

using ll = long long;
using namespace std;

ll n, s;
ll arr[1000010];
ll mmx2;
ll mmx;
int main()
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	ll j = s;
	ll sum = 0;
	while (j >= 1 && sum >= 0) {
		sum += arr[j];
		mmx = max(sum, mmx);
		j--;
	}
	j = s;
	sum = mmx;
	while (j <= n && sum >= 0) {
		sum += arr[j];
		mmx = max(sum, mmx);
		j++;
	}
	ll j = s;
	ll sum = 0;
	while (j >= 1 && sum >= 0) {
		sum += arr[j];
		mmx = max(sum, mmx);
		j--;
	}
	j = s;
	sum = mmx;
	while (j <= n && sum >= 0) {
		sum += arr[j];
		mmx = max(sum, mmx);
		j++;
	}
	cout << mmx;
}
