#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int N;
pair<int, int> points[20];
bool selected[20];
double result;

void dfs(int idx, int count)
{
    if (count == N / 2)
    {
        int x_sum = 0, y_sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (selected[i])
            {
                x_sum += points[i].first;
                y_sum += points[i].second;
            }
            else
            {
                x_sum -= points[i].first;
                y_sum -= points[i].second;
            }
        }
        double dist = sqrt(1.0 * x_sum * x_sum + 1.0 * y_sum * y_sum);
        result = min(result, dist);
        return;
    }

    for (int i = idx; i < N; i++)
    {
        selected[i] = true;
        dfs(i + 1, count + 1);
        selected[i] = false;
    }
}

int main()
{
    FIO;
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> points[i].first >> points[i].second;
        }
        result = DBL_MAX;
        dfs(0, 0);
        cout << fixed << setprecision(12) << result << '\n';
    }
    return 0;
}
