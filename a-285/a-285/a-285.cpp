#include <iostream>
#include <queue>

using namespace std;

int t;
int parent[1000010];
int visited[1000010];

string bfs(int a, int b) {
	queue<pair<int,string>> qu;
	qu.push({a,"S"});
	while (!qu.empty()) {
		int now = qu.front().first;
		string ns = qu.front().second;
		qu.pop();
		if (now == b) {
			return ns;
		}
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				qu.push({2*now % 10000,ns+"D"});
			}
			else if (i == 1) {
				qu.push({ (now==0)?9999:now-1,ns + "S" });
			}
			else if (i == 2) {
				int k = now / 1000 + ((now%1000)/100)*1000 + ((now % 100)/10*100)+(now%10)*10;
				qu.push({k,ns + "S" });
			}
			else if (i == 3) {
				int k = (now % 10) * 1000 + ((now / 1000) * 100) + ((now % 1000) / 100 * 10) + ((now % 100) / 10);
				qu.push({ k,ns + "S" });
			}
		}
	}
}

int main()
{
	int now;
	cin >> now;
	//cin >> t;
	/*while (t--) {
		int start, end;
		cin >> start >> end;
		cout << bfs(start, end) << '\n';
	}*/
	cout << now / 1000 + ((now % 1000) / 100) * 1000 + ((now % 100) / 10 * 100) + (now % 10) * 10;
}