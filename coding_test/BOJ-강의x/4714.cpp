#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    double x;
    while (cin >> x)
    {
        if (x < 0)
            break;
        double moon = x * 0.167;
        cout << fixed << setprecision(2);
        cout << "Objects weighing " << x << " on Earth will weigh " << moon << " on the moon." << endl;
    }

    return 0;
}
