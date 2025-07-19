#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    string line, input;
    while (getline(cin, line))
    {
        input += line;
    }

    stringstream ss(input);
    string token;
    int sum = 0;
    while (getline(ss, token, ','))
    {
        sum += stoi(token);
    }

    cout << sum << '\n';
    return 0;
}
