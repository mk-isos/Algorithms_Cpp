// 틀렸어.. 으아 나중에 오늘은 아니야.

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

vector<int> generate_sequence(int n)
{
    vector<int> a(2 * n);

    a[0] = 1;
    a[2 * n - 1] = 1;

    int f1 = -n * (n + 1) / 2;
    int f2 = n;

    for (int i = 1; i < n; i++)
    {
        a[2 * i - 1] = f1;
        a[2 * i] = f2;
        f1 += 1;
        f2 -= 1;
    }

    return a;
}

int main()
{
    FIO;
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> result = generate_sequence(n);

        for (int x : result)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
