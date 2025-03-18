#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second

int n, m;
int board[505][505];

pair<int, int> tetro[19][4] = {
    // 막대 모양 (청록색)
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},

    // 네모 모양 (노란색)
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},

    // L, ㄴ 모양 (주황색)
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 2}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 0}},

    {{0, 1}, {1, 1}, {2, 1}, {0, 0}},
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
    {{0, 0}, {1, 0}, {2, 0}, {0, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},

    // 번개 모양 (초록색)
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{1, 0}, {1, 1}, {0, 1}, {0, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}},

    // ㅗ, ㅜ, ㅓ, ㅏ 모양 (자주색)
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{1, 0}, {1, 1}, {1, 2}, {0, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
    {{0, 1}, {1, 1}, {2, 1}, {1, 0}}};

int bruteforce(int x, int y)
{
    int mx = 0;
    for (int i = 0; i < 19; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
            sum += board[x + tetro[i][j].X][y + tetro[i][j].Y];
        mx = max(mx, sum);
    }
    return mx;
}

int main()
{
    FIO;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, bruteforce(i, j));

    cout << ans;
}
