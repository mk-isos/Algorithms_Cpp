#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using u64 = unsigned long long;
using u128 = __uint128_t;

u64 modmul(u64 a, u64 b, u64 m) { return (u128)a * b % m; }
u64 modpow(u64 a, u64 e, u64 m)
{
    u64 r = 1 % m;
    while (e)
    {
        if (e & 1)
            r = modmul(r, a, m);
        a = modmul(a, a, m);
        e >>= 1;
    }
    return r;
}

bool isPrime(u64 n)
{
    if (n < 2)
        return false;
    for (u64 p : {2ull, 3ull, 5ull, 7ull, 11ull, 13ull, 17ull, 19ull, 23ull, 29ull, 31ull, 37ull})
    {
        if (n % p == 0)
            return n == p;
    }
    u64 d = n - 1, s = 0;
    while ((d & 1) == 0)
    {
        d >>= 1;
        ++s;
    }
    for (u64 a : {2ull, 3ull, 5ull, 7ull, 11ull})
    {
        if (a % n == 0)
            continue;
        u64 x = modpow(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool ok = false;
        for (u64 r = 1; r < s; ++r)
        {
            x = modmul(x, x, n);
            if (x == n - 1)
            {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    return true;
}

int main()
{
    FIO;

    int N;
    if (!(cin >> N))
        return 0;
    long long cnt = 0;
    for (int i = 0; i < N; i++)
    {
        long long a;
        cin >> a;
        u64 m = 2ull * (u64)a + 1ull;
        if (m == 1ull || isPrime(m))
            ++cnt;
    }
    cout << cnt << '\n';
}
