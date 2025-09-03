#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int T;
    if (!(cin >> T))
        return 0;
    for (int tc = 0; tc < T; ++tc)
    {
        int n;
        cin >> n;
        int sum = 1;
        for (int i = 2; i * (long long)i <= n; ++i)
        {
            if (n % i == 0)
            {
                sum += i;
                int j = n / i;
                if (j != i)
                    sum += j;
            }
        }
        if (sum < n)
            cout << n << " is a deficient number.\n";
        else if (sum == n)
            cout << n << " is a perfect number.\n";
        else
            cout << n << " is an abundant number.\n";
        if (tc != T - 1)
            cout << '\n';
    }
}
