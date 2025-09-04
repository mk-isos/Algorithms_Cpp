#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    FIO;
    
    int resp, a = 0, b = 0;

    for(int x = 1; x <= 9; ++x){
        cout << "? A " << x << endl;
        if(!(cin >> resp)) return 0;
        if(resp == 1){ a = x; break; }
    }
    for(int x = 1; x <= 9; ++x){
        cout << "? B " << x << endl;
        if(!(cin >> resp)) return 0;
        if(resp == 1){ b = x; break; }
    }
    cout << "! " << (a + b) << endl;
    return 0;
}
