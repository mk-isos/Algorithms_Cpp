#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M, x, y, d;
int board[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
    FIO;

    cin >> N >> M;
    cin >> x >> y >> d;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    int cleanedCount = 0;

    while (true)
    {
        // Step 1: 현재 위치 청소
        if (board[x][y] == 0)
        {
            board[x][y] = -1; // 청소 완료 표시
            cleanedCount++;
        }

        // Step 2: 주변 4칸 검사
        bool canClean = false;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (board[nx][ny] == 0)
            { // 청소할 공간이 있음
                canClean = true;
                break;
            }
        }

        if (canClean)
        {
            // Step 3: 반시계 방향 회전 후 청소 가능한 곳으로 이동
            for (int i = 0; i < 4; i++)
            {
                d = (d + 3) % 4; // 반시계 방향 회전
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (board[nx][ny] == 0)
                { // 청소되지 않은 칸이면 이동
                    x = nx;
                    y = ny;
                    break;
                }
            }
        }
        else
        {
            // Step 4: 청소할 공간이 없으면 후진 가능 여부 체크
            int backX = x - dx[d];
            int backY = y - dy[d];

            if (board[backX][backY] == 1)
            { // 벽이면 종료
                break;
            }

            // 후진 가능하면 후진
            x = backX;
            y = backY;
        }
    }

    cout << cleanedCount << '\n';
}
