#include <iostream>
#include <string>

using namespace std;

long long cnt;
int n;
int check = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    // printf("ABBA: %d\n", isPalindrome("ABBA")); // 1
    //printf("ABC: %d\n", isPalindrome("ABC"));   // 0
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length() / 2; j++) {
            if (str[j] != str[str.length() - 1 - j]) {
                cnt++;
                check = 0;
                break;
            }
            cnt++;
        }
        if (check == 0) {
            cout << check << " " << cnt << '\n';
        }
        else {
            cout << check << " " << str.length()/2+1 << '\n';
        }
        
      


        cnt = 0;
    }
}