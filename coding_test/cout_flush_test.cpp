#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 100000;

    // endl 사용 (비효율적)
    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        cout << i << endl; // 느림
    }
    auto end1 = chrono::high_resolution_clock::now();
    cout << "Time with endl: "
         << chrono::duration<double>(end1 - start1).count() << "s\n";

    // '\n' 사용 (효율적)
    auto start2 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        cout << i << '\n'; // 빠름
    }
    auto end2 = chrono::high_resolution_clock::now();
    cout << "Time with \\n: "
         << chrono::duration<double>(end2 - start2).count() << "s\n";

    return 0;
}