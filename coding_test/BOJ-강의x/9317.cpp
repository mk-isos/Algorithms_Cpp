#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    cout.setf(ios::fixed);

    cout << setprecision(2);
    double D;
    int RH, RV;
    const long double SQ337 = sqrtl(337.0L);
    while (cin >> D >> RH >> RV)
    {
        if (D == 0.0 && RH == 0 && RV == 0)
            break;
        long double W = 16.0L * (long double)D / SQ337;
        long double H = 9.0L * (long double)D / SQ337;
        long double hDPI = (long double)RH / W;
        long double vDPI = (long double)RV / H;
        cout << "Horizontal DPI: " << (double)hDPI << '\n';
        cout << "Vertical DPI: " << (double)vDPI << '\n';
    }
}
