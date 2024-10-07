#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long K; // int도 가능이네..
    cin >> K;
    
    string result = "";
    while (K > 0) {
        if (K % 2 == 0) {
            result = '7' + result;
        } else {
            result = '4' + result;
        }
        K = (K - 1) / 2;
    }

    cout << result << "\n";
    return 0;
}
