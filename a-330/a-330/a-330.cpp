#include <iostream>

using namespace std;
int n;
int main()
{
    cin >> n;
    cout << (n & -n) << '\n';
    int c = n;
    while (1) {
        if (c == 0) {
            break;
        }
        cout << c % 2;
        c /= 2;
    }
    c = n;
    cout << '\n';
    while (1) {
        if (c == 0) {
            break;
        }
        cout << !(c % 2);
        c /= 2;
    }
}