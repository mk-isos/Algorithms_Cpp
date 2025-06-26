#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;

    int time = 0;

    if (A < 0)
    {
        time = abs(A) * C + D + B * E;
    }
    else if (A == 0)
    {
        time = D + B * E;
    }
    else
    {
        time = (B - A) * E;
    }

    cout << time << '\n';
}
