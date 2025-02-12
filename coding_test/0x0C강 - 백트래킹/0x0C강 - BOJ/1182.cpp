#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, s;
int arr[22];
int cnt = 0;

void func(int cur, int sum)
{
    if (cur == n)
    {
        if (sum == s)
            cnt++;
        return;
    }
    func(cur + 1, sum);
    func(cur + 1, sum + arr[cur]);
}

int main()
{
    FIO;

    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    func(0, 0);
    if (s == 0) // 공집합 제외하래
        cnt--;
    cout << cnt;
}