#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int map[51][51];
int chickencnt;

int ans=99999999;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
bool 씨발새끼야[100010];

void go(int index,int next ,int m) {
	if (index == m) {
		int result = 0;
		
		for (int i = 0; i < house.size();i++) {
			int mmn=99999999;
			for (int j = 0; j < chicken.size(); j++) {
				if (씨발새끼야[j] = true) {
					int distance = abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second);
					mmn = min(mmn, distance);
				}
				
			}
			result += mmn;
		}
		ans = min(result,ans);
		return;
	}
	for (int i = next; i < chickencnt; i++) {
		if (씨발새끼야[i] == false) {
			씨발새끼야[i] = true;
			go(index + 1, i+1,m);
			씨발새끼야[i] = false;
		}
		
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chickencnt++;
				chicken.push_back({ i,j });
			}
			if (map[i][j]==1) {
				house.push_back({ i,j });
			}
		}
	}
	go(0,0, m);
	cout << ans;
}