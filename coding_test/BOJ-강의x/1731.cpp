#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> a(N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // 등차수열 확인
    long long diff = a[1] - a[0];
    bool is_arithmetic = true;
    for (int i = 1; i < N - 1; ++i) {
        if (a[i+1] - a[i] != diff) {
            is_arithmetic = false;
            break;
        }
    }

    if (is_arithmetic) {
        cout << a[N-1] + diff << "\n";
    } else {
        // 등비수열 확인
        long long ratio = a[1] / a[0];
        cout << a[N-1] * ratio << "\n";
    }

    return 0;
}
