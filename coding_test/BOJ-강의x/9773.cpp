#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int N;

    if (!(cin >> N))
        return 0;
    while (N--)
    {
        string s;
        cin >> s;
        long long sum = 0;
        for (char c : s)
            sum += c - '0';
        int last3 = (s[10] - '0') * 100 + (s[11] - '0') * 10 + (s[12] - '0');
        long long x = sum + 1LL * last3 * 10;
        if (x >= 10000)
            x %= 10000;
        else if (x < 1000)
            x += 1000;
        cout << setw(4) << setfill('0') << x << '\n';
    }
}
