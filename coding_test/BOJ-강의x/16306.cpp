#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int V;
    cin >> V;
    int min_surface = INT_MAX;

    for (int l = 1; l * l * l <= V; ++l)
    {
        if (V % l != 0)
            continue;
        for (int w = l; l * w * w <= V; ++w)
        {
            if ((V / l) % w != 0)
                continue;
            int h = V / (l * w);
            int surface = 2 * (l * w + w * h + h * l);
            min_surface = min(min_surface, surface);
        }
    }

    cout << min_surface << '\n';
    return 0;
}
