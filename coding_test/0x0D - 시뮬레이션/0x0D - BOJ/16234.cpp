#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define X first
#define Y second

int n, l, r;
int board[51][51];
bool vis[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool bfs(int i, int j)
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> cells;

    q.push({i, j});
    vis[i][j] = true;
    cells.push_back({i, j});
    int sum = board[i][j];

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (vis[nx][ny])
                continue;

            int diff = abs(board[x][y] - board[nx][ny]);
            if (diff >= l && diff <= r)
            {
                vis[nx][ny] = true;
                q.push({nx, ny});
                cells.push_back({nx, ny});
                sum += board[nx][ny];
            }
        }
    }

    if (cells.size() == 1)
        return false;

    int new_pop = sum / cells.size();
    for (auto [x, y] : cells)
        board[x][y] = new_pop;
    return true;
}

int main()
{
    FIO;
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int days = 0;

    while (true)
    {
        bool moved = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j])
                {
                    if (bfs(i, j))
                        moved = true;
                }
            }
        }
        if (!moved)
            break;
        days++;
    }
    cout << days;
}
