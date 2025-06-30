#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

string addBigNumbers(string a, string b)
{
    if (a.length() < b.length())
        swap(a, b); // 항상 a가 더 길게

    int carry = 0;
    int diff = a.length() - b.length();
    string result = "";

    for (int i = b.length() - 1; i >= 0; i--)
    {
        int sum = (a[i + diff] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    for (int i = diff - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }

    if (carry)
        result += carry + '0';

    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    FIO;

    string A, B;
    cin >> A >> B;
    cout << addBigNumbers(A, B) << '\n';
    return 0;
}
