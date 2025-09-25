// 158/161

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using u64 = unsigned long long;
using u128 = __uint128_t;

u64 mul_mod(u64 a, u64 b, u64 m) { return (u128)a * b % m; }
u64 pow_mod(u64 a, u64 e, u64 m)
{
    u64 r = 1 % m;
    a %= m;
    while (e)
    {
        if (e & 1)
            r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
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
    for (u64 a : {2ull, 3ull, 5ull, 7ull, 11ull, 13ull})
    {
        if (a % n == 0)
            continue;
        u64 x = pow_mod(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool ok = false;
        for (u64 r = 1; r < s; ++r)
        {
            x = mul_mod(x, x, n);
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
u64 rng64()
{
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    return rng();
}
u64 pollard(u64 n)
{
    if (n % 2 == 0)
        return 2;
    while (true)
    {
        u64 c = (rng64() % (n - 2)) + 1;
        u64 x = (rng64() % (n - 2)) + 2, y = x, d = 1;
        auto f = [&](u64 v)
        { return (mul_mod(v, v, n) + c) % n; };
        while (d == 1)
        {
            x = f(x);
            y = f(f(y));
            u64 diff = x > y ? x - y : y - x;
            d = std::gcd(diff, n);
        }
        if (d != n)
            return d;
    }
}
void factor(u64 n, vector<u64> &out)
{
    if (n == 1)
        return;
    if (isPrime(n))
    {
        out.push_back(n);
        return;
    }
    u64 d = pollard(n);
    factor(d, out);
    factor(n / d, out);
}

int main()
{
    FIO;
    u64 n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<u64> fac;
        factor(n, fac);
        sort(fac.begin(), fac.end());
        for (u64 p : fac)
            cout << p << '\n';
        cout << '\n';
    }
}
