#include <iostream>
#include <vector>

using namespace std;

vector<pair<pair<int, int>, int>> vc;
int n;
int all;
int mday;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int day, score;
		cin >> day >> score;
		vc.push_back({ {day,score},0 });
		mday = max(day, mday);
	}
	for (int i = 0; i < mday; i++) {
		float ans = -9999;
		int idx = -1;
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			//if (i == 6) {
			//	cout << vc[j].first.second / (vc[j].first.first - i + 1)<< ' ';
			//}
			if (vc[j].first.first - i > 0 && vc[j].second != 1 && ans < vc[j].first.second / (vc[j].first.first - i)) {
				ans = vc[j].first.second / (vc[j].first.first - i);
				cnt++;
				idx = j;
			}
		}
		if (cnt <= 0) {
			break;
		}
		all += vc[idx].first.second;
		vc[idx].second = 1;
	}
	cout << all;
}
