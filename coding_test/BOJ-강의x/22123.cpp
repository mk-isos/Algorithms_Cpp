#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int timeToSec(const string &timeStr)
{
    int h = stoi(timeStr.substr(0, 2));
    int m = stoi(timeStr.substr(3, 2));
    int s = stoi(timeStr.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

int main()
{
    FIO;
    int n;
    cin >> n;
    while (n--)
    {
        string S, F;
        int k;
        cin >> S >> F >> k;
        int start = timeToSec(S);
        int finish = timeToSec(F);

        if (finish <= start)
            finish += 86400; // 시작 == 끝도 하루로 간주

        int code_time = k * 60;

        if (start + code_time <= finish)
            cout << "Perfect\n";
        else if (start + code_time <= finish + 3600)
            cout << "Test\n";
        else
            cout << "Fail\n";
    }
    return 0;
}
