#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n, T;
    int enter, departure;
    int x, y, r, x1, y1, x2, y2;

    cin >> T;

    while (T--)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        cin >> n;

        enter = 0;
        departure = 0;
        while (n--)
        {
            cin >> x >> y >> r;

            if ((x - x1) * (x - x1) + (y - y1) * (y - y1) < r * r)
                if ((x - x2) * (x - x2) + (y - y2) * (y - y2) > r * r)
                    departure++;

            if ((x - x1) * (x - x1) + (y - y1) * (y - y1) > r * r)
                if ((x - x2) * (x - x2) + (y - y2) * (y - y2) < r * r)
                    enter++;
        }

        cout << enter + departure << '\n';
    }
}