#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000009;

int main() {
    ios::sync_with_stdio(0);  
    cin.tie(0);

    int N;
    cin >> N;
    
    // 파워 모듈러를 이용해 2^(N-1)와 2^N을 구한 후, 계산
    long long power_N_minus_1 = 1;
    long long power_N = 1;
    
    for (int i = 0; i < N; ++i) {
        power_N = (power_N * 2) % MOD;
        if (i < N - 1)a
            power_N_minus_1 = (power_N_minus_1 * 2) % MOD;
    }
    
    long long result = (power_N_minus_1 * (power_N - 1 + MOD) % MOD) % MOD;
    cout << result << "\n";
    return 0;
}

