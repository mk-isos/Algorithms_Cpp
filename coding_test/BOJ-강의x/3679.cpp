#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct Node
{
    long long x, y;
    int idx;
    long double ang, r2;
};

int main()
{
    FIO;

    int c;
    if (!(cin >> c))
        return 0;

    while (c--)
    {
        int n;
        cin >> n;
        vector<Node> a(n);
        long double sx = 0, sy = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].x >> a[i].y;
            a[i].idx = i;
            sx += a[i].x;
            sy += a[i].y;
        }
        long double cx = sx / n, cy = sy / n;
        for (int i = 0; i < n; i++)
        {
            long double dx = a[i].x - cx, dy = a[i].y - cy;
            a[i].ang = atan2l(dy, dx);
            a[i].r2 = dx * dx + dy * dy;
        }
        sort(a.begin(), a.end(), [](const Node &A, const Node &B)
             {
            if (A.ang != B.ang) return A.ang < B.ang;
            return A.r2 < B.r2; });
        for (int i = 0; i < n; i++)
        {
            if (i)
                cout << ' ';
            cout << a[i].idx;
        }
        cout << '\n';
    }
}
