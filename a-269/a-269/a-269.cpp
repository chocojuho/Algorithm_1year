#define x first
#define y second
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


using namespace std;
using point = pair<double, double>;
vector<pair<point, point>> vc;
int n;
int cnt;
int parent[50001];

int ccw(point a, point b, point c) {
	long long res = a.x * b.y + b.x * c.y + c.x * a.y;
	res -= a.y * b.x + b.y * c.x + c.y * a.x;
	return (res > 0) - (res < 0);
}

bool cross(point a, point b, point c, point d) {
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b) {
			swap(a, b);
		}
		if (c > d) {
			swap(c, d);
		}
		return !(d < a || b < c);
	}
	return 0;
}

int finder(int now) {
	if (parent[now] == now) {
		return now;
	}
	return parent[now] = finder(parent[now]);
}
void merge(int st,int ed) {
	int stp = finder(st);
	int edp = finder(ed);
	if (stp != edp) {
		if(stp > edp){
			parent[stp] = edp;
		}
		else {
			parent[edp] = stp;
		}
	}
}
unordered_set<int> st;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		point a, b;
		cin >> a.x >> a.y;
		cin >> b.x >> b.y;
		a.x *= 100;
		a.y *= 100;
		b.x *= 100;
		b.y *= 100;
		vc.push_back({ a,b });
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (finder(i) != finder(j) && cross(vc[i].first, vc[i].second, vc[j].first, vc[j].second)) {
				merge(i, j);
				cnt++;
			}
		}
	}
	cout << n - cnt;
}