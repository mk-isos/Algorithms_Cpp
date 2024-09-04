#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int wc, hc, ws, hs;
    cin >> wc >> hc >> ws >> hs;

    if (ws <= wc - 2 && hs <= hc - 2) 
        cout << 1;
    else 
        cout << 0;

    return 0;
}
