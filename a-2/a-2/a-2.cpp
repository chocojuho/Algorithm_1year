#include <iostream>

using namespace std;

int a, b, c , now;
int cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    if (c==0) {
        cout << 0;
        return 0;
    }
    else if (a > c) {
        cout << 1;
        return 0;
    }
    if ((c-a)%(a-b)==0) {
        cout << (c - a) / (a - b) + 1;
    }
    else {
        cout << c / (a - b) + 1;
    }
    
}
