#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main(){
    FIO;
    int n,x,t;
    cin >> n >> x;
    while(n--){
        cin >> t;
        if(t<x) cout << t << ' ';
    }

    return 0;
}