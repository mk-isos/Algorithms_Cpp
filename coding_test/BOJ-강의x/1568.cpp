#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);  
    cin.tie(0);

    int n, k = 0, time = 0;
    cin >> n;
    while (true) {
        k++;
        if (n == 0) break;
        if (n < k) k = 1;
        n -= k;
        time++;
    }
    cout << time << "\n";
    return 0;
}
