#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> positions;
        int pos = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                positions.push_back(pos);
            }
            n /= 2;
            pos++;
        }
        for (int i = 0; i < positions.size(); i++) {
            cout << positions[i];
            if (i != positions.size() - 1) {
                cout << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}
