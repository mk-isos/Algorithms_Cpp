#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int main()
{
    FIO;
    ll R, G;
    cin >> R >> G;

    ll g = gcd(R, G);
    vector<ll> divs;

    for (ll i = 1; i * i <= g; i++)
    {
        if (g % i == 0)
        {
            divs.push_back(i);
            if (i != g / i)
                divs.push_back(g / i);
        }
    }

    sort(divs.begin(), divs.end());
    for (ll d : divs)
    {
        cout << d << " " << R / d << " " << G / d << '\n';
    }

    return 0;
}
