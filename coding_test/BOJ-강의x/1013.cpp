#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int T;
    cin >> T;
    cin.ignore(); // 개행 문자 처리

    regex pattern("(100+1+|01)+");

    while (T--)
    {
        string s;
        getline(cin, s); // 공백 없는 문자열이지만 안전하게 getline 사용

        if (regex_match(s, pattern))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
