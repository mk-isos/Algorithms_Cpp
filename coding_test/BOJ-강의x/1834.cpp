#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long N;
    cin >> N;

    long long sum = 0;
    for (long long q = 1; q < N; ++q) {
        sum += N * q + q;
    }

    cout << sum << '\n';
    return 0;
}
