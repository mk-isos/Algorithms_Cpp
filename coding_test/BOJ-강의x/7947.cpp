#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    FIO;

    int z; 
    if(!(cin >> z)) return 0;
    while(z--){
        long long sr=0, sg=0, sb=0;
        for(int i=0;i<10;i++){
            int r,g,b; cin >> r >> g >> b;
            sr += r; sg += g; sb += b;
        }
        cout << (sr + 5) / 10 << ' ' << (sg + 5) / 10 << ' ' << (sb + 5) / 10 << '\n';
    }
}
