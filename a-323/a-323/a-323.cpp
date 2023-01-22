#include <iostream>

using ll = long long;
using namespace std;

int t;

int main()
{
	cin >> t;
	while (t--) {
		ll n;
		ll mmx = 0;
		ll mmn = 99999999;
		ll mmnx;
		bool flag = false;
		ll arr[100010] = { 0, };
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			mmn = min(arr[i], mmn);
			mmx = max(arr[i], mmx);
		}
		mmnx = mmx - mmn;
		for (int k = 0; k < 10000; k++) {
			ll nx = 0;
			ll ny = 0;
			ll oxr = 0;
			ll orr = 0;
			for (int i = 0; i < n; i++) {
				ll x = arr[i];
				for (int j = i + 1; j < n; j++) {
					ll y = arr[j];
					if ((x ^ y) != 0) {
						if ((x | y) - (x & y) > mmnx) {
							mmx = (x | y);
							mmn = (x & y);
							nx = i;
							ny = j;
							oxr = (x & y);
							orr = (x | y);
						}
						else if (mmx - (x & y) > mmnx) {
							mmn = (x & y);
							nx = i;
							ny = j;
							oxr = (x & y);
							orr = (x | y);
						}
						else if ((x | y) - mmn > mmnx) {
							mmx = (x | y);
							nx = i;
							ny = j;
							oxr = (x & y);
							orr = (x | y);
						}
						mmnx = max(mmx - mmn, mmnx);
						flag = true;
					}
				}
			}
			if (flag) {
				arr[nx] = oxr;
				arr[ny] = orr;
			}
			for (int i = 0; i < n; i++) {
				mmn = min(arr[i], mmn);
				mmx = max(arr[i], mmx);
			}
			mmnx = max(mmx - mmn,mmnx);
		}
		cout << mmnx << '\n';
	}
}