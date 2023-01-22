#include <iostream>

using ll = long long;
using namespace std;
string fibo[101];
ll sze;
int main()
{
	fibo[0] = "0";
	fibo[1] = "1";
	for (int i = 2; i <= 30; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		sze += sizeof(fibo[i]);
	}
	cout << sze << '\n' << fibo[10];
}