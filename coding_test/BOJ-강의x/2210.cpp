#include <iostream>
#include <set>
using namespace std;

int board[5][5];
set<int> unique_numbers;
int dx[4] = {0, 0, -1, 1}; // 상하좌우 방향
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, int depth, int number)
{
    if (depth == 6)
    {
        unique_numbers.insert(number);
        return;
    }
    for (int dir = 0; dir < 4; ++dir)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
        {
            dfs(nx, ny, depth + 1, number * 10 + board[nx][ny]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> board[i][j];

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            dfs(i, j, 1, board[i][j]);

    cout << unique_numbers.size() << '\n';
    return 0;
}
