#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;   //초기 문자열
    int m;
    cin >> s;
    cin >> m;   //명령어 개수

    list<char> editor(s.begin(), s.end());
    auto cursor = editor.end();

    while (m--) {
        char command;
        cin >> command;
        if (command == 'L') {
            if (cursor != editor.begin()) {
                --cursor;
            }
        } else if (command == 'D') {
            if (cursor != editor.end()) {
                ++cursor;
            }
        } else if (command == 'B') {
            if (cursor != editor.begin()) {
                cursor = editor.erase(--cursor);
            }
        } else if (command == 'P') {
            char ch;
            cin >> ch;
            editor.insert(cursor, ch);
        }
    }

    for (char c : editor) {
        cout << c;
    }
    cout << '\n';

    return 0;
}
