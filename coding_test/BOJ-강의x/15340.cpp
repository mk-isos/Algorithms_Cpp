#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    long long c, d;
    while (cin >> c >> d)
    {
        if (c == 0 && d == 0)
            break;
        long long ans = LLONG_MAX;
        ans = min(ans, 30 * c + 40 * d); // ParsTel
        ans = min(ans, 35 * c + 30 * d); // ParsCell
        ans = min(ans, 40 * c + 20 * d); // ParsPhone
        cout << ans << '\n';
    }
}
