#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int total = a + b + c + d;
    int minutes = total / 60;
    int seconds = total % 60;

    cout << minutes << '\n'
         << seconds << '\n';
    return 0;
}
