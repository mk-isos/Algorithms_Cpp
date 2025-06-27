#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int S, T, D;
    cin >> S >> T >> D;

    cout << (T * D) / (2 * S) << '\n';
    return 0;
}
