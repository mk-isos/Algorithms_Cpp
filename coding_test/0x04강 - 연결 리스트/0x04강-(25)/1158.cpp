#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n, k;
    cin >> n >> k;

    // 수열 완성 & < 출력
    queue<int> Q;
    for (int i = 1; i <= n; i++)
        Q.push(i);
    cout << '<';

    While(!Q.empty())
    {
        for (int i = 0; i < k - 1; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }
        cout << Q.front();
        Q.pop();
        if (Q.size())
            cout << ", ";
    }
    cout << '>';
}