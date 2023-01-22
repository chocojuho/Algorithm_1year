#include <iostream>

using ll = long long;
using namespace std;

int n, m, k;
int tree[2500][2500];
int arr[2500][2500];

void updateY(int i, int idxy, int start, int end, int idxx,int chk) {
	if (idxy < start || end < idxy) {
		return;
	}
	if (start == end) {
		updateX(i,1,0,500,idxx,chk);
	}
	ll mid = (start + end) / 2;
	updateY(i * 2, idxy, start, mid, idxx,chk);
	updateY(i * 2 + 1, idxy, mid + 1, end, idxx,chk);
	updateX(i,1,0,500,idxx,chk);
}

void updateX(int i, int j, int start, int end, int idxx,int chk) {
	if (idxx < start || end < idxx) {
		return;
	}
	if (start == end) {
		if (chk == -1) {
			tree[i][j] -= 1;
			if (tree[i][j] < 0) {
				tree[i][j] = 0;
			}
		}
		else {
			tree[i][j] += 1;
		}
		return;
	}
	ll mid = (start + end) / 2;
	updateX(i, j * 2, start, mid, idxx,chk);
	updateX(i, j * 2 + 1, mid + 1, end, idxx,chk);
	tree[i][j] = tree[i][j * 2] + tree[i][j * 2 + 1];
}

void queryY(int i, int j, int start, int end, int lefty, int righty) {
	if (end < lefty || righty < start) {
		return;
	}
	if (start == end) {

	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		short check;
		cin >> check;
		if(check == 1){
			int x, y, r;
			cin >> x >> y >> r;
		}
		else if(check == 2) {
			cin >> x >> y;
		}
		else {

		}
	}
}