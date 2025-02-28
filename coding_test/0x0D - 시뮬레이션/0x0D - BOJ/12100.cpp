#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N;
int board1[21][21];
int board2[21][21];

// 90도 회전
void rotate()
{
    int temp[21][21];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[i][j] = board2[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board2[i][j] = temp[N - 1 - j][i]; // 90도 회전
}

// 한 방향으로 기울이는 함수
void tilt(int dir)
{
    while (dir--)
        rotate(); // 원하는 방향이 나올 때까지 회전

    for (int i = 0; i < N; i++)
    {
        int tilted[21] = {};
        int idx = 0;

        for (int j = 0; j < N; j++)
        {
            if (board2[i][j] == 0)
                continue;

            if (tilted[idx] == 0)
                tilted[idx] = board2[i][j];

            else if (tilted[idx] == board2[i][j])
                tilted[idx++] *= 2; // 같은 숫자면 합침 (한 번만 합쳐지도록 idx 증가)
            else
                tilted[++idx] = board2[i][j]; // 다른 숫자면 다음 칸에 배치
        }

        for (int j = 0; j < N; j++)
            board2[i][j] = tilted[j]; // 원래 보드에 덮어쓰기
    }
}

int main()
{
    FIO;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board1[i][j];

    int maxBlock = 0;

    // 5번 이동하는 모든 경우의 수 (4^5 = 1024)
    for (int temp = 0; temp < 1024; temp++)
    {
        memcpy(board2, board1, sizeof(board1));

        int brute = temp;

        // 5번 이동
        for (int i = 0; i < 5; i++)
        {
            int dir = brute % 4; // 0: 위, 1: 왼쪽, 2: 아래, 3: 오른쪽
            brute /= 4;
            tilt(dir);
        }

        // 최대 블록 값 갱신
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                maxBlock = max(maxBlock, board2[i][j]);
    }

    cout << maxBlock << '\n';
}
