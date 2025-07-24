#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    string A, B;
    cin >> A >> B;

    while (A.length() < B.length())
        A = '0' + A;
    while (B.length() < A.length())
        B = '0' + B;

    string result = "";
    for (int i = 0; i < A.length(); ++i)
    {
        int digitA = A[i] - '0';
        int digitB = B[i] - '0';
        result += to_string(digitA + digitB);
    }

    cout << result << '\n';
    return 0;
}
