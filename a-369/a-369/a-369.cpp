#include <iostream>

using namespace std;

int num;
int cnt;

int main()
{
    cin >> num;
    num = 1000 - num;
    if (num >= 500) {
        cnt += num / 500;
        num %= 500;
    }
    if (num >= 100) {
        cnt += num / 100;
        num %= 100;
    }
    if (num >= 50) {
        cnt += num / 50;
        num %= 50;
    }
    if (num >= 10) {
        cnt += num / 10;
        num %= 10;
    }
    if (num >= 5) {
        cnt += num / 5;
        num %= 5;
    }
    
        cnt += num / 1;
    cout << cnt;
    return 0;
}
