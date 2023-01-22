#include <iostream>
#include <cassert>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	cout << (a ^ b) <<' ';
	(a ^= b), (b ^= a), (a ^= b);
	cout << a << b;
}