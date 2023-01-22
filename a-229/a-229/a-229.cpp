#include <iostream>
#include <queue>

using namespace std;

int visited[1010][1010];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n, m;
int d;
int flag;
string a[1010];
string b[1010];
queue<pair<pair<int,int>,int>> qu;

void bfs() {
	while (!qu.empty()) {
		int x = qu.front().first.first;
		int y = qu.front().first.second;
		int cnt = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && nx < n && ny >=0 && ny <m && b[nx][ny] == 'O' && visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				qu.push({ { nx,ny }, cnt+1});
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'O') {
				qu.push({ { i,j } ,0});
				visited[i][j] = 1;
			}
		}
	}
	cin >> d;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'O') {
				if (b[i][j] != 'O') {
					flag = 1;
					break;
				}
			}
		}
	}
	bfs();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j]=='O') {
				if (visited[i][j] != 1) {
					flag = 1;
					break;
				}
			}
		}
	}
	if (flag != 1) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}