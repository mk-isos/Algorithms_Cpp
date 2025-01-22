#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);  
    cin.tie(0);

    while (true) {
        char c;
        string sentence;
        cin >> c;
        
        if (c == '#') break;
        cin.ignore();
        getline(cin, sentence);

        int count = 0;
        for (char ch : sentence) {
            if (tolower(ch) == c) count++;
        }

        cout << c << ' ' << count << '\n';
    }

    return 0;
}
