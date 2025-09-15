#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n;
    if (!(cin >> n))
        return 0;
    bool needBase = true;
    int base = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (needBase)
        {
            base = x;
            needBase = false;
        }
        else if (x % base == 0)
        {
            cout << x << '\n';
            needBase = true;
        }
    }
}
