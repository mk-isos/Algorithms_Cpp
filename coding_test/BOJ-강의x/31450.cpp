#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    long long m, k;
    cin >> m >> k;

    if (m % k == 0)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
