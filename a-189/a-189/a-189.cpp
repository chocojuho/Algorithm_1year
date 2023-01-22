#include <bits/stdc++.h>
using namespace std;
#define ld long double
int main() {
    int N, ans = 0, cnt = 0;
    ld X, S[100001];
    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        long long c;
        scanf("%d", &c);
        if (c == X) {
            ans++;
            continue;
        }
        scanf(" %Lf", &S[i]);
    } 
    sort(S + 1, S + N + 1);
    int left = 1, right = N;
    while (left < right) {
        if (S[left] + S[right] >= X / 2) {
            cnt++;
            right--;
        }
        left++;
    }
    ans += (N - ans - cnt * 2) / 3;
    cout << ans;
    return 0;
}