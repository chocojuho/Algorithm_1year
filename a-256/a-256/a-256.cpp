#define x first
#define y second
#include <iostream>
#include <math.h>

using namespace std;
using point = pair<double, double>;

int n;

double dist(point a, point b) {
	return sqrt((b.x - a.x)* (b.x - a.x) + (b.y - a.y)* (b.y - a.y));
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		point p1, p2;
		double r1, r2;
		cin >> p1.x >> p1.y;
		cin >> p2.x >> p2.y;
		cin >> r1 >> r2;
		auto getter = dist(p1, p2);
		if (r1 == r2 && getter == (double)0) {
			cout << -1 << '\n';
		}
		else if (getter == (double)r1+r2 || getter == (double)r1 - r2) {
			cout << 1 << '\n';
		}else if (getter > (double)(r1-r2)  && getter < (double)r1 + r2) {
			cout << 0 << '\n';
		}
		else if (getter > (double)r1 + r2 || getter < (double)r1 - r2) {
			cout << 2 << '\n';
		}
	}

}