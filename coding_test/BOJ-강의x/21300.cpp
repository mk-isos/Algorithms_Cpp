#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int beer, malt, wine, soda, seltzer, water;
    cin >> beer >> malt >> wine >> soda >> seltzer >> water;
    
    int total_containers = beer + malt + wine + soda + seltzer + water;
    int refund = total_containers * 5;
    
    cout << refund << '\n';
    
    return 0;
}
