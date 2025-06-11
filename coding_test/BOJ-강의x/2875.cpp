#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int M, N, K;
    cin >> M >> N >> K;

    int team = min(M / 2, N);

    while (team >= 0)
    {
        int girls_left = M - 2 * team;
        int boys_left = N - team;
        if (girls_left + boys_left >= K)
            break;
        team--;
    }

    cout << team << '\n';
}
