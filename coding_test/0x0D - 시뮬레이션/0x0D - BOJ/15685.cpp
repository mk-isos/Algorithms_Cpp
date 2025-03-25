// 나중에 다시 또 해보기

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int board[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    FIO;

    int n;
    cin >> n;

    while (n--)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> dirs;
        dirs.push_back(d);

        // g 세대까지 확장
        for (int gen = 1; gen <= g; gen++)
        {
            int size = dirs.size();
            for (int i = size - 1; i >= 0; i--)
            {
                dirs.push_back((dirs[i] + 1) % 4); // 시계 방향으로 회전
            }
        }

        board[y][x] = 1;

        // 드래곤 커브 따라가기
        for (int dir : dirs)
        {
            x += dx[dir];
            y += dy[dir];
            board[y][x] = 1;
        }
    }

    int cnt = 0;

    // 1x1 정사각형을 구성할 수 있는지 확인
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                cnt++;
        }
    }

    cout << cnt;
}
