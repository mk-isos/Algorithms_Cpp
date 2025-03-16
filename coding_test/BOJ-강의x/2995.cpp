#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N;
vector<pair<int, int>> Scopes, Answer;

void input()
{
    cin >> N;
    Scopes.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Scopes[i].first >> Scopes[i].second;
        Scopes[i].second *= -1; // B를 음수로 변환하여 정렬 시 내림차순 유지
    }
}

vector<pair<int, int>> findScopes()
{
    vector<pair<int, int>> Result;
    vector<int> DP, Indices, PrevIndices(N, -1);

    for (int i = 0; i < N; i++)
    {
        auto it = upper_bound(DP.begin(), DP.end(), Scopes[i].second);
        int idx = it - DP.begin();

        if (it == DP.end())
        {
            DP.push_back(Scopes[i].second);
            Indices.push_back(i);
        }
        else
        {
            *it = Scopes[i].second;
            Indices[idx] = i;
        }

        if (idx > 0)
        {
            PrevIndices[i] = Indices[idx - 1];
        }
    }

    // LIS 추적
    int current = Indices.back();
    while (current != -1)
    {
        Result.push_back(Scopes[current]);
        current = PrevIndices[current];
    }

    reverse(Result.begin(), Result.end());
    return Result;
}

bool comp(pair<int, int> A, pair<int, int> B)
{
    if (A.first == B.first)
        return (A.second < B.second);
    return (A.first < B.first);
}

void settings()
{
    sort(Scopes.begin(), Scopes.end(), comp);
    Answer = findScopes();
}

void printAnswer()
{
    cout << (int)Answer.size() << "\n";
    for (auto &scope : Answer)
    {
        cout << scope.first << " " << -scope.second << "\n";
    }
}

int main()
{
    FIO;
    input();
    settings();
    printAnswer();
    return 0;
}
