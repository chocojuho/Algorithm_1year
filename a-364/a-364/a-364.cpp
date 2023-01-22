#include <iostream>

using namespace std;

int arr[6666][6666];
int n, m, k;

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x, y, r;
		cin >> y >> x >> r;
		arr[y + 3000 - r][x + 3000 ] += 1;
		arr[y + 3000 - r+1][x + 3000] += 1;
		arr[y-1+3000][x-r + 3000-1] += -1;
		arr[y-1+3000][x-r+3000] += -1;

		arr[y + 3000 ][x + 3000+r] += 1;
		arr[y + 3000+1][x + 3000+r] += 1;
		arr[y - 1 + 3000][x - r + 3000 - 1] += -1;
		arr[y - 1 + 3000][x - r + 3000] += -1;
	}
}