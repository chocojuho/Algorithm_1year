#include <iostream>
#include <vector>

using namespace std;

vector<int> conn[10000];
int n;
int del;
int cnt;
int cnt2;
int cnt3;
void dfs(int st) {
	if (conn[st].size() == 0) {
		cnt++;
	}
	for (int i = 0; i < conn[st].size(); i++) {
		if (conn[st][i] == del) {
			if (conn[st].size() == 1) {
				cnt++;
			}
			continue;
		}
		dfs(conn[st][i]);
	}
}

int st2;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == -1) {
			st2 = i;
			continue;
		}
		conn[a].push_back(i);
	}
	cin >> del;
	if (del == st2) {
		cout << 0;
	}
	else {
		dfs(st2);
		cout <<  cnt;
	}
}