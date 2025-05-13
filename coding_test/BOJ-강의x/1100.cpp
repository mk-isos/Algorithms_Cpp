#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int count = 0;
    for (int i = 0; i < 8; ++i)
    {
        string row;
        cin >> row;
        for (int j = 0; j < 8; ++j)
        {
            if ((i + j) % 2 == 0 && row[j] == 'F')
            {
                ++count;
            }
        }
    }
    cout << count << '\n';
    return 0;
}
