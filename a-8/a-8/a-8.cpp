#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
int mmx=0;
char str1[1010];
char str2[1010];
int lcs[1010][1010];

using namespace std;

int main()
{
	cin >> str1 >> str2;
	for (int i = 0; i < strlen(str1); i++) {
		for (int j = 0; j < strlen(str2); j++) {
			if (i == 0 || j == 0) {
					lcs[i][j] = 1;
			}
			else if (str1[i] == str2[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}
	for (int i = 0; i < strlen(str1); i++) {
		for (int j = 0; j < strlen(str2); j++) {
			mmx = max(mmx, lcs[i][j]);
		}
	}
	cout << mmx;
}