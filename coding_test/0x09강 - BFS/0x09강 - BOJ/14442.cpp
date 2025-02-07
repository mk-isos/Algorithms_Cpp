#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m, k;
string board[1002]; // 한 줄로 한 행 전체를 바로 입력
int dist[1002][1002][12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    FIO;

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1;
    while (!q.empty())
    {
        auto [x, y, w] = q.front();
        q.pop();
        if (x == n - 1 && y == m - 1)
        {
            cout << dist[x][y][w] << '\n';
            return 0;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            // 벽이라면
            int nw = w;
            if (board[nx][ny] == '1')
                nw++;
            if (nw > k || dist[nx][ny][nw] > 0)
                continue;
            dist[nx][ny][nw] = dist[x][y][w] + 1;
            q.push({nx, ny, nw});
        }
    }
    cout << -1;
}