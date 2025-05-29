#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;

int main()
{
    FIO;
    int N;
    cin >> N;

    vector<ll> pair_sums(N - 1);
    ll total = 0;
    ll sum_pairs = 0;

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> pair_sums[i];
        sum_pairs += pair_sums[i];
    }

    cin >> total;

    // 마지막 숫자 a[N-1] 계산
    ll last = (sum_pairs - total) / (N - 2);

    // 나머지 숫자 복원
    for (int i = 0; i < N - 1; ++i)
    {
        cout << pair_sums[i] - last << "\n";
    }
    cout << last << "\n";

    return 0;
}
