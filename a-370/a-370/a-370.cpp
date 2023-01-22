#include <iostream>

using namespace std;

long long a, b, v;

int main()
{
	cin >> a >> b >> v;
	if (((v / (a - b)) - b) * (a - b) + b >= v) {
		int k = (((v / (a - b)) - b) < 1) ? 1 : (v / (a - b)) - b;
		cout << k;
	}
	else {
		cout << v / (a - b)+!(v % (a - b) == 0);
	}
}