#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n;
    cin >> n;

    cout << fixed << setprecision(2);

    for (int i = 0; i < n; ++i)
    {
        double area, base;
        cin >> area >> base;
        double height = (2 * area) / base;
        cout << "The height of the triangle is " << height << " units\n";
    }

    return 0;
}
