#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    long long A, B, C;
    cin >> A >> B >> C;

    long long total = A + B;
    long long chickenCost = 2 * C;

    if (total >= chickenCost)
    {
        cout << total - chickenCost << '\n';
    }
    else
    {
        cout << total << '\n';
    }
}
