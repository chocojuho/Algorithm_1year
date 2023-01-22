#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

vector<pair<int, int>> should;

int visited[3010][3010];
int parent[2000000];
int dx[4] = {-1,1,0,0};
int dy[4] = { 0,0,-1,1 };
// CHECKED
typedef struct hi{
	int x;
	int y;
	int cnt;
}h;
// CHECKED
int find(int now) {
	if (now == parent[now]) {
		return now;
	}
	return parent[now] = find(parent[now]);
}
// CHECKED
void merge(int st,int ed) {
	int stp = find(st);
	int edp = find(ed);
		if (stp > edp) {
			parent[stp] = edp;
		}
		else {
			parent[edp] = stp;
		}
}
// CHECKED
int checker() {
	int must = find(0);
	for (int i = 1; i < should.size(); i++) {
		if (must != find(i)) {
			return 1;
		}
	}
	return 0;
}
// CHECKED
int sameOrNot(int st, int ed) {
	int stp = find(st);
	int edp = find(ed);
	return stp == edp;
}

int bfs() {
	queue<h> qu;
	for (int i = 0; i < should.size(); i++) {
		qu.push({ should[i].first,should[i].second,0 });
		visited[should[i].first][should[i].second] = i;
	}
	for (int i = 0; i < should.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int nx = should[i].first + dx[j];
			int ny = should[i].second + dy[j];
			if (nx > 0 && nx <= n && ny > 0 && ny <=n &&visited[nx][ny] != -1 && !sameOrNot(visited[should[i].first][should[i].second], visited[nx][ny])) {
				merge(visited[should[i].first][should[i].second], visited[nx][ny]);
			}
		}
	}
	while (!qu.empty()) {
		int x = qu.front().x;
		int y = qu.front().y;
		int cnt = qu.front().cnt;
		qu.pop();
		if (!checker()) {
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx>0 && nx<=n && ny>0 &&ny<=n &&visited[nx][ny] == -1) {	
				qu.push({ nx,ny,cnt + 1 });
				visited[nx][ny] = visited[x][y];
			}
			else if (!sameOrNot(visited[nx][ny], visited[x][y])) {
				merge(visited[x][y], visited[nx][ny]);
			}
		}
	}
}
// CHECKED
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 2000000; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= 3000; i++) {
		for (int j = 1; j <= 3000; j++) {
			visited[i][j] = -1;
		}
	}
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		should.push_back({a,b});
	}
	cout << bfs();
}