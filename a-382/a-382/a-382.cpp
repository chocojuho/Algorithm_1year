#include <iostream>

using namespace std;

string str;
int dp[100010];
int mmx;
bool used[1000010];

int main()
{
	cin >> str;
	for (int i = 1; i < str.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (str[i] == 'a' && (str[j] == 'c' || str[j] == 't')) {
				dp[i] = max(dp[i], dp[j]);
			}
			else if (str[i] == 'g' && (str[j] == 'c' || str[j] == 't')) {
				dp[i] = max(dp[i], dp[j]);
			}
			else if (str[i] == 't' && str[j]=='a') {

				used[j] = 1;
				dp[i] = max(dp[i], dp[j]+2);
			}
			else if (str[i] == 'c' && str[j] == 'g') {
				dp[i] = max(dp[i], dp[j] + 2);
			}
		}
		mmx = max(dp[i],mmx);
	}
	cout << mmx;
}