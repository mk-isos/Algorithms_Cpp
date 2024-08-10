#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L, P;
    cin >> L >> P;
    int expected = L * P;  // 예상 총 참가자 수

    for (int i = 0; i < 5; ++i) {
        int reported;
        cin >> reported;
        cout << reported - expected << " ";  // 각 신문 기사의 수와 예상된 참가자 수의 차이
    }

    return 0;
}
