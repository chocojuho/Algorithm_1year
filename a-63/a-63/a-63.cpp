#include <iostream>
#include <math.h>

using namespace std;
int n, x, y;
int cnt;
int ans = 0;
void z(int now,int y1,int x1) {
	if(now ==2) {
		if (x1 == x && y1 == y) {
			ans = cnt;
		}
		cnt++;
		if (x1+1 == x && y1 == y) {
			ans = cnt;
		}
		cnt++;
		if (x1 == x && y1+1 == y) {
			ans = cnt;
		}
		cnt++;
		if (x1+1 == x && y1+1 == y) {
			ans = cnt;
		}
		cnt++;
	}
	else {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				z(now / 2, y1 + i * (now / 2),x1 + j * (now / 2));
			}
		}
	}
}

int main()
{
	cin >> n >> y >> x;
	n = pow(2,n);
	z(n, 0, 0);
	cout << ans;
}