#include <iostream>
#include <string>

using namespace std;
int messilen[10000];
long long mk;

void messi(int n,int m) {
	if (m > 5 && m <= 13) {
		if (m == 6) {
			cout << "Messi Messi Gimossi";
		}
		else {
			string a = "Messi Gimossi";
			cout << a[m-1];
		}
		return;
	}
	else if (m <= 5) {
		string a = "Messi";
		cout << a[m-1];
		return;
	}
	if (m>=messilen[n-1]) {
		return messi(n - 2, m - messilen[n - 1]);
	}
	else {
		return messi(n-1,m);
	}
}

int main()
{
	cin >> mk;
	messilen[0] = 5;
	messilen[1] = 13;
	int i = 2;
	for (i = 2; messilen[i-1] < mk; i++) {
		messilen[i] = messilen[i - 1]+1+ messilen[i - 2];
	}
	messi(i, mk);
}
