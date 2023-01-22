#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
string p;

vector<int> preprocessing(string p) {
	int m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	int i = 0,j =0;
	for (i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = j + 1;
			j += 1;
		}
		else {
			pi[i] = 0;
		}
	}
	return pi;
}

vector<int> kmp(string s, string p) {
	int n = s.size();
	int m = p.size();
	auto pi = preprocessing(p);
	vector<int> ans;
	int i=0,j=0;
	for (i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j==m-1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j += 1;
			}
		}
	}
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	cin >> p;
	while (1) {
		auto ans = kmp(s, p);
		if (ans.empty()) {
			cout << s;
			break;
		}
		for (int i = 0; i < ans.size();i++) {
			//s.erase(s.begin() + k, s.begin() + k + p.size()+1);
			s.erase(ans[i]-p.length()*i, p.length());
			//cout << s << ' ';
		}
		if (s == "") {
			cout << "FRULA";
			break;
		}
	}
}