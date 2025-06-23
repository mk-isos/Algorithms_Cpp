#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int w, h;
vector<string> board;
vector<pair<int, int>> points; // [0]: start, [1~n]: dirty tiles
int dist[11][11];              // 거리 테이블
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// BFS로 points[i] → points[j] 거리 계산
int bfs(pair<int, int> start, pair<int, int> goal)
{
    queue<pair<int, int>> q;
    vector<vector<int>> visited(h, vector<int>(w, -1));
    q.push(start);
    visited[start.second][start.first] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (make_pair(x, y) == goal)
            return visited[y][x];

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h)
                continue;
            if (board[ny][nx] == 'x' || visited[ny][nx] != -1)
                continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({nx, ny});
        }
    }

    return -1; // 도달 불가
}

int solve()
{
    int n = points.size();
    // 거리 계산
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = bfs(points[i], points[j]);

    // 도달 불가능한 경우 -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[i][j] == -1)
                return -1;

    int dp[11][1 << 11];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][1] = 0; // 시작 위치는 0번, 비트마스크에서 첫 비트만 켜짐

    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int u = 0; u < n; u++)
        {
            if (!(mask & (1 << u)))
                continue;
            for (int v = 1; v < n; v++)
            {
                if (mask & (1 << v))
                    continue;
                int next_mask = mask | (1 << v);
                dp[v][next_mask] = min(dp[v][next_mask], dp[u][mask] + dist[u][v]);
            }
        }
    }

    int answer = INT_MAX;
    for (int i = 1; i < n; i++)
        answer = min(answer, dp[i][(1 << n) - 1]);

    return answer;
}

int main()
{
    FIO;

    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        board.clear();
        points.clear();

        for (int i = 0; i < h; i++)
        {
            string row;
            cin >> row;
            board.push_back(row);
            for (int j = 0; j < w; j++)
            {
                if (row[j] == 'o')
                    points.insert(points.begin(), {j, i}); // start = index 0
                else if (row[j] == '*')
                    points.push_back({j, i});
            }
        }

        cout << solve() << '\n';
    }
    return 0;
}
