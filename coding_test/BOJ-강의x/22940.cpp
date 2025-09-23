#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int N;
    if (!(cin >> N))
        return 0;
    vector<vector<long double>> a(N, vector<long double>(N + 1));
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= N; j++)
            cin >> a[i][j];

    const long double EPS = 1e-12L;
    for (int col = 0, row = 0; col < N && row < N; ++col, ++row)
    {
        int piv = row;
        for (int i = row; i < N; i++)
            if (fabsl(a[i][col]) > fabsl(a[piv][col]))
                piv = i;
        if (fabsl(a[piv][col]) < EPS)
            return 0;
        swap(a[piv], a[row]);
        for (int i = row + 1; i < N; i++)
        {
            long double f = a[i][col] / a[row][col];
            if (fabsl(f) < EPS)
                continue;
            for (int j = col; j <= N; j++)
                a[i][j] -= f * a[row][j];
        }
    }

    vector<long double> x(N, 0);
    for (int i = N - 1; i >= 0; i--)
    {
        long double s = a[i][N];
        for (int j = i + 1; j < N; j++)
            s -= a[i][j] * x[j];
        x[i] = s / a[i][i];
    }
    for (int i = 0; i < N; i++)
    {
        if (i)
            cout << ' ';
        cout << llround(x[i]);
    }
    cout << '\n';
}
