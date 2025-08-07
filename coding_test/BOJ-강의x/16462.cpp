#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int fix_score(int score)
{
    string s = to_string(score);
    for (char &c : s)
    {
        if (c == '0' || c == '6' || c == '9')
        {
            c = '9';
        }
    }
    int fixed = stoi(s);
    return min(fixed, 100);
}

int main()
{
    FIO;
    int n;
    cin >> n;
    int total = 0;

    for (int i = 0; i < n; ++i)
    {
        int q;
        cin >> q;
        total += fix_score(q);
    }

    double avg = (double)total / n;
    cout << (int)(avg + 0.5) << '\n'; // .5 이상 무조건 올림
    return 0;
}
