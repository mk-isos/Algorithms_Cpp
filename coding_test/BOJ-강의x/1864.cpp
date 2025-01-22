#include <bits/stdc++.h>
using namespace std;

int convertCharToNum(char c) {
    switch (c) {
        case '-': return 0;
        case '\\': return 1;
        case '(': return 2;
        case '@': return 3;
        case '?': return 4;
        case '>': return 5;
        case '&': return 6;
        case '%': return 7;
        case '/': return -1;
        default: return 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    while (true) {
        cin >> line;
        if (line == "#") break;
        
        int result = 0;
        int base = 1;
        for (int i = line.size() - 1; i >= 0; --i) {
            result += convertCharToNum(line[i]) * base;
            base *= 8;
        }
        cout << result << "\n";
    }

    return 0;
}
