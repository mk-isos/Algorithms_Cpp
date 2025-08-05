#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    string type;
    int x, total = 0;

    while (cin >> type >> x)
    {
        if (type == "Es")
            total += x * 21;
        else if (type == "Stair")
            total += x * 17;
    }

    cout << total << '\n';
    return 0;
}
