#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
char board[1000][1000];
int dist[1000][1000][2]; // 최단 거리 저장 (벽 부쉈는지 여부 0/1)

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs()
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 1; // 시작 위치의 거리 (1부터 시작)

    while (!q.empty())
    {
        auto [x, y, broken] = q.front();
        q.pop();

        // 목적지 도착 시 거리 반환
        if (x == N - 1 && y == M - 1)
            return dist[x][y][broken];

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위를 벗어나면 무시
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            // 이동 가능한 경우 (벽이 아닐 때)
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == 0)
            {
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, broken});
            }

            // 벽이지만, 아직 벽을 부순 적이 없을 때 한 번 부수고 이동
            if (board[nx][ny] == '1' && broken == 0 && dist[nx][ny][1] == 0)
            {
                dist[nx][ny][1] = dist[x][y][0] + 1;
                q.push({nx, ny, 1});
            }
        }
    }

    return -1;
}

int main()
{
    FIO;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = row[j];
            dist[i][j][0] = 0;
            dist[i][j][1] = 0;
        }
    }

    cout << bfs() << '\n';
    return 0;
}
