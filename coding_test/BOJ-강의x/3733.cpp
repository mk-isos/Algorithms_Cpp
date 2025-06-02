#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int N, S;
    while (cin >> N >> S)
    {
        cout << S / (N + 1) << '\n';
    }
    return 0;
}
