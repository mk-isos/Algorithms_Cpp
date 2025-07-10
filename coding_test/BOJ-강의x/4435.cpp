#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int T;
    cin >> T;

    vector<int> good_worth = {1, 2, 3, 3, 4, 10};
    vector<int> evil_worth = {1, 2, 2, 2, 3, 5, 10};

    for (int battle = 1; battle <= T; ++battle)
    {
        int good_power = 0, evil_power = 0;

        for (int i = 0; i < 6; ++i)
        {
            int cnt;
            cin >> cnt;
            good_power += cnt * good_worth[i];
        }

        for (int i = 0; i < 7; ++i)
        {
            int cnt;
            cin >> cnt;
            evil_power += cnt * evil_worth[i];
        }

        cout << "Battle " << battle << ": ";
        if (good_power > evil_power)
            cout << "Good triumphs over Evil\n";
        else if (good_power < evil_power)
            cout << "Evil eradicates all trace of Good\n";
        else
            cout << "No victor on this battle field\n";
    }

    return 0;
}
