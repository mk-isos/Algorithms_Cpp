#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<int> S, seq;
int k;

void backtrack(int depth, int start)
{
    if (depth == 6)
    { // 6개를 선택한 경우 출력
        for (int i = 0; i < 6; i++)
            cout << seq[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i < k; i++)
    { // start 이후의 숫자만 선택 (비내림차순 유지)
        seq.push_back(S[i]);
        backtrack(depth + 1, i + 1);
        seq.pop_back();
    }
}

int main()
{
    FIO;

    bool first = true;

    while (true)
    {
        cin >> k;
        if (k == 0)
            break;

        S.resize(k);
        for (int i = 0; i < k; i++)
            cin >> S[i];

        if (!first)
            cout << "\n";
        first = false;

        backtrack(0, 0); // 백트래킹 실행
    }

    return 0;
}
