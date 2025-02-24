// 아이디어는 좋았는데 구현이 조금 어려웠다.. 아직도..

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N, board[10][10];
bool left_diag[20], right_diag[20];              // 대각선 방문 체크
vector<pair<int, int>> black_cells, white_cells; // 검은 칸, 흰 칸 위치 저장
int max_black = 0, max_white = 0;

void backtrack(int idx, vector<pair<int, int>> &cells, int count, int &max_count)
{
    if (idx == cells.size())
    {
        max_count = max(max_count, count);
        return;
    }

    int r = cells[idx].first, c = cells[idx].second;
    if (!left_diag[r + c] && !right_diag[r - c + (N - 1)])
    { // 같은 대각선에 비숍이 없다면
        left_diag[r + c] = right_diag[r - c + (N - 1)] = true;
        backtrack(idx + 1, cells, count + 1, max_count);
        left_diag[r + c] = right_diag[r - c + (N - 1)] = false;
    }

    // 현재 위치에 놓지 않고 넘어가는 경우도 고려
    backtrack(idx + 1, cells, count, max_count);
}

int main()
{
    FIO;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                if ((i + j) % 2 == 0)
                    black_cells.push_back({i, j}); // 검은 칸
                else
                    white_cells.push_back({i, j}); // 흰 칸
            }
        }
    }

    // 검은 칸과 흰 칸에 대해 각각 백트래킹 수행
    backtrack(0, black_cells, 0, max_black);
    backtrack(0, white_cells, 0, max_white);

    cout << max_black + max_white << "\n";
    return 0;
}
