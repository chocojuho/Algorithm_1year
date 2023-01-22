#include <iostream>

using ll = long long;
using namespace std;

ll b, c,a[3];

int main()
{
	cin >> b >> c >> a[0] >> a[1];
	ll i = 0;
	while (1) {
		if (i == 100000000000) {
			printf("%.9lf\n", (double)a[(i % 3 + 2) % 3] / a[(i % 3 + 1) % 3]);
			break;
		}
		if (i % 3 == 0) {
			a[2] = b * a[1] + c*a[0];
		}
		else if (i % 3 == 1) {
			a[0] = b * a[2] + c * a[1];
		}
		else {
			a[1] = b * a[0] + c * a[2];
		}
		i++;
	}
}