#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);  
    cin.tie(0);               
    
    int N;
    cin >> N;
    
    vector<pair<long long, long long>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    long long area = 0;
    for (int i = 0; i < N; ++i) {
        int j = (i + 1) % N;  
        area += points[i].first * points[j].second;
        area -= points[i].second * points[j].first;
    }

    cout << fixed << setprecision(1) << abs(area) / 2.0 << '\n';

    return 0;
}
