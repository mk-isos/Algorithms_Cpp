// 백트래킹 ㄹㅇ 못해먹겠다. 그리고 permutation도 연습해봐야하는데... 으아

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int board[51][9];
int order[9];
bool isused[9];
int n, ans;

void run()
{
    int score = 0;
    int idx = 0;

    for (int inning = 0; inning < n; inning++)
    {
        int outCnt = 0;
        bool base[4] = {};

        while (outCnt < 3)
        {
            int hitter = order[idx];
            int result = board[inning][hitter];
            idx = (idx + 1) % 9;

            if (result == 0)
            {
                outCnt++;
                continue;
            }

            // 주자 및 타자 진루 처리
            for (int i = 3; i >= 0; i--)
            {
                if (!base[i])
                    continue;
                if (i + result >= 4)
                    score++;
                else
                    base[i + result] = true;
                base[i] = false;
            }

            // 타자 진루
            if (result >= 4)
                score++;
            else
                base[result] = true;
        }
    }

    ans = max(ans, score);
}

// 백트래킹으로 타순 조합 생성 (1번 선수는 4번 타순 고정)
void brute(int k)
{
    if (k == 9)
    {
        run();
        return;
    }

    if (k == 3)
    {
        order[k] = 0; // 1번 선수(번호 0)는 4번 타순 고정
        brute(k + 1);
        return;
    }

    for (int i = 1; i < 9; i++)
    {
        if (isused[i])
            continue;
        isused[i] = true;
        order[k] = i;
        brute(k + 1);
        isused[i] = false;
    }
}

int main()
{
    FIO;

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    brute(0);
    cout << ans;
}
