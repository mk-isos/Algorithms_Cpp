#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n, k;
    if (!(cin >> n >> k))
        return 0;
    long long s = 0;
    for (int i = 0; i < k; i++)
    {
        int r;
        cin >> r;
        s += r;
    }
    int rem = n - k;
    cout.setf(ios::fixed);
    cout << setprecision(10)
         << (s - 3LL * rem) / (double)n << ' '
         << (s + 3LL * rem) / (double)n << '\n';
}
