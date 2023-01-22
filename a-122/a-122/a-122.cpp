#include <iostream>

using namespace std;

int n;
int arr[300010];
int cnt;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        if (abs(arr[i] - arr[i - 1]) == 1) {
            cnt++;
        }
    }
    if ((cnt == 0 || cnt % 2 == 1) && cnt != n-1) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
}