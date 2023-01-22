#include <iostream>

using namespace std;
int cnt1, cnt2;
int n;
int f[1000];
int zeroone[1000][2];
int fibonacci(int now) {
    if (f[now]) {
        cnt1 += zeroone[now][0];
        cnt2 += zeroone[now][1];
        return f[now];
    }
    if (now == 0) {
        zeroone[0][0] = 1;
        return 0;
    }
    else if (now == 1) {
        zeroone[1][1] = 1;
        return 1;
    }
    f[now] = fibonacci(now - 1) + fibonacci(now - 2);
    zeroone[now][0] = zeroone[now - 1][0] + zeroone[now-2][0];
    zeroone[now][1] = zeroone[now - 1][1] + zeroone[now - 2][1];
    return f[now];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cnt1 = 0;
        cnt2 = 0;
        int k;
        cin >> k;
        fibonacci(k);
        cout << cnt1 <<" " << cnt2 << '\n';
    }
}