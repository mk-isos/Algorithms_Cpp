#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;  
    cin >> T;
    
    while (T--) {
        int N;  
        cin >> N;
        
        for (int i = 0; i < N; ++i) {
            int A, B;
            cin >> A >> B;
            
            int sum = A + B;        
            int product = A * B;    
            
            cout << sum << " " << product << "\n";
        }
    }

    return 0;
}
