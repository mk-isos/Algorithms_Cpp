#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> heights(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    long long result = 0;   // N이 최대 80,000일 때, 결과가 약 32억일수도
    stack<int> s;

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && s.top() <= heights[i]) { //s.empty()까먹으면 런타임에러
        }
        result += s.size();
        s.push(heights[i]);
    }

    cout << result << "\n";
    return 0;
}
