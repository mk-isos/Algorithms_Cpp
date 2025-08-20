#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using ll = long long;

struct Edge
{
    int u, v;
    ll w;
};
int main()
{
    FIO;
    int V, E;
    if (!(cin >> V >> E))
        return 0;
    vector<Edge> edges(E);
    vector<vector<pair<int, int>>> g(V + 1);
    for (int i = 0; i < E; i++)
    {
        int x, y;
        ll d;
        cin >> x >> y >> d;
        edges[i] = {x, y, d};
        g[x].push_back({y, i});
        g[y].push_back({x, i});
    }
    int s = 1, t = V;

    vector<int> tin(V + 1, 0), low(V + 1, 0);
    int timer = 0;
    vector<int> st;
    st.reserve(E);
    vector<vector<int>> compEdges;
    vector<int> it(V + 1, 0);
    struct Frame
    {
        int u, p, pe;
    };
    vector<Frame> stf;
    stf.reserve(V);
    stf.push_back({s, 0, -1});
    while (!stf.empty())
    {
        auto &f = stf.back();
        int u = f.u, p = f.p, pe = f.pe;
        if (!tin[u])
            tin[u] = low[u] = ++timer;
        bool pushed = false;
        while (it[u] < (int)g[u].size())
        {
            auto [v, eid] = g[u][it[u]++];
            if (eid == pe)
                continue;
            if (!tin[v])
            {
                st.push_back(eid);
                stf.push_back({v, u, eid});
                pushed = true;
                break;
            }
            else if (tin[v] < tin[u])
            {
                st.push_back(eid);
                low[u] = min(low[u], tin[v]);
            }
        }
        if (pushed)
            continue;
        if (pe != -1)
        {
            low[p] = min(low[p], low[u]);
            if (low[u] >= tin[p])
            {
                vector<int> ce;
                while (true)
                {
                    int e = st.back();
                    st.pop_back();
                    ce.push_back(e);
                    if (e == pe)
                        break;
                }
                compEdges.push_back(move(ce));
            }
        }
        stf.pop_back();
        if (stf.empty())
        {
            for (int i = 1; i <= V; i++)
                if (!tin[i])
                {
                    stf.push_back({i, 0, -1});
                    break;
                }
        }
    }

    struct Comp
    {
        bool isCycle;
        vector<int> vs;
        vector<ll> w;
        unordered_map<int, int> pos;
        ll bridgeW = 0;
    };

    int C = 0;
    vector<Comp> comps;
    comps.reserve(compEdges.size());
    vector<vector<int>> belongs(V + 1);
    for (auto &ce : compEdges)
    {
        if ((int)ce.size() == 1)
        {
            int id = ce[0];
            int a = edges[id].u, b = edges[id].v;
            ll w = edges[id].w;
            Comp c;
            c.isCycle = false;
            c.bridgeW = w;
            c.vs = {a, b};
            c.w = {w};
            int cid = C++;
            comps.push_back(move(c));
            belongs[a].push_back(cid);
            belongs[b].push_back(cid);
        }
        else
        {
            unordered_map<int, vector<pair<int, ll>>> cg;
            cg.reserve(ce.size() * 2);
            vector<int> verts;
            verts.reserve(ce.size());
            for (int id : ce)
            {
                int a = edges[id].u, b = edges[id].v;
                ll w = edges[id].w;
                cg[a].push_back({b, w});
                cg[b].push_back({a, w});
            }
            int start = cg.begin()->first;
            vector<int> cycV;
            cycV.reserve(cg.size());
            vector<ll> cycW;
            cycW.reserve(cg.size());
            int prev = start, cur = cg[start][0].first;
            cycV.push_back(start);
            while (true)
            {
                ll w = (cg[cur][0].first == prev ? cg[cur][0].second : cg[cur][1].second);
                cycW.push_back(w);
                if (cur == start)
                    break;
                cycV.push_back(cur);
                int nxt = (cg[cur][0].first != prev ? cg[cur][0].first : cg[cur][1].first);
                prev = cur;
                cur = nxt;
            }
            Comp c;
            c.isCycle = true;
            c.vs = move(cycV);
            c.w = move(cycW);
            c.pos.reserve(c.vs.size() * 2);
            for (int i = 0; i < (int)c.vs.size(); i++)
            {
                c.pos[c.vs[i]] = i;
                belongs[c.vs[i]].push_back(C);
            }
            comps.push_back(move(c));
            C++;
        }
    }

    vector<int> vNode(V + 1, -1);
    int extra = 0;
    auto needNode = [&](int v) -> bool
    {
        if (v == s || v == t)
            return true;
        return (int)belongs[v].size() >= 2;
    };
    for (int v = 1; v <= V; v++)
        if (needNode(v))
            vNode[v] = C + extra++;
    int Nnodes = C + extra;
    vector<vector<int>> T(Nnodes);
    vector<int> nodeToVertex(Nnodes, -1);
    for (int v = 1; v <= V; v++)
    {
        if (vNode[v] != -1)
        {
            nodeToVertex[vNode[v]] = v;
            for (int cid : belongs[v])
            {
                T[vNode[v]].push_back(cid);
                T[cid].push_back(vNode[v]);
            }
        }
    }
    if (vNode[s] == -1 || vNode[t] == -1)
    {
        cout << "권욱제 재입대를\n";
        return 0;
    }

    vector<int> par(Nnodes, -1);
    deque<int> dq;
    dq.push_back(vNode[s]);
    par[vNode[s]] = vNode[s];
    while (!dq.empty() && par[vNode[t]] == -1)
    {
        int u = dq.front();
        dq.pop_front();
        for (int v : T[u])
        {
            if (par[v] == -1)
            {
                par[v] = u;
                dq.push_back(v);
            }
        }
    }
    if (par[vNode[t]] == -1)
    {
        cout << "권욱제 재입대를\n";
        return 0;
    }

    vector<int> path;
    for (int x = vNode[t];; x = par[x])
    {
        path.push_back(x);
        if (x == vNode[s])
            break;
    }
    reverse(path.begin(), path.end());

    auto cycle_cost = [&](const Comp &c, int a, int b) -> ll
    {
        int m = c.vs.size();
        int ia = c.pos.at(a), ib = c.pos.at(b);
        ll m1 = LLONG_MAX, m2 = LLONG_MAX;
        for (int i = ia; i != ib; i = (i + 1) % m)
            m1 = min(m1, c.w[i]);
        for (int i = ib; i != ia; i = (i + 1) % m)
            m2 = min(m2, c.w[i]);
        return m1 + m2;
    };

    ll ans = (ll)4e18;
    for (int i = 1; i + 1 < (int)path.size(); i++)
    {
        int node = path[i];
        if (node < C)
        {
            int la = path[i - 1], ra = path[i + 1];
            int A = nodeToVertex[la], B = nodeToVertex[ra];
            if (!comps[node].isCycle)
                ans = min(ans, comps[node].bridgeW);
            else
                ans = min(ans, cycle_cost(comps[node], A, B));
        }
    }

    if (ans == (ll)4e18)
        cout << "권욱제 재입대를\n";
    else
        cout << ans << "\n";
}
