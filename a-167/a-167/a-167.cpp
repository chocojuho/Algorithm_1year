﻿#include <iostream>
#include <vector>

using namespace std;

struct Seg {
    int tree[1 << 18];
    int sz = 1 << 17;

    void update(int x, int v) {
        x |= sz; tree[x] += v;
        while (x >>= 1) {
            tree[x] = tree[x << 1] + tree[x << 1 | 1];
        }
    }

    int query(int l, int r) {
        l |= sz, r |= sz;
        int ret = 0;
        while (l <= r) {
            if (l & 1) ret += tree[l++];
            if (~r & 1) ret += tree[r--];
            l >>= 1, r >>= 1;
        }
        return ret;
    }
}seg;

int sz[101010]; // 서브트리 크기
int dep[101010]; // 깊이
int par[101010]; // 부모저장
int top[101010]; // heavy 사슬 구분
int in[101010]; // 들어간 순서
int out[101010]; // 나온 순서
vector<int> g[101010];
vector<int> inp[101010];

int visited[101010];
void dfs(int v = 1) {
    visited[v] = 1;
    for (auto i : inp[v]) {
        if (visited[i] != 1) {
            visited[i] = 1;
            g[v].push_back(i);
            dfs(i);
        }
    }
}

void dfs1(int v = 1) {
    sz[v] = 1;
    for (auto& i : g[v]) {
        dep[i] = dep[v] + 1; par[i] = v;
        dfs1(i); sz[v] += sz[i];
        if (sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
    }
}

int pv;
void dfs2(int v = 1) {
    in[v] = ++pv;
    for (auto i : g[v]) {
        top[i] = i == g[v][0] ? top[v] : i;
        dfs2(i);
    }
    out[v] = pv;
}

void update(int v, int w) {
    seg.update(in[v], w);
}

int query(int a, int b) {
    int ret = 0;
    while (top[a] ^ top[b]) {
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        int st = top[a];
        ret += seg.query(in[st], in[a]);
        a = par[st];
    }
    if (dep[a] > dep[b]) swap(a, b);
    ret += seg.query(in[a], in[b]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int s, e; 
        cin >> s >> e;
        inp[s].push_back(e);
        inp[e].push_back(s);
    }
    dfs(); 
    dfs1(); 
    dfs2();
    while (q--) {
        int c, a, b; cin >> c >> a >> b;
        if (c == 1) {
            update(a, b);
        }
        else if (c == 2) {
            cout << query(a, b) << "\n";
        }
    }
}