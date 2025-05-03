#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int X;
    cin >> X;

    int count = 0;
    while (X > 0)
    {
        if (X % 2 == 1)
            count++;
        X /= 2;
    }

    cout << count << '\n';
}
