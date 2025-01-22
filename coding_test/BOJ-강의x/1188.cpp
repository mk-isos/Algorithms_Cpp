#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);  
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int gcd_val = gcd(N, M);  
    int cuts = M - gcd_val;    
    cout << cuts << "\n";
    
    return 0;
}
