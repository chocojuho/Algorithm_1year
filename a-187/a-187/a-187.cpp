#include <iostream>
#include <math.h>

using namespace std;
long long a, b, c;
long long l, r;
long double e = 3.1415926535897932384626433832795028841971693993751058209749;


long double sin(long double x) {
	x  -= (x / (e * 2));
	long double n = 1;
	long double cur = x;
	long double res = x;
	while (abs(cur) >= pow(10, -60)) {
		n += 2;
		long double fac = n * (n - 1);
		cur = (cur * x * x) / fac * -1;
		res += cur;
	}
	return res;
}

long double f(long double x) {
	return a * x + b * sin(x) - c;
}

int main()
{
	cin >> a >> b >> c;
	l = 0, r = pow(10, 6);
	long long mid = (l + r) / 2;
	while (abs(r - l) >= pow(10, -60)) {
		if (f(mid) > 0) {
			r = mid;
		}
		else {
			l = mid;
		}
		mid = (l + r) / 2;
	}
	printf("%.6lf", round(mid*100000)/ 100000.0);
}
