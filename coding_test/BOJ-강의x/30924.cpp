#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());
    vector<int> cand(10000);
    iota(cand.begin(), cand.end(), 1);

    for (int tc = 0; tc < 10; ++tc)
    {
        vector<int> Aord = cand, Bord = cand;
        shuffle(Aord.begin(), Aord.end(), rng);
        shuffle(Bord.begin(), Bord.end(), rng);

        int resp, a = -1, b = -1;

        for (int x : Aord)
        {
            cout << "? A " << x << endl;
            if (!(cin >> resp))
                return 0;
            if (resp == 1)
            {
                a = x;
                break;
            }
        }
        for (int x : Bord)
        {
            cout << "? B " << x << endl;
            if (!(cin >> resp))
                return 0;
            if (resp == 1)
            {
                b = x;
                break;
            }
        }
        cout << "! " << (a + b) << endl;
    }

    return 0;
}
