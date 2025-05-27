#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    string line;
    while (getline(cin, line))
    {
        int lower = 0, upper = 0, digit = 0, space = 0;
        for (char ch : line)
        {
            if (islower(ch))
                lower++;
            else if (isupper(ch))
                upper++;
            else if (isdigit(ch))
                digit++;
            else if (ch == ' ')
                space++;
        }
        cout << lower << ' ' << upper << ' ' << digit << ' ' << space << '\n';
    }
    return 0;
}
