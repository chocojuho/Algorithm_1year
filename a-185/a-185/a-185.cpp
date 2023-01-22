// a-185.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

double e;

int main()
{
    for (long long a = 1; a < 1000000000000; a++) {
        printf("%.1000lf\n", pow(1 + 1 / (double)a, (double)a));
    }
}