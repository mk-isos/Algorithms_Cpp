#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

string board[4]; // 톱니바퀴 상태 저장

void go(int x, int dir)
{
    int dirs[4] = {};
    dirs[x] = dir;

    // 왼쪽으로 회전 전파
    int idx = x;
    while (idx > 0 && board[idx][6] != board[idx - 1][2])
    {
        dirs[idx - 1] = -dirs[idx]; // 반대 방향으로 회전
        idx--;
    }

    // 오른쪽으로 회전 전파
    idx = x;
    while (idx < 3 && board[idx][2] != board[idx + 1][6])
    {
        dirs[idx + 1] = -dirs[idx];
        idx++;
    }

    // 실제로 톱니바퀴를 회전 (STL rotate 활용)
    for (int i = 0; i < 4; i++)
    {
        if (dirs[i] == -1)
        {
            rotate(board[i].begin(), board[i].begin() + 1, board[i].end()); // 반시계 방향 회전
        }
        else if (dirs[i] == 1)
        {
            rotate(board[i].begin(), board[i].begin() + 7, board[i].end()); // 시계 방향 회전
        }
    }
}

int main()
{
    FIO;

    // 톱니 입력 받기
    for (int i = 0; i < 4; i++)
    {
        cin >> board[i];
    }

    int K;
    cin >> K;

    // 회전 명령 받기
    vector<pair<int, int>> rotations;
    for (int i = 0; i < K; i++)
    {
        int x, dir;
        cin >> x >> dir;
        go(x - 1, dir); // 배열은 0-indexed
    }

    int score = 0;
    for (int i = 0; i < 4; i++)
    {
        if (board[i][0] == '1')
            score += (1 << i); // 2^i (1, 2, 4, 8) 더하기
    }

    cout << score << '\n'; // 최종 점수 출력

    return 0;
}
