#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using ld = long double;
using cd = complex<ld>;
const ld PI = acosl(-1.0L);

void fft(vector<cd> &a, bool inv)
{
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; ++i)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
        ld ang = 2 * PI / len * (inv ? -1 : 1);
        cd wlen(cosl(ang), sinl(ang));
        for (int i = 0; i < n; i += len)
        {
            cd w(1);
            for (int j = 0; j < len / 2; ++j)
            {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (inv)
    {
        for (int i = 0; i < n; i++)
            a[i] /= n;
    }
}

int main()
{
    FIO;

    string A, B;
    if (!(cin >> A >> B))
        return 0;
    if (A == "0" || B == "0")
    {
        cout << 0 << '\n';
        return 0;
    }

    const int BASE = 1000, WIDTH = 3;
    auto toBlocks = [&](const string &s)
    {
        vector<int> v;
        for (int i = (int)s.size(); i > 0; i -= WIDTH)
        {
            int l = max(0, i - WIDTH);
            v.push_back(stoi(s.substr(l, i - l)));
        }
        return v;
    };

    vector<int> a = toBlocks(A), b = toBlocks(B);
    int n1 = (int)a.size(), n2 = (int)b.size();
    int n = 1;
    while (n < n1 + n2)
        n <<= 1;

    vector<cd> fa(n), fb(n);
    for (int i = 0; i < n1; i++)
        fa[i] = (ld)a[i];
    for (int i = 0; i < n2; i++)
        fb[i] = (ld)b[i];

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<long long> res(n);
    for (int i = 0; i < n; i++)
        res[i] = llroundl(fa[i].real());

    long long carry = 0;
    for (size_t i = 0; i < res.size(); ++i)
    {
        long long cur = res[i] + carry;
        res[i] = cur % BASE;
        carry = cur / BASE;
    }
    while (carry)
    {
        res.push_back(carry % BASE);
        carry /= BASE;
    }
    int i = (int)res.size() - 1;
    while (i > 0 && res[i] == 0)
        --i;

    cout << res[i];
    for (i = i - 1; i >= 0; --i)
    {
        cout << setw(WIDTH) << setfill('0') << res[i];
    }
    cout << '\n';
}
