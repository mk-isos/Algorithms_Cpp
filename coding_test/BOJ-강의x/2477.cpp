#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    pair<int, int> len[12];
    int k, d, l, big_area, small_area;

    cin >> k;

    for (int i = 0; i < 6; i++)
    {
        cin >> d >> l;
        len[i] = len[i + 6] = {d, l};
    }

    for (int i = 3; i < 12; i++)
    {
        if (len[i].first == len[i - 2].first && len[i - 1].first == len[i - 3].first)
        {

            big_area = len[i + 1].second * len[i + 2].second;
            small_area = len[i - 1].second * len[i - 2].second;
            break;
        }
    }

    cout << k * (big_area - small_area) << '\n';
    return 0;
}
