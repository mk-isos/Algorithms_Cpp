#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    long long a, d, v;
    while (cin >> a >> d >> v)
    {
        if (a == 0 && d == 0 && v == 0)
            break;

        if (d != 0 && (v - a) % d == 0)
        {
            long long n = (v - a) / d + 1; // 1-based term index
            if (n >= 1)
                cout << n << '\n';
            else
                cout << "X\n";
        }
        else
        {
            cout << "X\n";
        }
    }
    return 0;
}
