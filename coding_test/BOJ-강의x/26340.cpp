#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        long long a, b, k;
        cin >> a >> b >> k;

        cout << "Data set: " << a << ' ' << b << ' ' << k << '\n';

        while (k-- > 0 && (a > 0 || b > 0))
        {
            if (a >= b)
                a /= 2;
            else
                b /= 2;
        }

        if (a < b)
            swap(a, b);
        cout << a << ' ' << b << "\n\n";
    }
    return 0;
}
