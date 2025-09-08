#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    long long M, H;
    if (!(cin >> M >> H))
        return 0;
    int N;
    cin >> N;
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        long long C, B;
        cin >> C >> B;
        ans += max(C * M, B * H);
    }
    cout << ans << '\n';
}
