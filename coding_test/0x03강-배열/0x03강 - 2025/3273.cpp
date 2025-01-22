#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, x;
int a[1000001] = {};
bool occur[2000001];
int main()
{
    FIO;

    cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        // x-a[i]가 존재하는지 확인
        if (x - a[i] > 0 && occur[x - a[i]])
            ans++;
        occur[a[i]] = true;
    }
    cout << ans;
}