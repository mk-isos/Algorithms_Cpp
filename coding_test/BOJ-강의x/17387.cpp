#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct Point
{
    long long x, y;
    void read()
    {
        cin >> x >> y;
    }
};

// CCW(Orientation) 함수
// (A->B) x (A->C) 의 외적(신발끈 공식 변형)
// > 0 → 반시계, < 0 → 시계, = 0 → 일직선
int ccw(const Point &A, const Point &B, const Point &C)
{
    long long val = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
    if (val > 0)
        return 1; // A->B->C 반시계
    if (val < 0)
        return -1; // 시계
    return 0;      // 일직선
}

// 세 점 A, B, C가 일직선(CCW=0)일 때
// C가 선분 (A,B) 범위 내에 있는지 확인
bool onSegment(const Point &A, const Point &B, const Point &C)
{
    if (min(A.x, B.x) <= C.x && C.x <= max(A.x, B.x) &&
        min(A.y, B.y) <= C.y && C.y <= max(A.y, B.y))
    {
        return true;
    }
    return false;
}

int main()
{
    FIO;
    Point A, B, C, D;
    A.read();
    B.read();
    C.read();
    D.read();

    int ccw1 = ccw(A, B, C);
    int ccw2 = ccw(A, B, D);
    int ccw3 = ccw(C, D, A);
    int ccw4 = ccw(C, D, B);

    // 1) 서로 strict하게 교차하는 경우
    bool intersect = false;
    if (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0)
    {
        intersect = true;
    }
    else
    {
        // 2) 세 점이 일직선(=0)이고, 끝점이 다른 선분 범위 위에 있는 경우
        //    즉 "한 선분의 끝 점이 다른 선분이나 끝 점 위에 있는 것도 교차"라고 했으므로
        if (ccw1 == 0 && onSegment(A, B, C))
            intersect = true;
        if (ccw2 == 0 && onSegment(A, B, D))
            intersect = true;
        if (ccw3 == 0 && onSegment(C, D, A))
            intersect = true;
        if (ccw4 == 0 && onSegment(C, D, B))
            intersect = true;
    }

    cout << (intersect ? 1 : 0) << "\n";
    return 0;
}