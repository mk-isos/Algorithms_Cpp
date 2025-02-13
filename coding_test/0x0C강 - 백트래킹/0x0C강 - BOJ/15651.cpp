#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
vector<int> seq;

void backtrack()
{
    if (seq.size() == M)
    {
        for (int num : seq)
        {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        seq.push_back(i);
        // backtrack(i+1); // 중복 선택 불가능
        backtrack(); // 중복 선택 가능
        seq.pop_back();
    }
}

int main()
{
    FIO;

    cin >> N >> M;
    backtrack();
    return 0;
}