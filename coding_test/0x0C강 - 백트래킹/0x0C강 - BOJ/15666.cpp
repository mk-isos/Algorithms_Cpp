#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
int numbers[10], seq[10];
int uniqueNumbers[10], uniqueSize = 0;

void backtrack(int depth, int start)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
            cout << seq[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i < uniqueSize; i++)
    {
        seq[depth] = uniqueNumbers[i];
        backtrack(depth + 1, i); // `i`를 유지하여 같은 숫자 선택 가능
    }
}

int main()
{
    FIO;
    cin >> N >> M;

    int temp[10];
    for (int i = 0; i < N; i++)
        cin >> temp[i];

    // 정렬 후 중복 제거
    sort(temp, temp + N); // 사전 순
    uniqueSize = 0;
    for (int i = 0; i < N; i++)
    {
        if (i == 0 || temp[i] != temp[i - 1])
        {
            uniqueNumbers[uniqueSize++] = temp[i];
        }
    }

    backtrack(0, 0); // 백트래킹 실행

    return 0;
}
