#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
int numbers[10], seq[10];

void backtrack(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << seq[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++)
    {
        seq[depth] = numbers[i];
        backtrack(depth + 1);
    }
}

int main()
{
    FIO;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    sort(numbers, numbers + N);

    backtrack(0);

    return 0;
}
