#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int N;
    if (!(cin >> N))
        return 0;
    vector<char> seen(10000, 0);
    int cur = N, cnt = 0;
    while (1)
    {
        int mid = ((cur / 100) % 10) * 10 + ((cur / 10) % 10);
        int nxt = mid * mid;
        ++cnt;
        if (seen[nxt])
            break;
        seen[nxt] = 1;
        cur = nxt;
    }
    cout << cnt << '\n';
}
