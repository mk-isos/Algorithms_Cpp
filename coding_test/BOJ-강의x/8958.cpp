#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        
        int score = 0, current_streak = 0;
        for (char c : s) {
            if (c == 'O') {
                current_streak++;
                score += current_streak;
            } else {
                current_streak = 0;
            }
        }
        
        cout << score << '\n';
    }
    
    return 0;
}
