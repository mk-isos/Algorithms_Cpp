#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    long long A, B, C;
    cin >> A >> B >> C;

    if (A + B == C)
        cout << "correct!" << '\n';
    else
        cout << "wrong!" << '\n';

    return 0;
}
