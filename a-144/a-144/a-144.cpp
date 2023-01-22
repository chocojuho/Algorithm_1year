#include <iostream>

using namespace std;
int x1, y1, x2, y2, x3, y3;
int main()
{
	cin << x1 << y1;
	cin << x2 << y2;
	cin << x3 << y3;
	if (x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1 <0) {
		cout << "-1";
	}
	else if (x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1 > 0) {
		cout << "1";
	}
	else {
		cout << "0";
	}

}