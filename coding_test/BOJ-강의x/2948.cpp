#include <bits/stdc++.h>
using namespace std;

int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string days_of_week[] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int D, M;
    cin >> D >> M;

    int total_days = D - 1;  
    for (int i = 0; i < M - 1; ++i) {
        total_days += days_in_month[i];
    }

    cout << days_of_week[total_days % 7] << "\n";
    return 0;
}
