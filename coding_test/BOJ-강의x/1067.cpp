#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using ll = long long;
const int MOD = 998244353, G = 3;

int modpow(ll a, ll e)
{
    ll r = 1;
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
    rev.resize(n);
    for (int i = 0; i < n; i++)
    {
        rev[i] = 0;
        for (int b = 0; b < lg; b++)
            if (i >> b & 1)
                rev[i] |= 1 << (lg - 1 - b);
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
                int v = (int)((ll)a[i + j + len] * w % MOD);
                int x = u + v;
                if (x >= MOD)
                    x -= MOD;
                int y = u - v;
                if (y < 0)
                    y += MOD;
                a[i + j] = x;
                a[i + j + len] = y;
                w = (int)((ll)w * wlen % MOD);
            }
        }
    }
    if (inv)
    {
        int invn = modpow(n, MOD - 2);
        for (int &x : a)
            x = (int)((ll)x * invn % MOD);
    }
}

int main()
{
    FIO;

    int N;
    if (!(cin >> N))
        return 0;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++)
        cin >> X[i];
    for (int i = 0; i < N; i++)
        cin >> Y[i];

    int need = N + 2 * N - 1;
    int L = 1;
    while (L < need)
        L <<= 1;

    vector<int> A(L, 0), B(L, 0);
    for (int i = 0; i < N; i++)
        A[i] = X[N - 1 - i] % MOD;
    for (int i = 0; i < 2 * N; i++)
        B[i] = Y[i % N] % MOD;

    ntt(A, false);
    ntt(B, false);
    for (int i = 0; i < L; i++)
        A[i] = (int)((ll)A[i] * B[i] % MOD);
    ntt(A, true);

    long long ans = 0;
    for (int k = 0; k < N; k++)
    {
        long long v = A[k + (N - 1)];
        if (v > ans)
            ans = v;
    }
    cout << ans << '\n';
}
