#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

string n;
int cnt = 0;
bool flag;
vector<int> vc[26];
int arr[26] = { 0, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == ')') {
			for (int j = 0; j < 26; j++) {
				arr[j] = 0;
			}
		}
		else if (n[i] == '(') {

		}
		else {
			if (arr[n[i]-'a'] != 0) {
				cout << "No";
				flag = 1;
				break;
			}
			arr[n[i] - 'a']++;
		}
	}
	if (!flag) {
		cout << "Yes";
	}
}