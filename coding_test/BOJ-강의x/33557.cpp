#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using ll = long long;

int main()
{
    FIO;
    int T;
    cin >> T;

    while (T--)
    {
        ll A, B;
        cin >> A >> B;

        string result = to_string(A * B);

        ll a = A, b = B; // 원본 값 유지
        string wrongResult = "";

        while (a && b)
        {
            wrongResult = to_string((a % 10) * (b % 10)) + wrongResult;
            a /= 10;
            b /= 10;
        }

        while (a)
        {
            wrongResult = to_string(a % 10) + wrongResult;
            a /= 10;
        }

        while (b)
        {
            wrongResult = to_string(b % 10) + wrongResult;
            b /= 10;
        }

        cout << (result == wrongResult) << "\n";
    }
    return 0;
}
