#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    long long factorial = 1;
    for (int i = 1; i <= N; ++i) {
        factorial *= i;
    }

    cout << factorial << "\n";
    return 0;
}
