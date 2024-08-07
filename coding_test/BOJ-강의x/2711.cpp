#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int pos;
        string s;
        cin >> pos >> s;
        pos--;  // 1-based index를 0-based index로 변환
        s.erase(s.begin() + pos);
        cout << s << '\n';
    }

    return 0;
}
