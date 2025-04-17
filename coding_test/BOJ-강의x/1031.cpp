#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
int f[103][103]; // 현재 유량
int c[103][103]; // 용량
vector<int> adj[103];
int total_flow;

void ek_flow()
{
    int S = 0, T = N + M + 1;
    while (true)
    {
        vector<int> prev(N + M + 2, -1);
        queue<int> q;
        q.push(S);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (int next : adj[cur])
            {
                if (c[cur][next] > f[cur][next] && prev[next] == -1)
                {
                    prev[next] = cur;
                    q.push(next);
                    if (next == T)
                        break;
                }
            }
        }
        if (prev[T] == -1)
            return;

        for (int i = T; i != S; i = prev[i])
        {
            f[prev[i]][i] += 1;
            f[i][prev[i]] -= 1;
        }
        total_flow += 1;
    }
}

void flipping(int i, int j)
{
    int S = 0, T = N + M + 1;

    f[S][i]--;
    f[i][S]++;
    f[i][j]--;
    f[j][i]++;
    f[j][T]--;
    f[T][j]++;

    queue<int> q;
    q.push(i);
    vector<int> prev(N + M + 2, -1);
    prev[i] = S;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : adj[cur])
        {
            if (cur == i && next <= j)
                continue;
            if (next <= i)
                continue;
            if (c[cur][next] > f[cur][next] && prev[next] == -1)
            {
                prev[next] = cur;
                q.push(next);
                if (next == T)
                    break;
            }
        }
    }

    if (prev[T] == -1)
    {
        f[S][i]++;
        f[i][S]--;
        f[i][j]++;
        f[j][i]--;
        f[j][T]++;
        f[T][j]--;
        return;
    }

    for (int i = T; i != S; i = prev[i])
    {
        f[prev[i]][i] += 1;
        f[i][prev[i]] -= 1;
    }
}

int main()
{
    FIO;
    cin >> N >> M;

    int totalA = 0, totalB = 0;

    for (int i = 1; i <= N; ++i)
    {
        int x;
        cin >> x;
        c[0][i] = x;
        adj[0].push_back(i);
        adj[i].push_back(0);
        totalA += x;
    }

    for (int i = N + 1; i <= N + M; ++i)
    {
        int x;
        cin >> x;
        c[i][N + M + 1] = x;
        adj[i].push_back(N + M + 1);
        adj[N + M + 1].push_back(i);
        totalB += x;
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = N + 1; j <= N + M; ++j)
        {
            c[i][j] = 1;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    if (totalA != totalB)
    {
        cout << -1 << '\n';
        return 0;
    }

    ek_flow();
    if (total_flow != totalA)
    {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = N + 1; j <= N + M; ++j)
        {
            if (f[i][j] == 1)
                flipping(i, j);
            cout << f[i][j];
        }
        cout << '\n';
    }
}
