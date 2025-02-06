// base conditon 0 버전
#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

void func(int a, int b, int n)
{
    if (n == 0)
        return; // base case: n이 0이면 아무 동작도 하지 않음

    func(a, 6 - a - b, n - 1);
    cout << a << ' ' << b << '\n';
    func(6 - a - b, b, n - 1);
}

int main(void)
{
    FIO;

    int k;
    cin >> k;
    cout << (1 << k) - 1 << '\n';
    func(1, 3, k);
}
