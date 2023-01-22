﻿// a-197.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int, int>> vc;
vector<int> lis;
vector<int> ans;
int index[100010];

int cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vc.push_back({ a,b });
	}
	sort(vc.begin(), vc.end(),cmp);
	for (int i = 0; i < n; i++) {
		if (lis.size() == 0) {
			index[i] = 0;
			lis.push_back(vc[i].second);
			continue;
		}
		if (lis.back() < vc[i].second) {
			index[i] = lis.size();
			lis.push_back(vc[i].second);
		}
		else {
			index[i] = lower_bound(lis.begin(), lis.end(), vc[i].second)-lis.begin();
			int curser = lower_bound(lis.begin(), lis.end(), vc[i].second) - lis.begin();
			lis[curser] = vc[i].second;
		}
	}
	cout << n-lis.size() << '\n';
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (lis.size() - cnt == index[i] + 1) {
			cnt++;
		}
		else {
			ans.push_back({ vc[i].first });
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << '\n';
	}
}