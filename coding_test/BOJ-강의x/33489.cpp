#include <bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

typedef long long ll;

// 점수 계산 함수
tuple<int, int, int> get_max_score(int X, int Y)
{
    int best_x = 1, best_y = 1, max_score = 0;

    for (int x = 1; x <= X; ++x)
    {
        for (int y = 1; y <= Y; ++y)
        {
            vector<int> A = {x, y};
            int k = 2;
            while (true)
            {
                int next = A[k - 2] - A[k - 1];
                if (next <= 0)
                {
                    break;
                }
                A.push_back(next);
                k++;
            }
            if (k > max_score)
            {
                max_score = k;
                best_x = x;
                best_y = y;
            }
        }
    }
    return {best_x, best_y, max_score};
}

int main()
{
    FIO;
    int T;
    cin >> T;
    while (T--)
    {
        int X, Y;
        cin >> X >> Y;
        auto [x, y, score] = get_max_score(X, Y);
        cout << x << " " << y << "\n";
    }
    return 0;
}
