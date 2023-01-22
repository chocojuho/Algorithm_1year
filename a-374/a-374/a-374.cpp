#include <iostream>

using namespace std;

int main()
{
	long long before = 0;
	long long now = 1;
	long long sum = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100 - i; j++) {
			cout << ' ';
		}
		sum = before + now;
		cout << before + now << ' ';
		before = now;
		now = sum;
		if (i % 5 == 0) {
			cout << '\n';
		}
	}
}