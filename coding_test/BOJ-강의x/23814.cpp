#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    long long D, N, M, K;

    if (!(cin >> D))
        return 0;
    cin >> N >> M >> K;

    long long r1 = N % D, r2 = M % D;
    vector<pair<long long, int>> sp;
    if (r1)
        sp.push_back({D - r1, 1});
    if (r2)
        sp.push_back({D - r2, 2});

    sort(sp.begin(), sp.end());

    vector<long long> pref(1, 0);
    for (auto &e : sp)
        pref.push_back(pref.back() + e.first);
    long long bestVal = -1, bestPref = 0;
    int bestT = 0;

    for (int t = 0; t < (int)pref.size(); ++t)
    {
        if (pref[t] > K)
            continue;
        long long val = t + (K - pref[t]) / D;
        if (val > bestVal || (val == bestVal && pref[t] < bestPref))
        {
            bestVal = val;
            bestPref = pref[t];
            bestT = t;
        }
    }
    long long addN = 0, addM = 0;

    for (int i = 0; i < bestT; i++)
    {
        if (sp[i].second == 1)
            addN += sp[i].first;
        else
            addM += sp[i].first;
    }

    long long fried = K - addN - addM;
    cout << fried << '\n';
}
