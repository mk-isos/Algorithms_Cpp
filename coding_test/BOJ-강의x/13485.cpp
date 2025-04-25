#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

int main()
{
    FIO;
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int B, C;
    cin >> B >> C;

    ll total = 0;

    for (int i = 0; i < N; ++i)
    {
        total += 1;
        int remain = A[i] - B;
        if (remain > 0)
        {
            total += (remain + C - 1) / C; // 부감독관 수 = 올림 나눗셈
        }
    }

    cout << total << '\n';
    return 0;
}
