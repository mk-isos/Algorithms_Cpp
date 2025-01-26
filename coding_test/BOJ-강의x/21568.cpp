#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

// 확장 유클리드 알고리즘
// a*x + b*y = gcd(a, b)를 만족하는 (x, y) 찾기
long long gcdExtended(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main(){
    FIO;
    long long A, B, C;
    cin >> A >> B >> C;

    // 1) gcdExtended를 통해 gcd(A,B) 및 (x0, y0) 찾기
    long long x0, y0;
    long long g = gcdExtended(llabs(A), llabs(B), x0, y0);

    // 2) gcd(A,B)가 C를 나누지 못하면 해가 존재하지 않음
    if (C % g != 0) {
        cout << -1 << "\n";
        return 0;
    }

    // 3) C에 맞춰 (x0, y0)를 스케일링
    x0 *= (C / g);
    y0 *= (C / g);

    // A 혹은 B가 음수면 부호 보정
    if (A < 0) x0 = -x0;
    if (B < 0) y0 = -y0;

    // x0, y0가 이미 조건 범위에 있으면 그대로 출력
    const long long LIMIT = 1000000000LL;
    if (x0 >= -LIMIT && x0 <= LIMIT && y0 >= -LIMIT && y0 <= LIMIT) {
        cout << x0 << " " << y0 << "\n";
        return 0;
    }

    // x와 y를 범위 내로 옮기기 위해 k를 조정
    // x = x0 + (B/g)*k
    // y = y0 - (A/g)*k
    // k 범위를 구하기 위한 헬퍼 함수
    auto getRange = [&](long long start, long long step, long long L, long long R) {
        // start + step*k ∈ [L, R]
        // step*k ∈ [L - start, R - start]
        // k ∈ [(L - start)/step, (R - start)/step]
        if (step == 0) {
            // step=0이면, start가 [L, R] 내에 있어야 함
            if (start < L || start > R) {
                // 해 없음
                return pair<long double, long double>(1, -1);
            } else {
                // 무한대로 가능
                return pair<long double, long double>(-1e18L, 1e18L);
            }
        }
        long double mn = (L - (long double)start) / (long double)step;
        long double mx = (R - (long double)start) / (long double)step;
        if (mn > mx) swap(mn, mx);
        return make_pair(mn, mx);
    };

    // |B/g|, |A/g| 값
    long long Bd = llabs(B) / g;
    long long Ad = llabs(A) / g;

    // x와 y 각각에 대한 k의 유효 범위
    auto rx = getRange(x0, (B >= 0 ? Bd : -Bd), -LIMIT, LIMIT);
    auto ry = getRange(y0, (A >= 0 ? -Ad : Ad), -LIMIT, LIMIT);

    // 범위 교집합
    long double lowerBound = max(rx.first, ry.first);
    long double upperBound = min(rx.second, ry.second);

    // 교집합이 비면 해 없음
    if (lowerBound > upperBound) {
        cout << -1 << "\n";
        return 0;
    }

    // 교집합 내에서 임의의 정수 k를 골라서 대입
    long long kCandidate = (long long)floor(lowerBound);
    if ((long double)kCandidate > upperBound) {
        cout << -1 << "\n";
        return 0;
    }

    // kCandidate로 실제 x, y 계산
    long long x = x0 + (B >= 0 ? Bd : -Bd) * kCandidate;
    long long y = y0 + (A >= 0 ? -Ad : Ad) * kCandidate;

    // 최종적으로 범위에 들어가면 출력
    if (x < -LIMIT || x > LIMIT || y < -LIMIT || y > LIMIT) {
        cout << -1 << "\n";
    } else {
        cout << x << " " << y << "\n";
    }

    return 0;
}
