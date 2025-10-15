#include <bits/stdc++.h>
using namespace std;

unordered_map<char, char> bracketPair = {
    {')', '('},
    {']', '['},
    {'}', '{'}};

bool isValid(string &s, int start)
{
    stack<char> stk;
    unsigned int sz = s.size();

    for (int i = 0; i < sz; i++)
    {
        char ch = s[(start + i) % sz];

        if (bracketPair.count(ch))
        {
            if (stk.empty() || stk.top() != bracketPair[ch])
                return false;
            stk.pop();
        }
        else
        {
            stk.push(ch);
        }
    }
    return stk.empty();
}

int solution(string s)
{
    int answer = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        answer += isValid(s, i);
    }
    return answer;
}