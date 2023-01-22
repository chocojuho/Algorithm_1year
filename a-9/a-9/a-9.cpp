#include <iostream>

using namespace std;
int n, m;
int backtracking(int now) {
	if (now == 0) {
			return 0;
	}
	for (int i = 1; i <= n;i++) {
		if (i == now) {
			continue;
		}
		backtracking(--now);
		cout << i << " ";
	}
	cout << "\n";
}

int main()
{
	
	cin >> n >> m;
	backtracking(m);
}