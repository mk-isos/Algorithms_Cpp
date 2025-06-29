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
        int a, b, c;
        cin >> a >> b >> c;
        int count = 0;
        for (int x = 1; x <= a; ++x)
        {
            for (int y = 1; y <= b; ++y)
            {
                for (int z = 1; z <= c; ++z)
                {
                    int r1 = x % y;
                    int r2 = y % z;
                    int r3 = z % x;
                    if (r1 == r2 && r2 == r3)
                    {
                        count++;
                    }
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}
