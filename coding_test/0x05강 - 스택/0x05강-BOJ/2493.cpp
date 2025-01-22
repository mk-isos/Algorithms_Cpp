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

    vector<int> result(N, 0);  
    stack<pair<int, int>> s;   // (탑의 높이, 인덱스) 쌍을 저장하는 스택

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && s.top().first <= heights[i]) {
            s.pop();
        }
        if (!s.empty()) {
            result[i] = s.top().second + 1; // 인덱스는 1부터 시작하므로 +1
        }
        s.push({heights[i], i});
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
