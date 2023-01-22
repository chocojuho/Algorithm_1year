#include <iostream>
#include <algorithm>

using namespace std;

int m;
int main()
{
	cin >> m;
	for (int query = 0; query < m; query++) {
			int n=0, a=0, b=0, num = 1,len, i = 0,j=-1,dir=1,cnt=0;
			pair<pair<int,int>, pair<int,int>> ans;
			cin >> n >> a >> b;
			len = n;
			while (true) {
				for (int k = 0; k < len; k++) {
					j += dir;
					if (num == a || num == b) {
						if (num == a) {
							ans.first = {i,j};
						}
						else if(num==b) {
							ans.second = {i,j};
						}
						cnt++;
					}
					num++;
				}
				len -= 1;
				if (len == 0) {
					break;
				}
				for (int k = 0; k < len; k++) {
					i += dir;
					if (num == a || num ==b) {
						if (num == a) {
							ans.first = {i,j};
						}
						else if (num == b) {
							ans.second = {i,j};
						}
						cnt++;
					}
					num++;
				}
				dir *= -1;
			}
			cout << "(" << ans.first.first << "," << ans.first.second << ")" << " " << "(" << ans.first.first << "," << ans.first.second << ")" << '\n';
			if((ans.second.first - ans.first.first) == (ans.second.second - ans.first.second)){
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
	}
	
}