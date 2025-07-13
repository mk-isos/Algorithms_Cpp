#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int N, P;
    cin >> N >> P;

    int result = P;

    if (N >= 20)
        result = min(result, P * 75 / 100);
    if (N >= 15)
        result = min(result, P - 2000);
    if (N >= 10)
        result = min(result, P * 90 / 100);
    if (N >= 5)
        result = min(result, P - 500);

    cout << max(result, 0) << '\n';

    return 0;
}
