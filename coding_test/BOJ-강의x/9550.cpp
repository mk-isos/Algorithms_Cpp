#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N >> K;
        int totalKids = 0;
        for (int i = 0; i < N; i++)
        {
            int candyCount;
            cin >> candyCount;
            totalKids += (candyCount / K);
        }
        cout << totalKids << '\n';
    }
    return 0;
}
