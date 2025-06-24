#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    string s;
    cin >> s;

    int result = 0;

    if (s == "1010")
    {
        result = 20;
    }
    else if (s.substr(0, 2) == "10")
    {
        int B = s[2] - '0';
        result = 10 + B;
    }
    else if (s.substr(s.length() - 2) == "10")
    {
        int A = s[0] - '0';
        result = A + 10;
    }
    else
    {
        int A = s[0] - '0';
        int B = s[1] - '0';
        result = A + B;
    }

    cout << result << '\n';
}
