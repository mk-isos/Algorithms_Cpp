#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second

string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    FIO;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        fill(dist1[i], dist1[i] + m, -1);
        fill(dist2[i], dist2[i] + m, -1);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    queue<pair<int, int>> Q1; // 불 BFS용 큐
    queue<pair<int, int>> Q2; // 지훈이 BFS용 큐

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'F')
            {
                Q1.push({i, j});
                dist1[i][j] = 0;
            }
            if (board[i][j] == 'J')
            {
                Q2.push({i, j});
                dist2[i][j] = 0;
            }
        }
    }

    // 불에 대한 BFS
    while (!Q1.empty())
    {
        auto cur = Q1.front();
        Q1.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist1[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({nx, ny});
        }
    }

    // 지훈이에 대한 BFS
    while (!Q2.empty())
    {
        auto cur = Q2.front();
        Q2.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 미로를 벗어났다면 탈출 성공
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                cout << dist2[cur.X][cur.Y] + 1;
                return 0;
            }
            // 이미 방문했거나 벽이면 무시
            if (dist2[nx][ny] >= 0 || board[nx][ny] == '#')
                continue;
            // 불이 도달하는 시간과 비교하여 지훈이가 더 빨리 도착할 수 있는지 확인
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1)
                continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({nx, ny});
        }
    }

    // 여기까지 오면 탈출 불가능
    cout << "IMPOSSIBLE";
    return 0;
}
