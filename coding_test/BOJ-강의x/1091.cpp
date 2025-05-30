#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int N;
    cin >> N;
    vector<int> P(N), S(N), card(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];
    for (int i = 0; i < N; ++i)
        cin >> S[i];
    for (int i = 0; i < N; ++i)
        card[i] = i;

    set<vector<int>> visited;
    int count = 0;

    while (true)
    {
        bool matched = true;
        for (int i = 0; i < N; ++i)
        {
            if (P[card[i]] != i % 3)
            {
                matched = false;
                break;
            }
        }
        if (matched)
        {
            cout << count << '\n';
            break;
        }
        if (visited.count(card))
        {
            cout << -1 << '\n';
            break;
        }
        visited.insert(card);
        vector<int> new_card(N);
        for (int i = 0; i < N; ++i)
        {
            new_card[S[i]] = card[i];
        }
        card = new_card;
        ++count;
    }
    return 0;
}
