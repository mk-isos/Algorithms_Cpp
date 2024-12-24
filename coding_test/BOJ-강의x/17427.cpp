#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main() {
    FIO;

    long long N;
    cin >> N;

    long long result = 0;

    for (long long i = 1; i <= N; i++) {
        result += (N / i) * i; // 각 i의 배수들을 약수로 더하기
    }

    cout << result << "\n";
    return 0;
}
