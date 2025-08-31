#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n;
    if (!(cin >> n))
        return 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int t, l;
        cin >> t >> l;
        ans = min(ans, t + l);
    }
    cout << ans << '\n';
}
