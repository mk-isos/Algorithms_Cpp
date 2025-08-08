#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int d, s1, s2;
    while (cin >> d >> s1 >> s2)
    {
        if (d == 0 && s1 == 0 && s2 == 0)
            break;

        double t1 = (double)d / s1;
        double t2 = (double)d / s2;
        double diff = (t1 - t2) * 3600;
        int total_seconds = (int)(diff + 0.5);

        int h = total_seconds / 3600;
        int m = (total_seconds % 3600) / 60;
        int s = total_seconds % 60;

        cout << h << ":"
             << setw(2) << setfill('0') << m << ":"
             << setw(2) << setfill('0') << s << "\n";
    }
    return 0;
}
