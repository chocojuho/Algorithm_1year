#include <iostream>
#include <cmath>

using namespace std;
long long a, b, c, d,n;
int main()
{
	cin >> a >> b >> c >> d;
	double sum = c * c * 3.14159266;
	int i = 1;
	if (sum / d > a/b) {
		cout << "Whole pizza";
	}
	else {
		cout << "Slice of pizza";
	}
}