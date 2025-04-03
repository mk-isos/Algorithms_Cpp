#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second

const int INF = 0x3f3f3f3f;
int n, m;
int board[55][55];
int dist[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<pair<int, int>> virusCandidates;
int result = INF;

int bfs(vector<pair<int, int>> &activeVirus)
{
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;

    for (auto [x, y] : activeVirus)
    {
        q.push({x, y});
        dist[x][y] = 0;
    }

    int time = 0;
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
            if (board[nx][ny] == 1 || dist[nx][ny] != -1)
                continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
            time = max(time, dist[nx][ny]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0 && dist[i][j] == -1)
                return INF; // 바이러스가 도달하지 못한 빈 칸이 있음
        }
    }
    return time;
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
            if (board[i][j] == 2)
            {
                virusCandidates.push_back({i, j});
                board[i][j] = 0;
            }
        }
    }

    vector<int> comb(virusCandidates.size(), 1);
    fill(comb.begin(), comb.begin() + m, 0);

    do
    {
        vector<pair<int, int>> activeVirus;
        for (int i = 0; i < comb.size(); i++)
        {
            if (comb[i] == 0)
                activeVirus.push_back(virusCandidates[i]);
        }
        int time = bfs(activeVirus);
        result = min(result, time);
    } while (next_permutation(comb.begin(), comb.end()));

    if (result == INF)
        cout << -1;
    else
        cout << result;
}
