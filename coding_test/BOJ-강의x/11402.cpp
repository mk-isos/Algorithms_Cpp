#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using ull = unsigned long long;
using ll = long long;

ll modpow(ll a, ll e, ll m)
{
    ll r = 1 % m;
    a %= m;
    while (e)
    {
        if (e & 1)
            r = (__int128)r * a % m;
        a = (__int128)a * a % m;
        e >>= 1;
    }
    return r;
}

int main()
{
    FIO;

    ull N, K;
    int M;
    if (!(cin >> N >> K >> M))
        return 0;

    vector<int> fact(M, 1), invfact(M, 1);
    for (int i = 1; i < M; i++)
        fact[i] = (ll)fact[i - 1] * i % M;
    invfact[M - 1] = modpow(fact[M - 1], M - 2, M);
    for (int i = M - 2; i >= 0; i--)
        invfact[i] = (ll)invfact[i + 1] * (i + 1) % M;

    auto Csmall = [&](int n, int k) -> int
    {
        if (k < 0 || k > n)
            return 0;
        return (ll)fact[n] * invfact[k] % M * invfact[n - k] % M;
    };

    int ans = 1;
    ull n = N, k = K;
    while (n > 0 || k > 0)
    {
        int ni = n % M;
        int ki = k % M;
        if (ki > ni)
        {
            ans = 0;
            break;
        }
        ans = (ll)ans * Csmall(ni, ki) % M;
        n /= M;
        k /= M;
    }
    cout << ans << '\n';
}
