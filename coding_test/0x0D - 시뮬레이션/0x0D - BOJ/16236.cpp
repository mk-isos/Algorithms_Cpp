#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int board[22][22], dist[22][22];
int n;
int sharkSize = 2, eatCount = 0, totalTime = 0;

tuple<int, int, int> bfs(int sx, int sy)
{
    fill(&dist[0][0], &dist[0][0] + 22 * 22, -1);

    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    tuple<int, int, int> result = {INT_MAX, INT_MAX, INT_MAX};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        if (dist[x][y] > get<0>(result))
            break;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (dist[nx][ny] != -1 || board[nx][ny] > sharkSize)
                continue;

            dist[nx][ny] = dist[x][y] + 1;
            if (board[nx][ny] != 0 && board[nx][ny] < sharkSize)
            {
                result = min(result, {dist[nx][ny], nx, ny});
            }
            q.push({nx, ny});
        }
    }

    return result;
}

int main()
{
    FIO;
    cin >> n;
    int sx, sy;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                sx = i;
                sy = j;
                board[i][j] = 0;
            }
        }

    while (true)
    {
        auto [distToFish, x, y] = bfs(sx, sy);
        if (distToFish == INT_MAX)
            break; // 먹을 수 있는 물고기 없음

        totalTime += distToFish;
        eatCount++;
        board[x][y] = 0;
        sx = x;
        sy = y;

        if (eatCount == sharkSize)
        {
            sharkSize++;
            eatCount = 0;
        }
    }

    cout << totalTime;
}
