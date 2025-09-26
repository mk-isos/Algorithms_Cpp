#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using ll = long long;

struct P
{
    ll x, y;
};

int sgn128(__int128 v) { return v > 0 ? 1 : (v < 0 ? -1 : 0); }
int orient(const P &a, const P &b, const P &c)
{
    return sgn128((__int128)(b.x - a.x) * (c.y - a.y) - (__int128)(b.y - a.y) * (c.x - a.x));
}

bool inside_convex_strict(const vector<P> &v, const P &p)
{
    int n = (int)v.size();
    if (orient(v[0], v[1], p) <= 0)
        return false;
    if (orient(v[0], v[n - 1], p) >= 0)
        return false;
    int l = 1, r = n - 1;
    while (r - l > 1)
    {
        int m = (l + r) >> 1;
        if (orient(v[0], v[m], p) > 0)
            l = m;
        else
            r = m;
    }
    return orient(v[l], v[l + 1], p) > 0;
}

int main()
{
    FIO;

    int N, M;
    int K;
    if (!(cin >> N >> M >> K))
        return 0;
    vector<P> A(N), B(M), S(K);
    for (int i = 0; i < N; i++)
        cin >> A[i].x >> A[i].y;
    for (int i = 0; i < M; i++)
        cin >> B[i].x >> B[i].y;
    for (int i = 0; i < K; i++)
        cin >> S[i].x >> S[i].y;

    long long bad = 0;
    for (int i = 0; i < K; i++)
    {
        bool inA = inside_convex_strict(A, S[i]);
        bool inBout = !inside_convex_strict(B, S[i]);
        if (!(inA && inBout))
            ++bad;
    }
    if (bad == 0)
        cout << "YES\n";
    else
        cout << bad << '\n';
}
