#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m, k;
string board[1002];

int dist[1002][1002][12][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    FIO;

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> board[i];

    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, 0});
    dist[0][0][0][0] = 1;

    while (!q.empty())
    {
        auto [x, y, w, t] = q.front();
        q.pop();

        // 도착
        if (x == n - 1 && y == m - 1)
        {
            cout << dist[x][y][w][t] << '\n';
            return 0;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            // 빈 곳 이동
            if (board[nx][ny] == '0')
            {
                int nw = w;
                int nt = 1 - t;
                if (dist[nx][ny][nw][nt] > 0) // 이미 방문한경우
                    continue;
                dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;
                q.push({nx, ny, nw, nt});
            }

            // 안 비었음
            else
            {
                // 이미 k번 깼음
                if (w == k)
                    continue;
                // 낮이라면 깨기 가능
                if (t == 0)
                {
                    int nw = w + 1;
                    int nt = 1 - t;
                    if (dist[nx][ny][nw][nt] > 0)
                        continue;
                    dist[nx][ny][nw][nt] = dist[x][y][w][t] + 1;
                    q.push({nx, ny, nw, nt});
                }
                // 밤이라면 낮까지 기다리기
                // 다음 좌표가 (nx, ny, nw, nt)가 아니라 (x, y, w, nt)임
                else
                {
                    int nt = 1 - t;
                    if (dist[x][y][w][nt] > 0)
                        continue;
                    dist[x][y][w][nt] = dist[x][y][w][t] + 1;
                    q.push({x, y, w, nt});
                }
            }
        }
    }
    cout << -1;
}