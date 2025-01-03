#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    FIO;
    int A, B, m;
    cin >> A >> B >> m;

    vector<int> digits(m);
    for (int i = 0; i < m; ++i) {
        cin >> digits[i];
    }

    // Step 1: A진법 → 10진법
    long long decimal = 0;
    for (int i = 0; i < m; ++i) {
        decimal = decimal * A + digits[i];
    }

    // Step 2: 10진법 → B진법
    vector<int> result;
    while (decimal > 0) {
        result.push_back(decimal % B);
        decimal /= B;
    }
    
    
    reverse(result.begin(), result.end());
    for (int r : result) {
        cout << r << " ";
    }
    cout << "\n";

    return 0;
}
