#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);               

    int S, M, L;
    cin >> S >> M >> L;
    
    int happiness = S * 1 + M * 2 + L * 3; 
    
    if (happiness >= 10)
        cout << "happy" << endl;
    else
        cout << "sad" << endl;

    return 0;
}
