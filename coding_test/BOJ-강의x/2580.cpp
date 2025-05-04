#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int board[9][9];
vector<pair<int, int>> blanks;

bool isValid(int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num)
            return false;
        if (board[i][col] == num)
            return false;
    }

    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;
    for (int i = boxRow; i < boxRow + 3; i++)
    {
        for (int j = boxCol; j < boxCol + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}

void solve(int idx)
{
    if (idx == blanks.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    int row = blanks[idx].first;
    int col = blanks[idx].second;

    for (int num = 1; num <= 9; num++)
    {
        if (isValid(row, col, num))
        {
            board[row][col] = num;
            solve(idx + 1);
            board[row][col] = 0;
        }
    }
}

int main()
{
    FIO;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                blanks.push_back({i, j});
            }
        }
    }

    solve(0);
}
