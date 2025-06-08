#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    string A, B, C, D;
    cin >> A >> B >> C >> D;

    // 문자열을 연결하고 정수로 변환
    long long AB = stoll(A + B);
    long long CD = stoll(C + D);

    cout << AB + CD << '\n';
    return 0;
}
