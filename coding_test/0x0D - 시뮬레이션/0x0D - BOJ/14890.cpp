#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, l;
int board[102][102];

bool check(vector<int> &line)
{
    vector<bool> used(n, false);
    for (int i = 0; i < n - 1; i++)
    {
        int diff = line[i + 1] - line[i];

        if (abs(diff) > 1)
            return false;

        if (diff == 1)
        { // 현재 칸보다 다음 칸이 1 더 높아지는 경우
            for (int j = 0; j < l; j++)
            {
                if (i - j < 0 || line[i - j] != line[i] || used[i - j])
                    return false;
                used[i - j] = true;
            }
        }
        else if (diff == -1)
        { // 현재 칸보다 다음 칸이 1 더 낮아지는 경우
            for (int j = 1; j <= l; j++)
            {
                if (i + j >= n || line[i + j] != line[i + 1] || used[i + j])
                    return false;
                used[i + j] = true;
            }
        }
    }
    return true;
}

int count_paths()
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
            row.push_back(board[i][j]);
        if (check(row))
            count++;
    }

    for (int j = 0; j < n; j++)
    {
        vector<int> col;
        for (int i = 0; i < n; i++)
            col.push_back(board[i][j]);
        if (check(col))
            count++;
    }

    return count;
}

int main()
{
    FIO;

    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << count_paths();
}
