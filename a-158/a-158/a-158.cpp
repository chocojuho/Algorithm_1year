#include <iostream>
#include <vector>

using namespace std;

vector<int> conn[10000];
int parent[10000];
int visit[10000];
int n;
int del;
int cnt;
void dfs(int st) {
	visit[st] = 1;
	for (int i = 0; i < conn[st].size(); i++) {
		if (visit[conn[st][i]]!=1) {
			dfs(conn[st][i]);
			cnt++;
		}
	}
}

int st;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == -1) {
			st = a;
			parent[i] = -1;
			continue;
		}
		conn[a].push_back(i);
		parent[i] = a;
	}
	cin >> del;
	dfs(del);
	cout << cnt;
}