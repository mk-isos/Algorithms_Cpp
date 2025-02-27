#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, M;
int office[10][10];
vector<pair<int, int>> cctvs;

int dx[4] = {1, 0, -1, 0}; // 남쪽(↓), 동쪽(→), 북쪽(↑), 서쪽(←)
int dy[4] = {0, 1, 0, -1};

int minBlindSpot = INT_MAX;

// 감시 영역을 표시하는 함수
void mark(int x, int y, int dir, int board[10][10])
{
    dir %= 4;
    while (true)
    {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == 6)
            return;
        if (board[x][y] != 0)
            continue;
        board[x][y] = 7;
    }
}

// 모든 CCTV의 방향 조합을 백트래킹으로 탐색
void dfs(int idx)
{
    if (idx == cctvs.size())
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (office[i][j] == 0)
                    cnt++;
        minBlindSpot = min(minBlindSpot, cnt);
        return;
    }

    int x = cctvs[idx].first;
    int y = cctvs[idx].second;
    int type = office[x][y];

    int temp[10][10];
    memcpy(temp, office, sizeof(office));

    for (int d = 0; d < 4; d++)
    {
        memcpy(office, temp, sizeof(office));

        if (type == 1)
            mark(x, y, d, office);
        else if (type == 2)
        {
            mark(x, y, d, office);
            mark(x, y, d + 2, office);
        }
        else if (type == 3)
        {
            mark(x, y, d, office);
            mark(x, y, (d + 1) % 4, office);
        }
        else if (type == 4)
        {
            mark(x, y, d, office);
            mark(x, y, (d + 1) % 4, office);
            mark(x, y, (d + 2) % 4, office);
        }
        else if (type == 5)
        {
            mark(x, y, 0, office);
            mark(x, y, 1, office);
            mark(x, y, 2, office);
            mark(x, y, 3, office);
        }

        dfs(idx + 1);
    }
}

int main()
{
    FIO;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5)
                cctvs.push_back({i, j});
        }

    dfs(0);
    cout << minBlindSpot;
}
