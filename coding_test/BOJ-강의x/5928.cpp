#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int D, H, M;
    cin >> D >> H >> M;

    // 기준 시각: 11일 11시 11분
    int start = (11 * 24 * 60) + (11 * 60) + 11;
    int end = (D * 24 * 60) + (H * 60) + M;

    if (end < start)
        cout << -1;
    else
        cout << end - start;

    return 0;
}
