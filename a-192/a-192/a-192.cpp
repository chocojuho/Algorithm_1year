#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int t;


int main()
{
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		int mmx = -300000010;
		int mmn = -300000010;
		double ans;
		int a[100010] = {0, };
		int b[100010] = {0, };
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> b[j];
		}
		for (int j = 0; j < n; j++) {
			mmn = max(a[j] + b[j], mmn);
			mmx = max(b[j] - a[j], mmx);
		}
		printf("%.6lf\n", (mmn - mmx) / 2.0);
	}
}
