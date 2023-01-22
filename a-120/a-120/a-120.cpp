// a-120.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long n, m, q;

vector<pair<long long, long long>> vertex[100000];
long long mindex[1000000];

void daijestar() {

}

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        mindex[i] = 2000000000;
    }
    for(int i=0;i<m;i++){
        long long a, b, c;
        cin >> a >> b >> c;
        vertex[a].push_back({b,c});
        vertex[b].push_back({ a,c });
    }
    for (int i = 0; i < q; i++) {
        memset()
    }
}