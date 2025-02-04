#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int L, R, C;            // 층, 행, 열의 개수
char board[32][32][32]; // 미로 정보를 저장 (최대 30x30x30 → 여유분으로 32)
int dist[32][32][32];   // 각 위치까지 도달하는 데 걸린 시간
                        // -1: 아직 방문하지 않음, -2: 벽('#')

// 6방향 이동: 위, 아래, 남, 북, 동, 서
int dl[6] = {1, -1, 0, 0, 0, 0};
int dr[6] = {0, 0, 1, -1, 0, 0};
int dc[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    FIO;
    while (true)
    {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)
            break;

        // 각 층, 각 행별로 dist 배열을 fill 함수를 사용해 0으로 초기화
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                fill(dist[i][j], dist[i][j] + C, 0);
            }
        }

        queue<tuple<int, int, int>> Q;

        // 미로 정보를 triple nested for문을 통해 입력받으며 dist 배열을 초기화
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < R; j++)
            {
                for (int k = 0; k < C; k++)
                {
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S')
                    {
                        Q.push({i, j, k});
                        dist[i][j][k] = 0;
                    }
                    else if (board[i][j][k] == '.' || board[i][j][k] == 'E')
                        dist[i][j][k] = -1;
                    else if (board[i][j][k] == '#')
                        dist[i][j][k] = -2;
                }
            }
        }

        int ans = -1;
        while (!Q.empty())
        {
            auto cur = Q.front();
            Q.pop();

            int curH, curX, curY;
            tie(curH, curX, curY) = cur;

            // 현재 위치가 탈출구 'E'인 경우 탐색 종료
            if (board[curH][curX][curY] == 'E')
            {
                ans = dist[curH][curX][curY];
                break;
            }

            // 6방향 탐색
            for (int d = 0; d < 6; d++)
            {
                int nh = curH + dl[d];
                int nx = curX + dr[d];
                int ny = curY + dc[d];

                // 미로 범위 검사
                if (nh < 0 || nh >= L || nx < 0 || nx >= R || ny < 0 || ny >= C)
                    continue;
                // 벽이면 건너뜁니다.
                if (board[nh][nx][ny] == '#')
                    continue;
                // 이미 방문한 곳은 건너뜁니다. (미방문 상태는 -1)
                if (dist[nh][nx][ny] != -1)
                    continue;

                dist[nh][nx][ny] = dist[curH][curX][curY] + 1;
                Q.push({nh, nx, ny});
            }
        }

        if (ans == -1)
            cout << "Trapped!" << "\n";
        else
            cout << "Escaped in " << ans << " minute(s)." << "\n";
    }
    return 0;
}
