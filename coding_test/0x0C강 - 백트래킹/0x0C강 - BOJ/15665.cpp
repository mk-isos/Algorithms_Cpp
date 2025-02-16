#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
int numbers[10], seq[10];

vector<bool> chk(10002);

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

    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (!chk[x])
        { // 중복된 값이 아니라면
            chk[x] = true;
            numbers[idx++] = x;
        }
    }

    N = idx;
    sort(numbers, numbers + N);

    backtrack(0);

    return 0;
}
