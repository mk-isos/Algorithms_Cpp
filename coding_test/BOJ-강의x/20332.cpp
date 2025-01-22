#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        int w;
        cin >> w;
        total += w;
    }

    if (total % 3 == 0) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }

    return 0;
}
