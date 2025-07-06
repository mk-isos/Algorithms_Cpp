#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int timeToSec(string time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

string secToTime(int sec)
{
    int h = sec / 3600;
    sec %= 3600;
    int m = sec / 60;
    sec %= 60;
    int s = sec;

    stringstream ss;
    ss << setw(2) << setfill('0') << h << ":";
    ss << setw(2) << setfill('0') << m << ":";
    ss << setw(2) << setfill('0') << s;
    return ss.str();
}

int main()
{
    FIO;
    string now, target;
    cin >> now >> target;

    int t1 = timeToSec(now);
    int t2 = timeToSec(target);

    int diff = t2 - t1;
    if (diff <= 0)
        diff += 86400;

    cout << secToTime(diff) << '\n';
    return 0;
}
