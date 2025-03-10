#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int N, T, P;
    cin >> N;

    vector<int> sizes(6);
    for (int i = 0; i < 6; i++)
    {
        cin >> sizes[i];
    }

    cin >> T >> P;

    int min_shirt_bundles = 0;
    for (int i = 0; i < 6; i++)
    {
        min_shirt_bundles += (sizes[i] + T - 1) / T; // 올림(ceil) 계산
    }

    cout << min_shirt_bundles << "\n";

    cout << N / P << " " << N % P << "\n";

    return 0;
}