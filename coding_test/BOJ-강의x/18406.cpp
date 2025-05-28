#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    string s;
    cin >> s;
    int len = s.length();
    int leftSum = 0, rightSum = 0;

    for (int i = 0; i < len / 2; ++i)
    {
        leftSum += s[i] - '0';
    }
    for (int i = len / 2; i < len; ++i)
    {
        rightSum += s[i] - '0';
    }

    if (leftSum == rightSum)
        cout << "LUCKY\n";
    else
        cout << "READY\n";

    return 0;
}
