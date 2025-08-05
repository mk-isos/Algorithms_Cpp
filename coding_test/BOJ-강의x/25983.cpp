#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        cout << a << ' ' << b << ' ' << c << '\n';

        int count = 0;
        if (a >= 10)
            count++;
        if (b >= 10)
            count++;
        if (c >= 10)
            count++;

        if (count == 0)
            cout << "zilch\n";
        else if (count == 1)
            cout << "double\n";
        else if (count == 2)
            cout << "double-double\n";
        else
            cout << "triple-double\n";

        cout << '\n';
    }
    return 0;
}
