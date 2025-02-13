#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
vector<int> numbers, seq;
vector<bool> used;

void backtrack()
{
    if (seq.size() == M)
    {
        for (int num : seq)
            cout << num << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!used[i])
        {

            used[i] = true;
            seq.push_back(numbers[i]);

            backtrack();

            seq.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    FIO;

    cin >> N >> M;

    numbers.resize(N);
    used.resize(N, false);

    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    backtrack();
    return 0;
}
