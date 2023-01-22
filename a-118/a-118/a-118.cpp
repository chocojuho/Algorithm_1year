#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <map>
#define inf 500000000000
using namespace std;
long long n, m;
map<long long, long long> mdistance[1000000];
long long st, ed;
long long ans = 500000000000;
vector<pair<long long, long long>> vertex[1000000];

void daijestar() {
	priority_queue < pair<long long, pair<long long, long long>>, vector < pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;
	mdistance[st][0] = 0;
	pq.push({ 0,{st,0} });

	while (!pq.empty()) {
		long long current = pq.top().second.first;
		long long dist = pq.top().first;
		long long val = pq.top().second.second;
		pq.pop();
		if (current == ed) {
			ans = min(ans, dist);
		}
		if (dist > mdistance[current][val]) {
			continue;
		}
		for (long long i = 0; i < vertex[current].size(); i++) {
			long long nextcurrent = vertex[current][i].second;
			long long nextdist = vertex[current][i].first;
			if (nextdist + dist < mdistance[nextcurrent][nextdist] && nextdist >  val) {
				mdistance[nextcurrent][nextdist] = nextdist + val;
				pq.push({ dist + nextdist,{nextcurrent,nextdist} });
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
	for (long long i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		vertex[a].push_back({ c,b });
		vertex[b].push_back({ c,a });
		mdistance[a][c] = 500000000000;
		mdistance[b][c] = 500000000000;
	}
	cin >> st >> ed;
	daijestar();
	if (ans == 500000000000) {
		cout << "DIGESTA";
	}
	else {
		cout << ans;
	}

}

