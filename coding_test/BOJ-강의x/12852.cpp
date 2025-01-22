#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    FIO;
    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);
    vector<int> prev(N + 1, 0);

    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + 1;
        prev[i] = i - 1;

        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            prev[i] = i / 2;
        }

        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            prev[i] = i / 3;
        }
    }

    cout << dp[N] << "\n";

    vector<int> path;
    for (int i = N; i != 0; i = prev[i]) {
        path.push_back(i);
    }

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << " ";
    }
    cout << "\n";

    return 0;
}
