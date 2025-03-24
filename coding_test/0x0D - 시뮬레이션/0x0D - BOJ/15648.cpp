#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

#define X first
#define Y second

int n, m, h;
bool ladder[32][12];
vector<pair<int, int>> coords;

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        int pos = i;
        for (int j = 1; j <= h; j++)
        {
            if (ladder[j][pos])
                pos++; // 오른쪽 가로선
            else if (ladder[j][pos - 1])
                pos--; // 왼쪽 가로선
        }
        if (pos != i)
            return false;
    }
    return true;
}

int main()
{
    FIO;
    cin >> n >> m >> h;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = true;
    }

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (ladder[i][j] || ladder[i][j - 1] || ladder[i][j + 1])
                continue;
            coords.push_back({i, j});
        }
    }

    // 사다리가 이미 완성된 경우
    if (check())
    {
        cout << 0;
        return 0;
    }

    int ans = 1e9;

    int sz = coords.size();
    // 1개 추가
    for (int i = 0; i < sz; i++)
    {
        auto [x1, y1] = coords[i];
        ladder[x1][y1] = true;
        if (check())
            ans = min(ans, 1);

        // 2개 추가
        for (int j = i + 1; j < sz; j++)
        {
            auto [x2, y2] = coords[j];
            if (ladder[x2][y2 - 1] || ladder[x2][y2 + 1])
                continue;
            ladder[x2][y2] = true;
            if (check())
                ans = min(ans, 2);

            // 3개 추가
            for (int k = j + 1; k < sz; k++)
            {
                auto [x3, y3] = coords[k];
                if (ladder[x3][y3 - 1] || ladder[x3][y3 + 1])
                    continue;
                ladder[x3][y3] = true;
                if (check())
                    ans = min(ans, 3);
                ladder[x3][y3] = false;
            }
            ladder[x2][y2] = false;
        }
        ladder[x1][y1] = false;
    }

    cout << (ans > 3 ? -1 : ans);
}
