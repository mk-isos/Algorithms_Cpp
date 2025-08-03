#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    long long n;
    cin >> n;

    while (true)
    {
        cout << n;
        if (n == 1)
            break;
        cout << ' ';
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
    }

    cout << '\n';
    return 0;
}
