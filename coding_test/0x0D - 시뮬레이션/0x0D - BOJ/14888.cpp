#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n;
int num[12];
int cal[4];
int mx = -1e9, mn = 1e9; // 최댓값, 최솟값

void func(int idx, int result)
{
    if (idx == n)
    {
        mx = max(mx, result);
        mn = min(mn, result);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (cal[i] > 0)
        {
            cal[i]--;

            if (i == 0)
                func(idx + 1, result + num[idx]); // 덧셈
            else if (i == 1)
                func(idx + 1, result - num[idx]); // 뺄셈
            else if (i == 2)
                func(idx + 1, result * num[idx]); // 곱셈
            else
            { // 나눗셈 (C++ 음수 나눗셈 처리) 그니까 그냥 버림 하는 거임
                if (result < 0)
                    func(idx + 1, -(-result / num[idx]));
                else
                    func(idx + 1, result / num[idx]);
            }

            cal[i]++; // 백트래킹 (원상 복구)
        }
    }
}

int main()
{
    FIO;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < 4; i++)
        cin >> cal[i];

    func(1, num[0]); // 첫 번째 수는 그대로 두고 시작
    cout << mx << '\n'
         << mn << '\n';
}
