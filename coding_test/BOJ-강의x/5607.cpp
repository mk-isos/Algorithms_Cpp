#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n;
    if (!(cin >> n))
        return 0;
    long long A = 0, B = 0;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            A += a + b;
        else if (a < b)
            B += a + b;
        else
        {
            A += a;
            B += b;
        }
    }
    cout << A << ' ' << B << '\n';
}
