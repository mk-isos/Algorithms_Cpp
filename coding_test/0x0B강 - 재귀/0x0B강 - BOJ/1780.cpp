#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N;
vector<vector<int>> paper;
int cnt_minus1 = 0, cnt_0 = 0, cnt_1 = 0;

bool check_same(int x, int y, int size)
{
    int first = paper[x][y];
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (paper[i][j] != first)
                return false;
        }
    }
    return true;
}

// 종이를 나누어가며 개수를 세는 재귀 함수
void divide(int x, int y, int size)
{
    if (check_same(x, y, size))
    {
        if (paper[x][y] == -1)
            cnt_minus1++;
        else if (paper[x][y] == 0)
            cnt_0++;
        else
            cnt_1++;
        return;
    }

    int newSize = size / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            divide(x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main()
{
    FIO;
    cin >> N;
    paper.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> paper[i][j];
        }
    }

    divide(0, 0, N);

    cout << cnt_minus1 << "\n";
    cout << cnt_0 << "\n";
    cout << cnt_1 << "\n";

    return 0;
}
