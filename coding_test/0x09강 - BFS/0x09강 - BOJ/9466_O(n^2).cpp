#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int arr[100005];
int n;

bool iscycle(int idx)
{
    int cur = idx;
    for (int i = 0; i < n; i++)
    {
        cur = arr[cur];
        if (cur == idx)
            return true;
    }
    return false;
}

int main()
{
    FIO;

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!iscycle(i))
                ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
