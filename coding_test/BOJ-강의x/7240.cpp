#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using ll = long long;
struct P
{
    ll x, y;
};

ll cross(const P &a, const P &b, const P &c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

long double dist(const P &a, const P &b)
{
    long double dx = (long double)b.x - a.x;
    long double dy = (long double)b.y - a.y;
    return sqrtl(dx * dx + dy * dy);
}

int main()
{
    FIO;

    int N;
    ll L;
    if (!(cin >> N >> L))
        return 0;
    vector<P> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].x >> v[i].y;

    sort(v.begin(), v.end(), [](const P &a, const P &b)
         {
        if(a.x!=b.x) return a.x<b.x;
        return a.y<b.y; });

    v.erase(unique(v.begin(), v.end(), [](const P &a, const P &b)
                   { return a.x == b.x && a.y == b.y; }),
            v.end());
    int n = (int)v.size();

    vector<P> H(2 * n);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], v[i]) <= 0)
            --k;
        H[k++] = v[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], v[i]) <= 0)
            --k;
        H[k++] = v[i];
    }
    if (k > 1)
        --k;
    H.resize(k);

    long double per = 0;
    if (k >= 2)
    {
        for (int i = 0; i < k; i++)
            per += dist(H[i], H[(i + 1) % k]);
    }
    const long double PI = acosl(-1.0L);
    long double ans = per + 2.0L * PI * (long double)L;
    cout << (long long)llround(ans) << '\n';
}
