#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int A, B, C, D, P;
    cin >> A >> B >> C >> D >> P;

    int x_price = A * P;
    int y_price = B + max(0, (P - C)) * D;

    cout << min(x_price, y_price) << '\n';
}
