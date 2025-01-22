#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int B;
    cin >> B;

    int P = 5 * B - 400;
    cout << P << '\n';
    
    if (P > 100) {
        cout << "-1\n";
    } else if (P == 100) {
        cout << "0\n";
    } else {
        cout << "1\n";
    }
    
    return 0;
}
