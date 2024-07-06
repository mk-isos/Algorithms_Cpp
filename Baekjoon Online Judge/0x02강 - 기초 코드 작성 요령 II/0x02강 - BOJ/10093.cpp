#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b; //두 정수의 값이 최대 10^15
    cin >> a >> b;
    if (a > b) swap(a,b);   //swap을 그냥 이렇게 사용하구나
    if (a == b || b - a == 1) cout << 0;
    else {
        cout << b - a - 1 << "\n";
        for(long long i = a+1; i < b; i++)
        cout << i << " ";
    }
}