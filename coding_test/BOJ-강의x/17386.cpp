#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long LL;

// 점의 좌표를 저장하기 위한 구조체
struct coordinate
{
    LL x, y;
    void read()
    {
        cin >> x >> y;
    }
};

// 세 점 A, B, C에 대해 CCW(외적) 값 계산
//  > 0 → A->B->C 순서가 반시계,
//  < 0 → 시계,
//  = 0 → 일직선
int CCW(const coordinate &A, const coordinate &B, const coordinate &C)
{
    LL temp = (A.x * B.y + B.x * C.y + C.x * A.y) - (A.x * C.y + B.x * A.y + C.x * B.y);
    if (temp > 0)
        return 1; // 반시계
    if (temp < 0)
        return -1; // 시계
    return 0;      // 일직선
}

// 두 선분 (A,B)와 (C,D)가 교차하는지 판별
bool isOverlapped(const coordinate &A, const coordinate &B,
                  const coordinate &C, const coordinate &D)
{
    // A,B를 기준으로 C,D가 서로 다른 방향에 있는지
    int ans1 = CCW(A, B, C) * CCW(A, B, D);
    // C,D를 기준으로 A,B가 서로 다른 방향에 있는지
    int ans2 = CCW(C, D, A) * CCW(C, D, B);

    // 문제에서 세 점이 일직선 위에 있는 경우는 없다고 했으므로,
    // CCW=0인 케이스는 고려하지 않아도 된다.
    // 따라서 두 곱이 모두 음수(< 0)이면 교차
    return (ans1 < 0) && (ans2 < 0);
}

int main()
{
    FIO;
    coordinate A, B, C, D;
    A.read();
    B.read();
    C.read();
    D.read();

    // 교차하면 1, 아니면 0
    if (isOverlapped(A, B, C, D))
        cout << 1 << "\n";
    else
        cout << 0 << "\n";

    return 0;
}