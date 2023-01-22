#include <iostream>
#include <stack>

using namespace std;

int n;
string str;
stack<char> st;
int main()
{
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] == ',') {
			if (st.empty()) {
				str[i] = '.';
			}
		}
		if (str[i] == '"') {
			if (st.empty()) {
				st.push('"');
			}
			else {
				st.pop();
			}
		}
	}
	cout << str;
}