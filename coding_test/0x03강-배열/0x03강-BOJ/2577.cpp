#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int A, B, C;
    cin >> A >> B >> C;
    
    int t = A * B * C;
    
    int d[10] = {}; // 0부터 9까지의 숫자 빈도를 저장
    // 계산 결과를 자릿수별로 저장
    while (t>0) {
        d[t%10]++;
        t/=10;
    }
    for (int i=0; i<10; ++i) cout << d[i] << '\n';
}