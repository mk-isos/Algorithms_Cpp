#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N;
int cnt[1001], total;
vector<int> answer;
bool found = false;

void dfs(int last)
{
    if (found)
        return;
    if (answer.size() == total)
    {
        for (int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << (i + 1 < total ? ' ' : '\n');
        }
        found = true;
        return;
    }
    for (int i = 0; i <= 1000; i++)
    {
        if (cnt[i] == 0)
            continue;
        if (i == last + 1)
            continue;
        cnt[i]--;
        answer.push_back(i);
        dfs(i);
        answer.pop_back();
        cnt[i]++;
        if (found)
            return;
    }
}

int main()
{
    FIO;
    cin >> N;
    total = N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    dfs(-2);
}
