#include <iostream>
#include <vector>

using namespace std;

string str;
unsigned long long sum = 0;

int main()
{
	cin >> str;
	/*for (int j = 1; j <= 10000000; j++) {
		vector<char> vc;
		int k = j-1;
		vc.push_back(k % 26 + 'A');
		while(k) {
			k /= 26;
			vc.push_back(k % 26 + 'A');
		} ;
		for (int l = vc.size()-1; l >=0 ; l--) {
			cout << vc[l];
		}
		cout << "             " << j;
		cout << '\n';
	}*/
	for (int i = 0; i < str.size(); i++) {
		sum = (str[i]- 'A'+1)* (long long)pow((long long)26, (long long)str.size() - i - 1) +sum;
	}
	cout << sum;
}