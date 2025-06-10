#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;

    int korean_days = (A + C - 1) / C; // 올림
    int math_days = (B + D - 1) / D;

    int homework_days = max(korean_days, math_days);
    cout << L - homework_days << '\n';
}
