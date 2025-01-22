#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int M, ball = 1; 
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int X, Y;
        cin >> X >> Y;
        
        if (X == ball) ball = Y;
        else if (Y == ball) ball = X;
    }

    cout << ball << "\n";
    return 0;
}
