#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int player1 = 0, player2 = 0;

        for (int i = 0; i < n; ++i) {
            char p1, p2;
            cin >> p1 >> p2;

            if (p1 == 'R' && p2 == 'S') player1++;
            else if (p1 == 'S' && p2 == 'P') player1++;
            else if (p1 == 'P' && p2 == 'R') player1++;
            else if (p2 == 'R' && p1 == 'S') player2++;
            else if (p2 == 'S' && p1 == 'P') player2++;
            else if (p2 == 'P' && p1 == 'R') player2++;
        }

        if (player1 > player2) cout << "Player 1\n";
        else if (player1 < player2) cout << "Player 2\n";
        else cout << "TIE\n";
    }

    return 0;
}
