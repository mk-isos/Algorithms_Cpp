#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

string toBinary(char octDigit)
{
    int num = octDigit - '0';
    string bin = "";
    for (int i = 0; i < 3; i++)
    {
        bin = char((num % 2) + '0') + bin;
        num /= 2;
    }
    return bin;
}

int main()
{
    FIO;
    string oct;
    cin >> oct;

    if (oct == "0")
    {
        cout << "0\n";
        return 0;
    }

    // 첫 자리는 앞자리 0 제거
    cout << stoi(toBinary(oct[0]));

    for (int i = 1; i < oct.size(); i++)
    {
        cout << toBinary(oct[i]);
    }
    cout << '\n';
}
