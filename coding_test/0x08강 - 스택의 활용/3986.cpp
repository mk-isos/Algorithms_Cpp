#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n;
    int ans = 0;

    cin >> n;

    while (n--)
    {
        string a;
        cin >> a;

        stack<int> S;
        for (auto c : a)
        {
            if (!S.empty() && S.top() == c)
                S.pop();
            else
                S.push(c);
        }
        if (S.empty())
            ans++;
    }
    cout << ans;
}