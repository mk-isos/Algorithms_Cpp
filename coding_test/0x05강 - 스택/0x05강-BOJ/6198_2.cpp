// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog


#include <bits/stdc++.h>
using namespace std;

#define ll long long

stack<int> s;
int n;
ll ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll h;
    while (n--) {
        cin >> h;
        while(!s.empty() && s.top() <= h)
        s.pop();
        ans += s.size();
        s.push(h);
    }
    cout << ans;
    return 0;
}

// 나의 풀이(6198.cpp)와 비교해서 고칠점 :
// 1. 전역 변수 사용
//    - 코딩테스트에서는 전역 변수를 사용하면 코드가 간결해지고 함수 매개변수를 줄일 수 있어 유리할 수 있음.
//    - 하지만 전역 변수는 코드의 가독성을 떨어뜨릴 수 있으므로 적절하게 사용해야 함.

// 2. #define ll long long
//    - long long을 줄여 쓰기 위해 #define을 사용하면 코드 작성이 더 편리해짐.
//    - 코딩테스트에서는 시간 단축을 위해 유용하게 사용 가능.

// 3. FOR문보다 WHILE문 사용
//    - WHILE문은 조건에 따라 유연하게 반복을 제어할 수 있음.
//    - 특정 상황에서는 FOR문보다 WHILE문이 더 적합할 수 있음.