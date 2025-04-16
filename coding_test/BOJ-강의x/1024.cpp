#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    long long N;
    int L;

    cin >> N >> L;

    for (int k = L; k <= 100; ++k)
    {
        long long temp = 2 * N - 1LL * k * (k - 1);
        if (temp < 0)
            continue;
        if (temp % (2 * k) != 0)
            continue;

        long long x = temp / (2 * k);
        for (int i = 0; i < k; ++i)
        {
            cout << x + i << ' ';
        }
        return 0;
    }

    cout << -1 << '\n';
}
