#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int M, S, G;
    if (!(cin >> M >> S >> G))
        return 0;
    double A, B;
    cin >> A >> B;
    int L, R;
    cin >> L >> R;

    double wait_left = L / A;
    double wait_right = R / B;

    double ride_left = (double)M / G;
    double ride_right = (double)M / S;

    double t_left = wait_left + ride_left;
    double t_right = wait_right + ride_right;

    if (t_left < t_right)
        cout << "friskus\n";
    else
        cout << "latmask\n";
    return 0;
}
