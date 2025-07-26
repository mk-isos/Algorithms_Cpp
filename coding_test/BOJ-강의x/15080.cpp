#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int timeToSeconds(string s) {
    stringstream ss(s);
    int h, m, sec;
    char colon;
    ss >> h >> colon >> m >> colon >> sec;
    return h * 3600 + m * 60 + sec;
}

int main() {
    FIO;
    string start_str, end_str;
    getline(cin, start_str);
    getline(cin, end_str);

    int start = timeToSeconds(start_str);
    int end = timeToSeconds(end_str);

    int result = (end >= start) ? (end - start) : (end + 86400 - start);
    cout << result << '\n';
    return 0;
}
