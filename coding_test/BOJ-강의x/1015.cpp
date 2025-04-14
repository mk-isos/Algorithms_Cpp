#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    vector<int> P(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++)
    {
        P[A[i].second] = i;
    }
    for (auto r : P)
        cout << r << " ";
}