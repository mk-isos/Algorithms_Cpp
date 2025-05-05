#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int F(string x)
{
    int firstDigit = x[0] - '0';
    int length = x.size();
    return firstDigit * length;
}

int main()
{
    FIO;
    string x;
    cin >> x;

    set<int> seen;
    int current = F(x);

    while (true)
    {
        if (seen.count(current))
        {
            cout << "FA\n";
            return 0;
        }
        seen.insert(current);
        string next = to_string(current);
        current = F(next);
    }

    // 실제로 도달하지 않음
    cout << "NFA\n";
    return 0;
}
