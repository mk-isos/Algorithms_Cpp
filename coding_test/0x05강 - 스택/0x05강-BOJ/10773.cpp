#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    cin >> K;
    stack<int> s;

    for (int i = 0; i < K; ++i) {
        int num;
        cin >> num;
        if (num == 0) {
            if (!s.empty()) {
                s.pop();
            }
        } else {
            s.push(num);
        }
    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum << '\n';
    return 0;
}
