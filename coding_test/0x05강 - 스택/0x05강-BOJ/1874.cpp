#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    stack<int> s;
    vector<char> result;
    int current = 1;

    for (int i = 0; i < n; ++i) {
        int target = seq[i];
        if (current <= target) {
            while (current <= target) {
                s.push(current++);
                result.push_back('+');
            }
            s.pop();
            result.push_back('-');
        } else {
            if (s.empty() || s.top() != target) {
                cout << "NO\n";
                return 0;
            }
            s.pop();
            result.push_back('-');
        }
    }

    for (char c : result) {
        cout << c << '\n';
    }

    return 0;
}
