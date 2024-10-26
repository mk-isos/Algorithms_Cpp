#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main() {
    FIO;
    
    long long N;
    cin >> N;

    if (N % 7 == 0 || N % 7 == 2)
        cout << "CY\n";
    else
        cout << "SK\n";

    return 0;
}
