#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> vc;
vector<long long> ans;
long long n,now;
long long st, ed;
long long sum;
long long mmn;
long long mmnidx;
long long cnt;
int visited[100010];
string query;
/*long long cmp2(long long a, long long b) {

}*/
int main()
{
	cin >> query >> st >> ed >> now;
	cin >> n;
	if (query == "FCFS" || query == "fcfs" || query == "에프시에프에스") {
		vc.push_back(now);
		for (auto i = 0; i < n; i++) {
			int v;
			cin >> v;
			vc.push_back({ v });
		}
		ans.push_back(now);
		for (auto i = 0; i < vc.size() - 1; i++) {
			sum += abs(vc[i] - vc[i + 1]);
			ans.push_back({ vc[i + 1] });
		}
	}
	else if (query == "SSTF" || query == "sstf" || query == "에스에스티에프") {
		/*vc.push_back(now);
		for (auto i = 0; i < n; i++) {
			int v;
			cin >> v;
			vc.push_back({ v });
		}
		cnt = vc.size()-1;
		long long i = vc[0];
		auto j = 0;
		while (cnt >= 0) {
			i = mmnidx;
			visited[i] = 1;
			cnt--;
			sum += mmn;
			mmn = 9999999;
			for (j = 0; j < vc.size(); j++) {
				if (i == j || visited[j] == 1) {
					continue;
				}
				if (mmn > abs(vc[i] - vc[j])) {
					mmn = abs(vc[i] - vc[j]);
					mmnidx = j;
				}
			}
			
		}
		cout << sum;*/
	}
	else if (query == "SCAN" || query == "scan" || query == "스캔") {

	}
	else if (query == "LOOK" || query == "look" || query == "룩" || query=="보다") {

	}
	else {

	}
	cout << sum << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}
