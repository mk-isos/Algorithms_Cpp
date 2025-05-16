#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int H, W;
    cin >> H >> W;

    int min_side = min(H, W);
    int radius_cm = (min_side * 100) / 2;

    cout << radius_cm << '\n';
    return 0;
}
