// 살짝 헷갈렸음

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
int numbers[10], seq[10];
bool used[10];

void backtrack(int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << seq[i] << " ";
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        if (!used[i] && tmp != numbers[i])
        { // 중복 수열 거르기
            used[i] = true;
            seq[depth] = numbers[i];
            tmp = numbers[i]; // 현재 선택한 값 저장 (다음 루프에서 중복 체크)
            backtrack(depth + 1);
            used[i] = false;
        }
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
