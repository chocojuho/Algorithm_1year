#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long sum = 0;
vector<int> ans;
void div(int now) {
	if (now == 0) {
		return;
	}
	ans.push_back({ now % 2 });
	div(now / 2);
}

int main()
{
	string str;
	cin >> str;
	for (int i = 1; i <= str.length(); i++) {
		if (str[i-1] == '1') {
			sum += pow(2, str.length() - i);
		}
	}
	sum *= 17;
	div(sum);
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
}