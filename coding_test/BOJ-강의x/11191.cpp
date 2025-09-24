#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n;
    if (!(cin >> n))
        return 0;
    const int B = 63;
    long long basis[B + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        for (int b = B; b >= 0; b--)
        {
            if (((x >> b) & 1) == 0)
                continue;
            if (!basis[b])
            {
                basis[b] = x;
                break;
            }
            x ^= basis[b];
        }
    }

    long long ans = 0;
    for (int b = B; b >= 0; b--)
        ans = max(ans, ans ^ basis[b]);
    cout << ans << '\n';
}
