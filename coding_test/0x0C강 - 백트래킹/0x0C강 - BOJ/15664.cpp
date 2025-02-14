// 중복을 허용하면서도, 같은 조합이 여러 번 출력되지 않도록

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
int num[10], seq[10];

void backtrack(int depth, int start)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << seq[i] << " ";
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = start; i < N; i++)
    {
        if (tmp != num[i]) // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
        {
            seq[depth] = num[i];
            tmp = num[i];
            backtrack(depth + 1, i + 1);
        }
    }
}

int main()
{
    FIO;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> num[i];

    sort(num, num + N);

    backtrack(0, 0);

    return 0;
}
