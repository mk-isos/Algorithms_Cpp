// #include <bits/stdc++.h>
// #define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// using namespace std;

// int main() {
//     FIO;
//     int N;
//     cin >> N;

//     if (N % 4 == 1 || N % 4 == 3) cout << "SK\n";
//     else cout << "CY\n";
// }

// DP 로

#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dp[1001];

int main()
{
    FIO;
    int N;
    cin >> N;

    dp[1] = 1; // SK
    dp[2] = 0; // CY
    dp[3] = 1; // SK
    dp[4] = 0; // CY

    for (int i = 5; i <= N; i++)
    {
        if (dp[i - 1] == 0 || dp[i - 3] == 0)
            dp[i] = 1; // 한 번에 이길 수 있는 경우
        else
            dp[i] = 0; // 무조건 진다
    }

    if (dp[N])
        cout << "SK\n";
    else
        cout << "CY\n";
}
