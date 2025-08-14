#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    long long w, l, h;
    if (!(cin >> w))
        return 0;
    cin >> l >> h;
    long long a = min(w, l), b = max(w, l);
    if (a >= 2 * h && b <= 2 * a)
        cout << "good\n";
    else
        cout << "bad\n";
}
