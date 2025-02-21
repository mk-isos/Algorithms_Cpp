#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int l, n;
    double t;
    cin >> l >> n >> t;

    bool canWin = false;

    for (int i = 0; i < n; i++)
    {
        double f, b;
        cin >> f >> b;

        double totalTime = (l / f) + (l / b); // 왕복 걸리는 시간

        if (totalTime < t)
        {
            canWin = true;
        }
    }

    cout << (canWin ? "HOPE" : "DOOMED") << '\n';

    return 0;
}
