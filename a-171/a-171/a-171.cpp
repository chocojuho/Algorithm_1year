#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector<int> vertex[100010];
vector<int> chain[100010];
pair<int,pair<int, int>> edge[100010];
int parent[100010];
int sz[100010];
int depth[100010];
int chain_number[100010];
int chain_index[100010];
int in[100010];
int out[100010];
int base = 1;
int pv;
/////////////////////
struct Seg{
	int tree[1 << 22];
	int sz = 1 << 21;

	void update(int x,int v) {
		int st = edge[x].second.first;
		int ed = edge[x].second.second;
		edge[x].first = v;
		// 어느 값이 위에 있는지 확인 
		if (parent[ed] ^ st) {
			swap(st, ed);
		}
		int idx = base + in[ed];
		tree[idx] = edge[x].first;
		while (idx >>= 1) {
			tree[idx] = max(tree[idx << 1] , tree[idx << 1 | 1]);
		}
	}
	int query(int l, int r) {
		l |= sz;
		r |= sz;
		int ans = 0;
		while (l <= r) {
			if (l & 1) {
				ans = max(tree[l++],ans);
			}
			if (~r & 1) {
				ans += max(tree[r--],ans);
			}
			l >>= 1;
			r >>= 1;
		}
		return ans;
	}
}seg;
/////////////////////
void dfs(int now,int up) {
	parent[now] = up;
	sz[now] = 1;
	depth[now] = depth[up] + 1;
	for (auto x : vertex[now]) {
		if (x != up) {
			dfs(x, now);
			sz[now] += sz[x];
		}
	}
}

// 오일러 테크닉 투어 (인덱스 번호 부여)
void dfs2(int now, int up) {
	in[now] = pv++;
	for (auto x : vertex[now]) {
		if (x != up) {
			dfs2(x,now);
		}
	}
	out[now] = pv;
}

//체인생성
void hld(int now, int up, int node_chain) {
	chain_number[now] = node_chain;
	chain_index[now] = chain[node_chain].size();
	chain[node_chain].push_back(now);

	int heavy = -1;
	for (auto x : vertex[now]) {
		if (x != up && (heavy == -1 || sz[x] > sz[heavy])) {
			heavy = x;
		}
	}
	if (heavy != -1){
		hld(heavy, now, node_chain);
	}
	for (auto x : vertex[now]) {
		if (x != up && x != heavy) {
			hld(x, now, x);
		}
	}
}

void update(int a, int b) {
	seg.update(in[a], b);
}

int query(int a, int b) {
	int ans = 0;
	while (chain_number[a] ^ chain_number[b]) {
		if (depth[chain_number[a]] < depth[chain_number[b]]) {
			swap(a, b);
		}
		int st = chain_number[a];
		ans = max(seg.query(in[st], in[a]),ans);
		a = parent[st];
	}
	if (depth[a] > depth[b]) {
		swap(a, b);
	}
	ans = max(seg.query(in[a], in[b]),ans);
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n ;
	while (base < n) {
		base <<= 1;
	}
	for (int i = 1; i < n ; i++) {
		int st, ed,val;
		cin >> st >> ed >> val;
		edge[i] = { val , {st,ed} };
		vertex[st].push_back(ed);
		vertex[ed].push_back(st);
	}
	dfs(1,0);
	dfs2(1, 0);
	hld(1, 0, 1);
	for (int i = 1; i < n; i++) {
		update(i, edge[i].first);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		}
		else if(a==2){
			cout << query(b, c) << '\n';
		}
	}
}