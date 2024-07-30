#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string N;
    cin >> N;

    // 주어진 전화번호의 앞 3자리가 "555"인지 확인
    if (N.substr(0, 3) == "555") {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
