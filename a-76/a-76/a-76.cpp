#include <iostream>

using namespace std;
int n, k;
char str[10000];
char finder[10] = { 'D','K','S','H',};
int cnt[4];
int cur;
int main()
{
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++) {
		if(cur>4){
			break;
		}
		if (cnt[cur] && finder[cur + 1] == str[i]) {
			cur++;
		}
		if (finder[cur] == str[i]) {
			cnt[cur]++;
		}
	}
	cout << cnt[0] * cnt[1] * cnt[2] * cnt[3];
}