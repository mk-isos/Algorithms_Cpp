#include <bits/stdc++.h>
using namespace std;

int phone[10000], Y, M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) cin >> phone[n];

    for(int i = 0; i < N; i++) Y += ((phone[n] / 30) + 1) * 10;
    for(int i = 0; i < N; i++) M += ((phone[n] / 60) + 1) * 15;

    if(Y > M) cout << "Y " << Y;
    else if(Y > M) cout << "M " << M;
    else cout << "Y M " << Y;
}

