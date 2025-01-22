#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main() {
    FIO;

    long long N;
    cin >> N;

    long long bags = 0;

    while (N >= 0) {
        if (N % 5 == 0) { 
            bags += N / 5; 
            cout << bags << "\n";
            return 0;
        }
        N -= 3; 
        bags++;
    }

    cout << -1 << "\n"; 
    return 0;
}
