#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int A[105][105];
int n = 3, m = 3;
int r, c, k;

int freq_sort(int arr[], int size)
{
    vector<pair<int, int>> v;
    int freq[101] = {};
    for (int i = 1; i <= size; i++)
    {
        if (arr[i] == 0)
            continue;
        freq[arr[i]]++;
    }
    for (int i = 1; i <= 100; i++)
        if (freq[i])
            v.push_back({freq[i], i});
    sort(v.begin(), v.end());
    int j = 0;
    for (auto [cnt, num] : v)
    {
        if (j >= 100)
            break;
        arr[++j] = num;
        arr[++j] = cnt;
    }
    for (int i = j + 1; i <= 100; i++)
        arr[i] = 0;
    return j;
}

int main()
{
    FIO;
    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            cin >> A[i][j];

    int time = 0;
    while (A[r][c] != k && time <= 100)
    {
        if (n >= m)
        {
            int new_m = 0;
            for (int i = 1; i <= n; i++)
                new_m = max(new_m, freq_sort(A[i], m));
            m = new_m;
        }
        else
        {
            int new_n = 0;
            for (int i = 1; i <= m; i++)
            {
                int col[105];
                for (int j = 1; j <= n; j++)
                    col[j] = A[j][i];
                int len = freq_sort(col, n);
                for (int j = 1; j <= len; j++)
                    A[j][i] = col[j];
                for (int j = len + 1; j <= 100; j++)
                    A[j][i] = 0;
                new_n = max(new_n, len);
            }
            n = new_n;
        }
        time++;
    }
    cout << (time > 100 ? -1 : time);
}
