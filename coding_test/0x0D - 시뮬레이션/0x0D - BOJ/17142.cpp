#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second

const int INF = 0x7f7f7f7f;
int n, m;
int board[55][55];
int dist[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int, int>> virus_spots;
vector<int> perm;
int emptyCnt = 0;

int bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + n, -1);

    for (int i = 0; i < virus_spots.size(); i++)
    {
        if (perm[i])
            continue;
        int x = virus_spots[i].X;
        int y = virus_spots[i].Y;
        q.push({x, y});
        dist[x][y] = 0;
    }

    int time = 0;
    int filled = 0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (board[nx][ny] == 1 || dist[nx][ny] >= 0)
                continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
            if (board[nx][ny] == 0)
            {
                filled++;
                time = dist[nx][ny];
            }
        }
    }

    return (filled == emptyCnt ? time : INF);
}

int main()
{
    FIO;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                emptyCnt++;
            if (board[i][j] == 2)
                virus_spots.push_back({i, j});
        }
    }

    perm.resize(virus_spots.size());
    fill(perm.begin() + m, perm.end(), 1);

    int ans = INF;
    do
    {
        ans = min(ans, bfs());
    } while (next_permutation(perm.begin(), perm.end()));

    cout << (ans == INF ? -1 : ans);
    return 0;
}
