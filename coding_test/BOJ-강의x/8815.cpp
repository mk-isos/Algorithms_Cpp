#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    FIO;
    int Z; 
    if(!(cin >> Z)) return 0;
    const string pat = "ABCBCDCDADAB"; 
    while(Z--){
        long long N; cin >> N;
        cout << pat[(N-1)%12] << '\n';
    }
}
