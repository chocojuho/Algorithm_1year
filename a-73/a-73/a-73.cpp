#include <iostream>

using namespace std;

//idt
int idt[1 << 18], n,m, base;

void update(int a,int b) {
    idt[a] = b;
    a >>= 1;
    while (a) {
        idt[a] = idt[2 * a] + idt[2 * a + 1];
        a >>= 1;
    }
}
int lg_sum(int a, int b) {
    int sum = 0;
    while (a < b) {
        if (a % 2 == 1) {
            sum += idt[a];
            a++;
        }
        if (b % 2 == 0) {
            sum += idt[b];
            b--;
        }
        a >>= 1, b >>= 1;
    }
    if (a == b) {
        sum += idt[a];
    }
    return sum;
}
int main()
{
    cin >> n >> m;
    // maketree
    for (base = 1; base < n; base * 2)
    for (int i = base; i < n + base; i++) {
            cin >> idt[i];
    }
    for (int i = base - 1; i > 0; i--) {
        idt[i] = idt[i * 2] + idt[i * 2 + 1];
    }
    //update query 1
    for (int i = 0; i < m; i++) {
        int check;
        cin >> check;
        if (check == 1) {
            int a, b;
            cin >> a >> b;
            update(base + a - 1, b);
        }
        else if (check == 2) {
            int a, b;
            cin >> a >> b;
            lg_sum(base + a - 1, base + b - 1);
        }
    }
    for (int i = 1; i <= base + n; i++) {
        cout << idt[i];
    }
    
}
