#include <iostream>

using namespace std;

int n;
int arr[1000][1000];

int rotate(int dir) {
	int temp[1000][1000];
	for (int i = 0; i < dir; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				temp[j][k] = arr[k][n-j-1];
			}
		}
		for (int i = 0; i < n; i++) {
			int ptr = 0;
			int temp[10001] = { 0, };
			for (int j = 0; j < n; j++) {
				if (!arr[i][j]) {
					continue;
				}
				if (!temp[ptr]) {
					temp[ptr] = arr[i][j];
				}
				if (temp[ptr] == arr[i][j]) {
					temp[ptr++] *= 2;
				}
				else {
					temp[++ptr] = arr[i][j];
				}
			}
			for (int j = 0; j < n; i++) {
				arr[i][j] = temp[j];
			}
		}
	}
}


int mmx = 0;
void go(int depth,int dir) {
	if (depth == 5) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		mmx = max(mmx, rotate(i));
		go(depth + 1,i);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	go(0,0);
}