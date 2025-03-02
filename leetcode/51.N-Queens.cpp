class Solution
{
public:
    vector<vector<string>> result;

    bool isValid(vector<int> &queens, int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            // 같은 열 또는 대각선 체크
            if (queens[i] == col || abs(queens[i] - col) == abs(i - row))
            {
                return false;
            }
        }
        return true;
    }

    void solve(int n, int row, vector<int> &queens)
    {
        if (row == n)
        {
            // 유효한 체스판 생성
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++)
            {
                board[i][queens[i]] = 'Q';
            }
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isValid(queens, row, col))
            {
                queens[row] = col; // 퀸 배치
                solve(n, row + 1, queens);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> queens(n, -1);
        solve(n, 0, queens);
        return result;
    }
};