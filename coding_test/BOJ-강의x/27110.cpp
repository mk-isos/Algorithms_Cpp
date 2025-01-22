#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    int A, B, C;
    cin >> A >> B >> C;

    int fried = min(N, A);     
    int soy = min(N, B);       
    int seasoned = min(N, C);  

    int total = fried + soy + seasoned;
    
    cout << total << '\n';
    
    return 0;
}
