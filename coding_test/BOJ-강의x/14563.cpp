#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int T;
    cin >> T;
    while (T--)
    {
        int n, sum = 0;
        cin >> n;
        for (int i = 1; i < n; ++i)
        {
            if (n % i == 0)
                sum += i;
        }
        if (sum == n)
            cout << "Perfect\n";
        else if (sum > n)
            cout << "Abundant\n";
        else
            cout << "Deficient\n";
    }
    return 0;
}
