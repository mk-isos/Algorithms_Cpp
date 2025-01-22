#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int UR, TR, UO, TO;
    cin >> UR >> TR >> UO >> TO;

    int site_score = 56 * UR + 24 * TR + 14 * UO + 6 * TO;
    cout << site_score << '\n';

    return 0;
}
