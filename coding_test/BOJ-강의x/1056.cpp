#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;

const int MAX_EXP = 63;
ll a[MAX_EXP];
unordered_map<ll, ll> dp;

ll pw(ll base, ll exp)
{
    ll result = 1;
    while (exp--)
    {
        if (result > LLONG_MAX / base)
            return LLONG_MAX;
        result *= base;
    }
    return result;
}

ll limf(ll exp)
{
    ll l = 2, r = (1LL << 45), res = 1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (exp * log(mid) <= log((1LL << 63) - 1))
        {
            res = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}

ll lower_bound_pow(ll x, ll exp, ll limit)
{
    ll l = 1, r = limit, res = limit;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (pw(mid, exp) >= x)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}

ll solve(ll n)
{
    if (n == 1)
        return 0;
    if (dp.count(n))
        return dp[n];
    ll &res = dp[n];
    res = n - 1;

    for (ll exp = 61; exp >= 2; --exp)
    {
        ll r = lower_bound_pow(n, exp, a[exp]);
        ll l = r - 1;

        if (r > 1)
        {
            ll pow_r = pw(r, exp);
            if (pow_r != LLONG_MAX)
                res = min(res, solve(r) + abs(n - pow_r) + 1);
        }
        if (l > 1)
        {
            ll pow_l = pw(l, exp);
            if (pow_l != LLONG_MAX)
                res = min(res, solve(l) + abs(n - pow_l) + 1);
        }
    }

    return res;
}

int main()
{
    FIO;

    ll n;
    cin >> n;
    for (int i = 2; i < MAX_EXP; ++i)
    {
        a[i] = limf(i);
    }
    cout << solve(n) << '\n';
}
