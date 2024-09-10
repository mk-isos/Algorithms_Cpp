#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    string easiest_problem;
    int min_difficulty = INT_MAX;
    
    while (N--) {
        string title;
        int difficulty;
        cin >> title >> difficulty;
        
        if (difficulty < min_difficulty) {
            min_difficulty = difficulty;
            easiest_problem = title;
        }
    }
    
    cout << easiest_problem << '\n';
    
    return 0;
}
