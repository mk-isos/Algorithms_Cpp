#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

int n, k, ne, pw = 1, p = -1;
int pv[4200005];

void dfs(int x)
{
    while (pv[x] != n)
    {
        ne = 1LL * x * n % pw + pv[x];
        pv[x]++;
        dfs(ne);
    }
    if (p != -1)
        cout << p << ' ';
    p = x % n;
}

int main()
{
    FIO;
    cin >> n >> k;
    if (--k == 0)
    {
        for (int i = 0; i < n; i++)
            cout << i << ' ';
        return 0;
    }
    for (int i = 1; i <= k; i++)
        pw *= n;
    dfs(0);
    return 0;
}
