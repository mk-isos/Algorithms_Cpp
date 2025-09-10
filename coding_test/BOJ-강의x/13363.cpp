#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n1, n2;
    if (!(cin >> n1 >> n2))
        return 0;
    int diff = ((n2 - n1 + 540) % 360) - 180; // in (-180, 180]
    if (diff == -180)
        diff = 180; // diametrically opposed -> clockwise
    cout << diff << '\n';
}
