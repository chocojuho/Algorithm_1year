// a-314.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
int t;
int main()
{
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int arr[100010010] = {0, };
		int 몫 = n / k;
		int 나머지 = n % k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
	}
	
}