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
        int k;
        cin >> k;
        int n = 0;
        for (int i = 0; i < k; ++i)
        {
            n = n * 2 + 1;
        }
        cout << n << '\n';
    }
    return 0;
}
