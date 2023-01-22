#include <iostream>

using namespace std;

int n;
char str2[5010];
char str[5010];
int main()
{
	cin >> n;
	cin >> str2;
	for (int i = 1; i <= n; i++) {
		str[i] = str2[i - 1];
	}
	for (int i=1; i <= n - 1; i++) {
		int mmx = 0;
		for (int l = n-i; l >=0; l--) {
			int flag = 0;
			for (int k = 0; k <= l; k++) {
				if (str[k] == str[k + i]) {
					flag = 1;
					break;
				}
			}
			if (flag) {
				continue;
			}
			mmx = l;
			break;
		}
		cout << mmx << '\n';
	}
}