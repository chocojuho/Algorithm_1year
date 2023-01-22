#include <iostream>

using namespace std;
int coin[110];
int dp[10010];
int n, k;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            dp[i + coin[j]] = dp[i] + dp[i + coin[j]];
        }
    }
}