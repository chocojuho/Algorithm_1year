#include <iostream>
using namespace std;

int main() {
    int n, dp[1001];
    cin >> n;
    dp[2] = 3;
    dp[4] = 11;
    for (int i = 6; i <= n; i += 2) {
        dp[i] = (dp[i-4]*dp[i - 2]  + 8);
    }
    cout << dp[n] << '\n';
    return 0;
}