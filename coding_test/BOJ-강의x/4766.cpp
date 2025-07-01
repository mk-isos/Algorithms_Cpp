#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{

    FIO;

    double m, n;
    cin >> m;
    while (true)
    {
        cin >> n;
        if (n == 999)
            break;
        else
        {
            cout << fixed << setprecision(2) << n - m << endl;
            m = n;
        }
    }
    return 0;
}
