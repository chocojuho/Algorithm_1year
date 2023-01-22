#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int n;
int arr[2000100];

int all;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n;i++) {
		int checker[2000000] = {0, };
		int k = i+1;
		checker[arr[i]]++;
		while (1) {
			if (checker[arr[k]] != 0 || k>=n) {
				k--;
				break;
			}
			checker[arr[k]]++;
			k++;
		}
		int szze = k - i+1;
		if (k == i) {
			szze = 1;
		}
		all = max(all, szze);
	}
	cout << all;
}