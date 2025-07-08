#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    long long a, b;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        cout << a / b << ' ' << a % b << " / " << b << '\n';
    }
    return 0;
}
