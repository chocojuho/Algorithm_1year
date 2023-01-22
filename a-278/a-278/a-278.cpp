#include <iostream>
#include <map>
#include <string>


using ll = long long;
using namespace std;

map<string, string> mp;
ll n, s;
int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		string k,g;
		cin >> k >> g;
		mp.insert({ k,g });
	}
	for (int i = 0; i < s; i++) {
		string k;
		cin >> k;
		cout << mp[k] << '\n';
	}
}