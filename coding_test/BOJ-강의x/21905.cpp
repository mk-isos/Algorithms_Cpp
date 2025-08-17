#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n;
    if (!(cin >> n))
        return 0;
    vector<long long> p(n + 1), s(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        s[i] = s[i - 1] + p[i];
    }

    priority_queue<long long> pq;
    pq.push(s[n]);
    long long ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        long long t = pq.top();
        if (t - s[i] > 0)
        {
            ans += t - s[i];
            pq.pop();
            pq.push(s[i]);
        }
        pq.push(s[i]);
    }
    cout << ans << '\n';
}
