#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long A, B;
    cin >> A >> B;
    
    // A부터 B까지의 합 계산 (작은 값부터 큰 값까지)
    if (A > B) swap(A, B);
    
    long long result = (B - A + 1) * (A + B) / 2;
    
    cout << result << "\n";
    return 0;
}
