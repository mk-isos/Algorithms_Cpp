#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, S;
    cin >> R >> S;

    int total_cupcakes = R * 8 + S * 3;
    int leftover = total_cupcakes - 28;

    cout << leftover << "\n";

    return 0;
}
