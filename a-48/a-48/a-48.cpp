#define inf 1e9
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef struct hi {
	long long 단백질;
	long long 지방;
	long long 탄수화물;
	long long 비타민;
	long long 가격;
}h;

long long n;

pair<long long, vector<long long>> all = { 9999999,{} };
long long nutrition[4];
long long nownutrition[4];
vector<h> vc;
vector<long long> temp;
void solve(long long now,long long costm) {
	if (now == n) {
		for (int i = 0; i < 4; i++) {
			if (nutrition[i] > nownutrition[i]) {
				return ;
			}
		}
		all = min(all, { costm,temp });
		return ;
	}
	solve(now + 1, costm);
	nownutrition[0] += vc[now].단백질;
	nownutrition[1] += vc[now].지방;
	nownutrition[2] += vc[now].탄수화물;
	nownutrition[3] += vc[now].비타민;
	temp.push_back(now);
	solve(now + 1, costm + vc[now].가격);
	nownutrition[0] -= vc[now].단백질;
	nownutrition[1] -= vc[now].지방;
	nownutrition[2] -= vc[now].탄수화물;
	nownutrition[3] -= vc[now].비타민;
	temp.pop_back();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> nutrition[i];
	}
	for (int i = 0; i < n; i++) {
		long long a, b, c,d, cost;
		cin >> a >> b >> c >> d >> cost;
		vc.push_back({ a,b,c,d,cost });
	}
	solve(0,0);
	if (all.first == 9999999) {
		cout << -1;
	}
	else {
		cout << all.first << '\n';
		int szze = all.second.size();
		for (int i = 0; i < szze;i++) {
			cout << all.second[i] + 1 << ' ';
		}
	}
}
