// Authored by : OceanShape

#include <bits/stdc++.h>
using namespace std;

int K, ans = 0;
stack<int> s;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;
    while(K--){
        int n;
        cin >> n;
        if(n == 0) s.pop(); // 0을 입력할 경우, 가장 최신값(s.top()) 제거
        else s.push(n);     // 0 이외의 수를 입력할 경우, 스택에 추가
    }

    // 스택에 쌓여 있는 모든 값을 더해줌
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    cout << ans;
}

// s.pop()을 호출하기 전에 스택이 비어 있지 않은지 확인하는 것이 안전하지 않나? 
// 비어있는데 호출하면 런타임 오류난다고 강의에서..
/*
내 풀이와 차이점:
1. 변수 선언 위치:
   - OceanShape: `int K, ans = 0; stack<int> s;` 변수를 전역으로 선언.
   - 나의 풀이: `int K; stack<int> s;`를 함수 내에 선언하고, `int sum = 0;`은 최종 합 계산 시에 선언.

2. 입력 처리 방식:
   - OceanShape: while 문을 사용하여 K를 감소시키면서 입력을 처리.
   - 나의 풀이: for 문을 사용하여 K번 입력을 처리.


*/