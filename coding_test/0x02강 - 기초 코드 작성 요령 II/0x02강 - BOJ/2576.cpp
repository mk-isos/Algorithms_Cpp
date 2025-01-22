#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, odd = 0, sum = 0, min = 100;

    for (int i = 0; i < 7; i++) {
    cin >> x;

    if (x & 1) {    // x가 홀수인지 확인 
        odd += 1;
        sum += x;

        if (x < min) {
        min = x;
        }
    }
    }

    if (odd) cout << sum << "\n" << min;
    else cout << "-1";
}