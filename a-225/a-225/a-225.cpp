#include <iostream>
#include <string>

using namespace std;
int h, w;
string a[100010];
int arr[100010];
int main()
{
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> a[i];
        for (int j = 0; j < w;j++) {
            if (a[i][j] == '#') {
                arr[j]++;
            }
        }
    }
    for (int i = 0; i < w; i++) {
        cout << arr[i] << ' ';
    }
}