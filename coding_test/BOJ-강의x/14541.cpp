#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n;
    while (cin >> n && n != -1)
    {
        long long ans = 0;
        int prev = 0;
        for (int i = 0; i < n; ++i)
        {
            int s, t;
            cin >> s >> t;
            ans += 1LL * s * (t - prev);
            prev = t;
        }
        cout << ans << " miles\n";
    }
}
