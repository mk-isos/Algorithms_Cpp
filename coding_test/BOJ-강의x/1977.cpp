#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N;
    cin >> M >> N;

    int sum = 0;
    int minSquare = INT_MAX;
    bool found = false;

    // 완전제곱수를 찾기 위해 1부터 N의 제곱근까지 반복
    for (int i = 1; i * i <= N; ++i) {
        int square = i * i; 
        
        if (square >= M && square <= N) {
            sum += square; 
            minSquare = min(minSquare, square); // 최소 제곱수를 갱신
            found = true; 
        }
    }

    if (found) {
        cout << sum << "\n" << minSquare << "\n"; 
    } else {
        cout << -1 << "\n"; 
    }

    return 0;
}
