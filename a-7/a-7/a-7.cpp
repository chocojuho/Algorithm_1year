#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
int mover[3] = { -1,1,2 };
int a, b;
int dist[100010];
int bfs(int now) {
	queue<int> qu;
	qu.push(now);
	dist[now] = 0;
	while (!qu.empty()) {
		int cur = qu.front();
		if (cur == b) {
			return dist[b];
		}
		qu.pop();
		for (int i = 0; i < 3;i++) {
			if (i == 2  && cur * mover[2] <= 100000 && dist[cur * mover[2]] > dist[cur]) {
				qu.push(cur*mover[2]);
				dist[cur * mover[2]] = dist[cur];
			}
			else {
				if (cur + mover[i] >= 0 && cur + mover[i] <= 100000 && dist[cur + mover[i]] > dist[cur]+1) {
					qu.push( cur + mover[i]);
					dist[cur + mover[i]] = dist[cur] + 1;
				}
			}
		}
	}
}

int main()
{
	memset(dist,999999999, sizeof dist);
	cin >> a >> b;
	cout << bfs(a);
}