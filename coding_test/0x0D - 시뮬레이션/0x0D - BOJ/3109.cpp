#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
#define X first
#define Y second

int n, k;
int board[105][105];
queue<pair<int, char>> switchDir;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    FIO;
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x][y] = 2;
    }

    int l;
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        switchDir.push({x, c});
    }

    int second = 0;
    int dir = 0;
    deque<pair<int, int>> dq;
    dq.push_front({1, 1});

    while (true)
    {
        second++;

        int nx = dq.front().X + dx[dir];
        int ny = dq.front().Y + dy[dir];

        if (nx < 1 || nx > n || ny < 1 || ny > n)
            break;
        if (board[nx][ny] == 1)
            break;

        dq.push_front({nx, ny});

        if (board[nx][ny] != 2)
        {
            auto tail = dq.back();
            board[tail.X][tail.Y] = 0;
            dq.pop_back();
        }
        board[nx][ny] = 1;

        if (!switchDir.empty() && switchDir.front().X == second)
        {
            if (switchDir.front().Y == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
            switchDir.pop();
        }
    }

    cout << second << '\n';
}
