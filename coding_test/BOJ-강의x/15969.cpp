#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int N;
    cin >> N;
    int maxScore = 0, minScore = 1000;
    for (int i = 0; i < N; ++i)
    {
        int score;
        cin >> score;
        maxScore = max(maxScore, score);
        minScore = min(minScore, score);
    }
    cout << maxScore - minScore << '\n';
}
