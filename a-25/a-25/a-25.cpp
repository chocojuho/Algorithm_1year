#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

unsigned long long n, m, k;

vector<pair<unsigned long long, unsigned long long>> vc;
vector<pair<unsigned long long, unsigned long long>> vc2;

unsigned long long cmp(pair<unsigned long long, unsigned long long> a, pair<unsigned long long, unsigned long long> b) {
	return a.first > b.first;
}
unsigned long long cmp2(pair<unsigned long long, unsigned long long> a, pair<unsigned long long, unsigned long long> b) {
	return a.second > b.second;
}
unsigned long long total;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (unsigned long long i = 0; i < n; i++) {
		unsigned long long a, b;
		cin >> a >> b;
		vc.push_back({ a,b });
	}
	stable_sort(vc.begin(), vc.end(), cmp);
	stable_sort(vc.begin() + m, vc.end(), cmp2);
	for (unsigned long long i = 0; i < m + k; i++) {
		total += vc[i].first;
	}
	cout << total;
}