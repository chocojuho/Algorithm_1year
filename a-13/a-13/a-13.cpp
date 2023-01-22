// a-13.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

int a;

int main()
{
    cin >> a;
    if (a % 7 == 2 || a % 7 == 0) {
        cout << "CY";
    }
    else {
        cout << "SK";
    }
}