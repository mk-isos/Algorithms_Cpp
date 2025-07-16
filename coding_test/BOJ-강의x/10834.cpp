#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M;
    cin >> M;

    long long num = 1, den = 1;
    int dir = 0;

    for (int i = 0; i < M; ++i)
    {
        long long a, b;
        int s;
        cin >> a >> b >> s;

        num *= b;
        den *= a;
        dir ^= s;

        long long g = gcd(num, den);
        num /= g;
        den /= g;
    }

    // 문제 조건상 항상 정수로 떨어지게 입력 주어짐
    cout << dir << " " << num / den << '\n';
    return 0;
}
