#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int N;
    cin >> N;
    vector<pair<int, int>> people(N);

    for (int i = 0; i < N; i++)
    {
        cin >> people[i].first >> people[i].second;
    }

    vector<int> ranks(N, 1); // (기본 등수는 1등)

    // 모든 사람을 비교하는 브루트포스 방식
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            if (people[i].first < people[j].first && people[i].second < people[j].second)
            {
                ranks[i]++;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << ranks[i] << " ";
    }

    return 0;
}
