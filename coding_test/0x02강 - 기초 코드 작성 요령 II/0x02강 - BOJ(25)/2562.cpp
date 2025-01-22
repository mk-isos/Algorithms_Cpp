#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    FIO;
    
    int max = 0;
    int maxindex = 0;

    for(int i = 0; i < 9; i++){
        int n;
        cin >> n;

        if(max < n){
            max = n;
            maxindex = i + 1;
        }
    }
    cout << max << "\n" << maxindex;

    return 0;
}
