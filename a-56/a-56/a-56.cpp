#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <iostream>
#include <string>
using namespace std;
int cnt[4], use[4];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    string S;
    cin >> S;
    long long ans = 0;
    for (auto i : S) cnt[i - 'A']++;
    for (auto i : S) {
        if (i == 'A' && cnt[0] > 0 && cnt[1] > 0) {
            use[1]++, ans++;
            cnt[1]--;
            cnt[i - 'A']--;
        }
        else if (i == 'B' && cnt[1] > 0 && cnt[2] > 0) {
            use[2]++, ans++;
            cnt[2]--;
            cnt[i - 'A']--;
        }
        else {
            if (use[i - 'A'] > 0) {
                use[i - 'A']--;
            }
            else cnt[i - 'A']--;
        }
    }
    cout << ans;
}