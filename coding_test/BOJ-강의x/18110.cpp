#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
        cin >> ratings[i];

    sort(ratings.begin(), ratings.end());

    int trim = round(n * 0.15); // 위/아래에서 제거할 개수

    // 절사평균 계산
    int sum = accumulate(ratings.begin() + trim, ratings.end() - trim, 0);
    int count = n - 2 * trim; // 제외한 후 남은 개수
    cout << round((double)sum / count) << '\n';

    return 0;
}
