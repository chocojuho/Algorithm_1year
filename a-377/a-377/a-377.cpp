#include <iostream>

using namespace std;

long long a, b;

int main()
{
	cin >> a >> b;
	if (a * 2 == b || a * 2 + 1 == b) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}