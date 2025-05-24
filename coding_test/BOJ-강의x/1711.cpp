#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

long long zz(long long t)
{
    return t * t;
}
int main()
{
    FIO;

    int N;
    cin >> N;
    vector<pair<long long, long long>> V(N);
    vector<vector<long long>> dist(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++)
    {
        cin >> V[i].first >> V[i].second;
        for (int j = 0; j < i; j++)
        {
            dist[j][i] = zz(V[i].first - V[j].first) + zz(V[i].second - V[j].second);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                long long a, b, c, d;
                a = dist[i][j];
                b = dist[j][k];
                c = dist[i][k];
                d = max({a, b, c});
                if (d == a + b + c - d)
                {
                    ans += 1;
                }
            }
        }
    }
    cout << ans;
    return 0;
}