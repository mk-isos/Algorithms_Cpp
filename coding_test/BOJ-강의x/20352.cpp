#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    double A;
    cin >> A;
    double r = sqrt(A / M_PI);
    double C = 2 * M_PI * r;
    cout << fixed << setprecision(10) << C << '\n';
    return 0;
}
