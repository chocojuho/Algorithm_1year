#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;
map<string,string> mp;
set<string> st;
vector<string> vc;
int n;
int flag = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		vc.push_back(a);
		st.insert(a);
		mp.insert({ a,b });
	}
	for (auto i : vc) {
		int cnt =0;
		string k = i;
		if (st.find(k) == st.end()) {
			continue;
		}
		while (1) {
			if (mp.find(k)==mp.end()) {
				break;
			}
			st.erase(k);
			k = mp[k];
			cnt++;
			if (cnt >= 100010) {
				flag = 0;
				break;
			}
		}
		if (!flag) {
			break;
		}
	}
	if (!flag) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
}