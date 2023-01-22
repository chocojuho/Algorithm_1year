#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int a, b;
    cin >> a;
    for (int i = 0; i < a; i++) {
        string s;
        getline(cin, s);
        cout << i+1 << ". " << s << '\n';
    }
    return 0;
}