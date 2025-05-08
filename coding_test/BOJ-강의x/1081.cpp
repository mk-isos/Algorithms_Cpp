#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using ll = long long;

ll dp[20][2][200]; // dp[position][tight][sum] position - 현재 자리, tight - 제한 여부, sum - 현재까지의 합

string num_str;

ll digit_dp(int pos, bool tight, int sum)
{
    if (pos == num_str.size())
        return sum;
    if (dp[pos][tight][sum] != -1)
        return dp[pos][tight][sum];

    int limit = tight ? num_str[pos] - '0' : 9;
    ll res = 0;
    for (int d = 0; d <= limit; ++d)
    {
        res += digit_dp(pos + 1, tight && (d == limit), sum + d);
    }
    return dp[pos][tight][sum] = res;
}

ll solve(ll n)
{
    if (n < 0)
        return 0;
    num_str = to_string(n);
    memset(dp, -1, sizeof(dp));
    return digit_dp(0, true, 0);
}

int main()
{
    FIO;
    ll L, U;
    cin >> L >> U;
    cout << solve(U) - solve(L - 1) << '\n';
    return 0;
}
