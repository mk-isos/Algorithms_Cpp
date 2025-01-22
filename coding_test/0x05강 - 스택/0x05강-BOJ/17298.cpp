#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> result(N, -1);
    stack<int> s;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && A[s.top()] < A[i]) {
            result[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }

    return 0;
}
