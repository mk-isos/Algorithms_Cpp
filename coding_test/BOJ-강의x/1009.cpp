#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;

        a %= 10;
        if (a == 0)
        {
            cout << 10 << '\n';
            continue;
        }

        vector<int> pattern;
        int current = a;
        set<int> seen;

        while (seen.find(current) == seen.end())
        {
            seen.insert(current);
            pattern.push_back(current);
            current = (current * a) % 10;
        }

        int index = (b - 1) % pattern.size();
        cout << pattern[index] << '\n';
    }
    return 0;
}
