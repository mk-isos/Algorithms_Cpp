#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second

int n, m, year;
int area[303][303];
int vis[303][303];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool check(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void initvis()
{
    for (int i = 0; i < n; i++)
        fill(vis[i], vis[i] + m, 0);
}

void melting()
{
    int zero[303][303] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (area[i][j] == 0)
                continue;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if (check(nx, ny) && area[nx][ny] == 0)
                    zero[i][j]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            area[i][j] = max(0, area[i][j] - zero[i][j]);
        }
    }
}

int status()
{
    int x = -1, y = -1;
    int cnt1 = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (area[i][j])
            {
                x = i;
                y = j;
                cnt1++;
            }
        }
    }
    if (cnt1 == 0)
        return 0;

    int cnt2 = 0;
    queue<pair<int, int>> q;
    vis[x][y] = 1;
    q.push({x, y});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        cnt2++;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (!check(nx, ny) || vis[nx][ny] == 1 || area[nx][ny] <= 0)
                continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    if (cnt1 == cnt2)
        return 1;
    return 2;
}

int main()
{
    FIO;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> area[i][j];
    }

    while (true)
    {
        year++;               // 1년 추가
        melting();            // 빙산 녹이기
        initvis();            // 방문배열 초기화
        int check = status(); // 빙산의 상태 확인
        if (check == 0)
        {
            cout << 0;
            return 0;
        }
        else if (check == 1)
            continue; // 아직 한 덩이
        else
            break; // check = 2, 분리됨
    }
    cout << year;
    return 0;
}