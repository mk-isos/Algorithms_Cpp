#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

stack<char> s;
string str;

int main()
{
    FIO;

    cin >> str;
    int sum = 0; // 누적해서 더해질 값
    int num = 1; // 곱해질 값

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            num *= 2; // 소괄호가 나오면 곱해질 값 2배 증가
            s.push(str[i]);
        }
        else if (str[i] == '[')
        {
            num *= 3; // 대괄호가 나오면 곱해질 값 3배 증가
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '(')
                sum += num; // 직전 괄호가 여는 괄호였다면 sum에 값 추가
            s.pop();
            num /= 2; // 소괄호 쌍이 사라졌으니 2로 나눔
        }
        else
        { // str[i] == ']'
            if (s.empty() || s.top() != '[')
            {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '[')
                sum += num; // 직전 괄호가 여는 괄호였다면 sum에 값 추가
            s.pop();
            num /= 3; // 대괄호 쌍이 사라졌으니 3로 나눔
        }
    }
    if (s.empty())
        cout << sum;
    else
        cout << 0;
}