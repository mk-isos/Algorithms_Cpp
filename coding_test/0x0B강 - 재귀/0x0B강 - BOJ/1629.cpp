#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

using ll = long long;

// 거듭제곱을 빠르게 계산하는 함수 (분할 정복 사용)
ll POW(ll a, ll b, ll m) // 예제 입력: 10 11 12
{
    // 기본 조건: b가 1이면 a % m을 반환
    if (b == 1)
        return a % m; // b == 1일 때 10 % 12 = 10 반환

    // b를 절반으로 나누어 재귀적으로 호출 (분할 정복)
    ll val = POW(a, b / 2, m);

    // 중간 계산 결과를 제곱한 후 모듈러 연산 적용
    val = val * val % m;

    // b가 짝수일 경우 그대로 반환
    if (b % 2 == 0)
        return val;

    // b가 홀수일 경우 추가로 a를 곱해주고 모듈러 연산 적용
    return val * a % m;
}

int main()
{
    FIO;
    ll a, b, c;
    cin >> a >> b >> c;   // 입력: 10 11 12
    cout << POW(a, b, c); // 결과 출력: 4
}
