#include <iostream>
#include <string>

using namespace std;

char str[10000];

int arr[30];
int a;
int cnt1, cnt2, cnt3;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> str[i];
	}
	if (a == 1) {
		cout << str[0];
	}
	else {
		cout << str;
		cout << str;
	}
	
}