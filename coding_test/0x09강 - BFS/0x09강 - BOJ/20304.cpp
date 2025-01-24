#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define X first
#define Y second
int dist[1'000'005];

int main()
{
    FIO;

    int n, m, next, tmp;
    cin >> n;
    cin >> m;
    vector<int> start{};
    for (int i{}; i < m; ++i)
    {
        cin >> tmp;
        start.push_back(tmp);
    }

    fill(dist, dist + n + 2, -1);

    queue<int> q{};
    for (auto &e : start)
    {
        dist[e] = 0;
        q.push(e);
    }

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int k{}; k < 31; ++k)
        {
            // bitmask 검색
            if (cur & (1 << k))
                next = cur & ~(1 << k);
            else
                next = cur | (1 << k);
            if (next > n)
                continue;
            if (dist[next] >= 0)
                continue;
            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
    int ans = 0;
    for (int i{}; i <= n; ++i)
        ans = max(ans, dist[i]);
    cout << ans;
}