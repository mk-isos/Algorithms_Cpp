#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        string input;
        cin >> input;
        
        list<char> password;
        auto cursor = password.begin();
        
        for (char ch : input) {
            if (ch == '<') {
                if (cursor != password.begin()) {
                    cursor--;
                }
            } else if (ch == '>') {
                if (cursor != password.end()) {
                    cursor++;
                }
            } else if (ch == '-') {
                if (cursor != password.begin()) {
                    cursor = password.erase(--cursor);
                }
            } else {
                password.insert(cursor, ch);
            }
        }
        
        for (char ch : password) {
            cout << ch;
        }
        cout << '\n';
    }
    
    return 0;
}
