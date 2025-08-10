#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct Dinic
{
    struct Edge
    {
        int to, rev;
        long long cap;
    };
    int N;
    vector<vector<Edge>> G;
    vector<int> level, it;

    Dinic(int n) : N(n), G(n), level(n), it(n) {}

    void add_edge(int u, int v, long long c)
    {
        Edge a{v, (int)G[v].size(), c};
        Edge b{u, (int)G[u].size(), 0};
        G[u].push_back(a);
        G[v].push_back(b);
    }

    bool bfs(int s, int t)
    {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &e : G[u])
                if (e.cap > 0 && level[e.to] < 0)
                {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
        }
        return level[t] >= 0;
    }

    long long dfs(int u, int t, long long f)
    {
        if (u == t || f == 0)
            return f;
        for (int &i = it[u]; i < (int)G[u].size(); ++i)
        {
            Edge &e = G[u][i];
            if (e.cap > 0 && level[e.to] == level[u] + 1)
            {
                long long ret = dfs(e.to, t, min(f, e.cap));
                if (ret > 0)
                {
                    e.cap -= ret;
                    G[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    long long maxflow(int s, int t)
    {
        long long flow = 0, pushed;
        while (bfs(s, t))
        {
            fill(it.begin(), it.end(), 0);
            while ((pushed = dfs(s, t, LLONG_MAX / 4)) > 0)
                flow += pushed;
        }
        return flow;
    }
};

int main()
{
    FIO;
    int N, M;
    if (!(cin >> N >> M))
        return 0;

    vector<int> P(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> P[i];

    struct Group
    {
        int A, B, C;
    };
    vector<Group> grp(M + 1);
    long long sumC = 0;
    for (int i = 1; i <= M; ++i)
    {
        cin >> grp[i].A >> grp[i].B >> grp[i].C;
        sumC += grp[i].C;
    }

    int S = 0, T = M + N + 1;
    Dinic dinic(T + 1);
    const long long INF = (long long)1e15;

    for (int i = 1; i <= M; ++i)
    {
        dinic.add_edge(S, i, grp[i].C);

        dinic.add_edge(i, M + grp[i].A, INF);
        dinic.add_edge(i, M + grp[i].B, INF);
    }

    for (int i = 1; i <= N; ++i)
    {
        dinic.add_edge(M + i, T, P[i]);
    }

    long long max_flow = dinic.maxflow(S, T);
    long long max_profit = sumC - max_flow;
    cout << max_profit << '\n';
    return 0;
}
