#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second

int n, maxcnt, maxlimit;
int area[102][102];
int vis[102][102];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int i, int j, int limit)
{
    queue<pair<int, int>> q;
    vis[i][j] = 1;
    q.push({i, j});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (vis[nx][ny] == 0 && area[nx][ny] > limit)
            { // 미방문, 침수되지 않음
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    FIO;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> area[i][j];
            maxlimit = max(area[i][j], maxlimit);
        }
    }

    for (int limit = 0; limit <= maxlimit; limit++)
    {
        for (int i = 0; i < n; i++)
            fill(vis[i], vis[i] + n, 0);

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (area[i][j] > limit && vis[i][j] == 0)
                { // 침수 여부, 방문 여부
                    bfs(i, j, limit);
                    cnt++;
                }
            }
        }
        maxcnt = max(cnt, maxcnt);
    }
    cout << maxcnt;
}