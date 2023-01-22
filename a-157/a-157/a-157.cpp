#include <iostream>
#include <algorithm>
#include <queue> 


using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int visited[110][110];
int n, m;
int arr[110][110];
int ans = 0;
int mmx;
queue<pair<pair<int, int>, int>> qu;
int is_melt(int y, int x)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (x + dx[i] >= 0 && x + dx[i] < m && y + dy[i] >= 0 && y + dy[i] < n && (arr[y + dy[i]][x + dx[i]] == 0))
        {
            cnt++;
        }
    }
    return (cnt >= 2);
}

int bfs()
{
    int cnt = 0;
    while (!qu.empty()) {
        int y = qu.front().first.second;
        int x = qu.front().first.first;
        arr[x][y] = 0;
        cnt = qu.front().second;
        qu.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (ny >= 0 && ny < m && nx >= 0 && nx < n && arr[nx][ny] == 1 && visited[nx][ny] != 1 && is_melt(nx, ny)) {
                qu.push({ { nx,ny },cnt + 1 });
                visited[nx][ny] = 1;
            }
        }
    }//
    return cnt + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && is_melt(i, j)) {
                qu.push({ {i,j},0 });
                visited[i][j] = 1;
            }
        }
    }
    cout << bfs();
    return 0;
}