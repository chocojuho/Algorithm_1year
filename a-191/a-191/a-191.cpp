#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n,q,m,c;

int main()
{
	cin >> q;
	for (int i = 0; i < q; i++) {
		int arr[100010] = { 0, };
		vector<int> vc;
		int mmn = 0;
		cin >> n >> c;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			vc.push_back(a);
			arr[a]++;
		}sort(vc.begin(),vc.end());
		vc.erase(unique(vc.begin(), vc.end()), vc.end());
		
		for (int j = 0; j < vc.size(); j++) {
			mmn += min(arr[vc[j]],c);
		}
		cout << mmn << '\n';
	}
}