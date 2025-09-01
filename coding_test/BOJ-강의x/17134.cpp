#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

const int MAXN = 1000000;
const int MOD = 998244353;
const int G = 3;

int modpow(long long a, long long e)
{
    long long r = 1;
    while (e)
    {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return (int)r;
}

void ntt(vector<int> &a, bool inv)
{
    int n = (int)a.size();
    static vector<int> rev;
    int lg = 0;
    while ((1 << lg) < n)
        ++lg;
    rev.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int b = 0; b < lg; b++)
            if (i >> b & 1)
                x |= 1 << (lg - 1 - b);
        rev[i] = x;
    }
    for (int i = 0; i < n; i++)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int len = 1; len < n; len <<= 1)
    {
        int wlen = modpow(G, (MOD - 1) / (2 * len));
        if (inv)
            wlen = modpow(wlen, MOD - 2);
        for (int i = 0; i < n; i += 2 * len)
        {
            int w = 1;
            for (int j = 0; j < len; j++)
            {
                int u = a[i + j];
                int v = (int)((1LL * a[i + j + len] * w) % MOD);
                int x = u + v;
                if (x >= MOD)
                    x -= MOD;
                int y = u - v;
                if (y < 0)
                    y += MOD;
                a[i + j] = x;
                a[i + j + len] = y;
                w = (int)((1LL * w * wlen) % MOD);
            }
        }
    }
    if (inv)
    {
        int invn = modpow(n, MOD - 2);
        for (int &x : a)
            x = (int)((1LL * x * invn) % MOD);
    }
}

int main()
{
    FIO;

    int T;
    if (!(cin >> T))
        return 0;
    vector<int> Ns(T);
    int maxN = 0;
    for (int i = 0; i < T; i++)
    {
        cin >> Ns[i];
        if (Ns[i] > maxN)
            maxN = Ns[i];
    }
    if (maxN < 6)
    {
        for (int i = 0; i < T; i++)
            cout << 0 << '\n';
        return 0;
    }
    if (maxN > MAXN)
        maxN = MAXN;

    vector<char> isP(maxN + 1, true);
    isP[0] = isP[1] = false;
    for (int i = 2; i * (long long)i <= maxN; i++)
        if (isP[i])
            for (long long j = 1LL * i * i; j <= maxN; j += i)
                isP[(int)j] = false;

    int need = 2 * maxN + 1;
    int L = 1;
    while (L < need)
        L <<= 1;

    vector<int> A(L, 0), B(L, 0);
    for (int i = 3; i <= maxN; i++)
        if (isP[i])
            A[i] = 1;
    for (int q = 2; 2 * q <= maxN; q++)
        if (isP[q])
            B[2 * q] = 1;

    ntt(A, false);
    ntt(B, false);
    for (int i = 0; i < L; i++)
        A[i] = (int)((1LL * A[i] * B[i]) % MOD);
    ntt(A, true);

    for (int i = 0; i < T; i++)
    {
        int N = Ns[i];
        if (N < 7 || N > maxN)
        {
            cout << 0 << '\n';
            continue;
        }
        cout << A[N] << '\n';
    }
}
