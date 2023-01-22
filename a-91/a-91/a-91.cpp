#include <iostream>
#include <algorithm>

using namespace std;

long long a, b, c, e, f;
long long arr[1000];

int main()
{
	cin >> a >> b;
	if (a>=b) {
		cout << max((a + b) / 2, (a - b) / 2) << " " << min((a - b) / 2, (a + b) / 2);
	}
	else {
		cout << "-1";
	}
}