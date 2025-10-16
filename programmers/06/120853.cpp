#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    istringstream iss(s);
    string tok;
    int sum = 0, last = 0; // last: 직전에 더한 숫자
    while (iss >> tok)
    {
        if (tok == "Z")
            sum -= last; // 직전 숫자 취소
        else
        {
            last = stoi(tok);
            sum += last;
        }
    }
    return sum;
}
