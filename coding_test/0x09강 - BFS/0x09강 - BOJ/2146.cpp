#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second

int board[101][101];
bool vis[101][101]; // 섬을 분류하는 첫 번째 bfs에서 사용
int dist[101][101]; // 다리의 길이를 구하는 두 번째 bfs에서 사용
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

bool OOB(int a, int b)
{ // Out Of Bounds인지 체크하는 함수
    return a < 0 or a >= n or b < 0 or b >= n;
}

void island()
{
    int idx = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 방문헀거나 바다면 건너뛰기~
            if (vis[i][j] || board[i][j] == 0)
                continue;

            queue<pair<int, int>> Q;
            Q.push({i, j});
            vis[i][j] = 1;

            while (!Q.empty())
            {
                auto cur = Q.front();
                Q.pop();
                board[cur.X][cur.Y] = idx;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (OOB(nx, ny) || vis[nx][ny] || board[nx][ny] == 0)
                        continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
            idx++;
        }
    }
}

int main()
{
    FIO;


    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    island();
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + n, -1);
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != 0)
            {
                dist[i][j] = 0;
                Q.push({i, j});
            }
        }
    }

    int ans = 999999;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (OOB(nx, ny) || board[nx][ny] == board[cur.X][cur.Y]) // OOB거나 인접한 곳이 같은 섬일 경우
                continue;
            if (board[nx][ny] != 0)
            {                                                      // 인접한 곳이 다른 섬일 경우
                ans = min(ans, dist[nx][ny] + dist[cur.X][cur.Y]); // cur와 (nx, ny) 각각이 육지로부터 떨어진 거리를 합하면 된다.
            }
            else
            { // 바다일 경우
                board[nx][ny] = board[cur.X][cur.Y];
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    cout << ans;
}