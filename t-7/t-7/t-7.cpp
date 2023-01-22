#include <iostream>

using namespace std;

long long n, m;

int main()
{
    cin >> n >> m;
    if (n == m) {
        cout << 1;
    }
    else{
         cout << n / m + !(n%m == 0);
    }
}