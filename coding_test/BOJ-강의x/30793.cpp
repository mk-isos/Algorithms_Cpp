#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    long long p, r;
    if (!(cin >> p >> r))
        return 0;
    long long t = 5 * p;
    if (t < r)
        cout << "weak\n";
    else if (t < 2 * r)
        cout << "normal\n";
    else if (t < 3 * r)
        cout << "strong\n";
    else
        cout << "very strong\n";
}
