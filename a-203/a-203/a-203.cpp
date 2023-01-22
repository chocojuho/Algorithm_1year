#include <iostream>

using namespace std;

int n;
float arr[100010];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int i;
	for (i = 1; i < 100010; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (int(int(i * arr[j]) / float(i) * 1000) / 1000.0 == arr[j] || int((int(i * arr[j]) + 1)/float(i)*1000)/1000.0 == arr[j]) {
				cnt++;
			}
		}
		if (cnt == n) {
			break;
		}
	}
	cout << i;
}