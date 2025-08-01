#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int X, Y;

    cin >> X >> Y;
    if (X > 7)
        cout << X - 7;
    else
        cout << Y + 7;
}
