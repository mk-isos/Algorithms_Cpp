#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--) {
        string password;
        cin >> password;
        int length = password.length();
        if (length >= 6 && length <= 9) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
