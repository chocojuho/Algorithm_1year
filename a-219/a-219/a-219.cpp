#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
stack<int> st;
vector<pair<char,int>> vc;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a;
		int k;
		cin >> a;
		if (a == 'a') {
			cin >> k;
			st.push(k);
			cout << st.top() << '\n';
			vc.push_back({ '-',k});
		}
		else if (a == 's') {
			if (st.empty()) {
				cout << "-1" << '\n';
			}
			else {
				vc.push_back({ '+',st.top()});
				st.pop();
				cout << st.top() << '\n';
			}
		}
		else if(a == 't') {
			cin >> k;
			vc.push_back({a,k});
			for (int j = i - 1; j >= k -1;j--) {
				if (a=='+') {
					st.push(vc[j].second);
				}
				else if(a=='-') {
					st.pop();
				}
				else if (a=='t') {
					k = vc[i].second-1;
				}
			}
			cout << st.top() << '\n';
		}
	}
}