#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x;
vector<pair<int,int>> vc[100010];
int dest[100010];

void bfs(int start){
	priority_queue<pair<int,int>> pq;
	pq.push({ start ,0});
	while (!pq.empty()) {
		int now = pq.top().first;
		int val = pq.top().second;
		if (dest[now] > val) {
			continue;
		}
		for (auto nx : vc[now]) {
			nx.first
		}
	}
}

int main()
{
	cin >> n >> m >> x;
	for (int i = 0; i < 100010; i++) {
		dest[i] = -99999999;
	}
	for (int i = 0; i < n; i++) {
		int st, ed, val;
		cin >> st >> ed >> val;
		vc[st].push_back({ ed,val });
		vc[ed].push_back({ st,val });
	}
	bfs(x);
}