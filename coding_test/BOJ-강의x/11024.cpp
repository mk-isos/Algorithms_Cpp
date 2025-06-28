#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);

        int num, sum = 0;
        while (ss >> num)
            sum += num;

        cout << sum << '\n';
    }
    return 0;
}
