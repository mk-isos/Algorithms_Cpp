#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        list<char> L = {};
        string s;
        auto p = L.begin();

        cin >> s;
        for (auto c : s)
        {
            if (c == '<')
            {
                if (p != L.begin())
                    p--;
            }
            else if (c == '>')
            {
                if (p != L.end())
                    p++;
            }
            else if (c == '-')
            {
                if (p != L.begin())
                {
                    p--;
                    p = L.erase(p);
                }
            }
            else
                L.insert(p, c);
        }
        for (auto c : L)
            cout << c;
        cout << '\n';
    }
}
