#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K; 
    cin >> K;

    while (K--) {
        int P, M;
        cin >> P >> M;

        set<int> occupied_seats; 
        int unable_to_participate = 0;

        for (int i = 0; i < P; ++i) {
            int seat;
            cin >> seat;
            
            // Set에 넣었는데 중복되면 참가하지 못하는 사람으로 카운트
            if (occupied_seats.find(seat) == occupied_seats.end()) {
                occupied_seats.insert(seat);
            } else {
                unable_to_participate++;
            }
        }

        cout << unable_to_participate << "\n";
    }

    return 0;
}
