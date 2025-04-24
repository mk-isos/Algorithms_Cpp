#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

// 문자열 곱셈 (s * k)
string multiply(const string &s, int k)
{
    string result = "";
    int carry = 0;
    for (int i = (int)s.size() - 1; i >= 0; --i)
    {
        int mul = (s[i] - '0') * k + carry;
        result += (mul % 10) + '0';
        carry = mul / 10;
    }
    while (carry)
    {
        result += (carry % 10) + '0';
        carry /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

// 문자열 회전 여부 확인 (길이 같을 것 + 회전 포함)
bool isRotation(const string &base, const string &test)
{
    return base.size() == test.size() && (base + base).find(test) != string::npos;
}

bool isCyclic(const string &s)
{
    int len = s.length();
    for (int i = 1; i <= len; ++i)
    {
        string m = multiply(s, i);
        if (m.size() != len)
            return false;
        if (!isRotation(s, m))
            return false;
    }
    return true;
}

int main()
{
    FIO;
    string s;
    while (cin >> s)
    {
        if (isCyclic(s))
            cout << s << " is cyclic\n";
        else
            cout << s << " is not cyclic\n";
    }
}
