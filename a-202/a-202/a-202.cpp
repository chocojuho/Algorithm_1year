// a-202.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int t;
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		int sum = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			sum += a;
		}
		if (sum % n == 0) {
			cout << "Alice" << '\n';
		}
		else {
			cout << "Bob" << '\n';
		}
	}
}