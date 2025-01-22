#include <bits/stdc++.h>
using namespace std;

int n, maxvalue, maxidx;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < 10; i++){
        cin >> n;
        // 전역변수의 초기값은 0이므로 바로 비교 가능하다고 함.
        if(maxvalue < n){
            maxvalue = n;
            maxidx = i;
        }
    }

    cout << maxvalue << "\n" << maxidx;
}