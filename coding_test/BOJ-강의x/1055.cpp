#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using ll = long long;
using ld = long double;

const ll LNF = LLONG_MAX;
const ll MXN = (ll)1e9 + 99;

string p, s;
vector<string> notDollar;
ll opCnt, mn, mx;
ll n, dollarCnt = 0, mCnt = 0;

ll fastPow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (a > MXN)
            return LNF;
        if (b & 1)
        {
            if (res > MXN / a)
                return LNF;
            res = res * a;
        }
        b >>= 1;
        if (a > MXN / a)
            a = LNF;
        else
            a = a * a;
    }
    return res;
}

ll f(ll k)
{
    if (--k == 0)
        return (ll)p.size();
    if (dollarCnt == 1)
        return n + mCnt * k;
    ll dk = fastPow(dollarCnt, k);
    if (dk == LNF)
        return LNF;
    return n * dk + mCnt * (dk - 1) / (dollarCnt - 1);
}

int main()
{
    FIO;
    cin >> p >> s >> opCnt >> mn >> mx;

    mn--;
    mx--;

    string seg;
    int dollarSeen = 0;
    for (char c : s)
    {
        if (c == '$')
        {
            dollarCnt++;
            if (dollarSeen != 0)
            {
                notDollar.push_back(seg);
                seg.clear();
            }
            dollarSeen++;
        }
        else
        {
            mCnt++;
            seg.push_back(c);
        }
    }
    if (!seg.empty())
        notDollar.push_back(seg);

    n = p.size();

    ll totalLen = f(opCnt + 1);

    string ans;
    ans.reserve(mx - mn + 1);

    for (ll i = mn; i <= mx; ++i)
    {
        if (i >= totalLen)
        {
            ans.push_back('-');
            continue;
        }
        ll target = i;

        while (target >= (ll)p.size())
        {

            ll lo = 1, hi = (ll)1e9;
            while (lo < hi)
            {
                ll mid = lo + (hi - lo) / 2 + ((hi - lo) % 2);
                if (f(mid) <= target)
                    lo = mid;
                else
                    hi = mid - 1;
            }
            ll lenLo = f(lo);
            target -= lenLo;

            for (auto &part : notDollar)
            {
                if (target < (ll)part.size())
                {
                    ans.push_back(part[target]);
                    target = -1;
                    break;
                }
                target -= part.size();
                if (target < lenLo)
                {
                    break;
                }
                target -= lenLo;
            }
            if (target < 0)
                break;
        }

        if (target >= 0)
            ans.push_back(p[target]);
    }

    cout << ans << "\n";
    return 0;
}
