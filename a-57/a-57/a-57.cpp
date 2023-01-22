#include <iostream>
#include <string.h>

char a[500000];
int cnt[4];
int use[4];

using namespace std;

int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;
    int l = strlen(a);
    for (int i = 0; i < l; i++) {
        cnt[a[i] - 'A']++;
    }
    for (int i = 0; i < l; i++) {
        if (a[i] == 'A' && cnt[0] > 0 && cnt[1] > 0) {
            use[1]++;
            ans++;
            cnt[1]--;
            cnt[i - 'A']--;
        }
        else if (a[i] == 'B' && cnt[1] > 0 && cnt[2] > 0) {
            use[2]++;
            ans++;
            cnt[2]--;
            cnt[i - 'A']--;
        }
        else {
            if (use[i - 'A'] > 0) {
                use[i - 'A']--;
            }
            else {
                cnt[i - 'A']--;
            }
        }
    }
    cout << ans;
}