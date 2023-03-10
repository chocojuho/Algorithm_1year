#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long cnt;
string str,ptr;

vector<int> preprocessing(string p) {
	int m = p.size();
	vector<int> pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < m; i++) {
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
	auto pi = preprocessing(p);
	vector<int> ans;
	int n = s.size(), m = p.size(), i = 0, j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				cnt++;
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
	getline(cin, str);
	getline(cin, ptr);
	auto km = kmp(str, ptr);
	cout << cnt << '\n';
	for (int i = 0; i < km.size(); i++) {
		cout << km[i]+1 << " ";
	}
}