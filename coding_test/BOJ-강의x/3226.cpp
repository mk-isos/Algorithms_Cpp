#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    FIO;
    int N;
    cin >> N;
    int total_cost = 0;

    while (N--) {
        string time;
        int duration;
        cin >> time >> duration;

        int h = stoi(time.substr(0, 2));
        int m = stoi(time.substr(3, 2));
        int start_min = h * 60 + m;

        for (int i = 0; i < duration; i++) {
            int current_min = (start_min + i) % (24 * 60); // 하루 1440분 순환
            int hour = current_min / 60;
            // 07:00 ~ 18:59 → 주간
            if (hour >= 7 && hour < 19) total_cost += 10;
            else total_cost += 5;
        }
    }

    cout << total_cost << '\n';
    return 0;
}
