#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

int main(){
    FIO;

    vector<int> h(9);
    for (int i =0; i<9;i++){
        cin >> h[i];
    }

    sort(h.begin(),h.end());
    int total = accumulate(h.begin(),h.end(),0);

    for(int i =0; i<9; ++i){
        for(int j=i+1; j<9;++j){
            if(total-h[i]-h[j] == 100){
                for(int k=0;  k <9; ++k) {
                    if(k!=i && k != j){
                        cout << h[k] <<'\n';
                    }
                }
                return 0;
            }
        }
    }

}