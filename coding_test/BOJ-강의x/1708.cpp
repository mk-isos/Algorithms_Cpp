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

int main()
{
    FIO;

    int N;
    if (!(cin >> N))
        return 0;
    vector<P> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i].x >> v[i].y;

    sort(v.begin(), v.end(), [](const P &a, const P &b)
         {
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y; });

    vector<P> H;
    H.reserve(2 * N);

    // lower hull
    for (const auto &p : v)
    {
        while (H.size() >= 2 && cross(H[H.size() - 2], H.back(), p) <= 0)
            H.pop_back();
        H.push_back(p);
    }
    // upper hull
    size_t t = H.size();
    for (int i = N - 2; i >= 0; --i)
    {
        while (H.size() > t && cross(H[H.size() - 2], H.back(), v[i]) <= 0)
            H.pop_back();
        H.push_back(v[i]);
        if (i == 0)
            break;
    }

    if (!H.empty())
        H.pop_back(); // remove duplicate first point
    cout << H.size() << '\n';
}
