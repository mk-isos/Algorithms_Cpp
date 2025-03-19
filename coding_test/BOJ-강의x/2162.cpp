#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct Line
{
    int x1, y1, x2, y2;
};

int N;
vector<Line> lines;
vector<int> parent, groupSize;

// 유니온-파인드 find 함수 (경로 압축 적용)
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

// 유니온 연산 (랭크 고려 X, 단순 union)
void union_sets(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB)
    {
        parent[rootB] = rootA;
        groupSize[rootA] += groupSize[rootB];
    }
}

// CCW 알고리즘을 활용한 선분 교차 판별
int ccw(pair<int, int> A, pair<int, int> B, pair<int, int> C)
{
    long long val = 1LL * (B.first - A.first) * (C.second - A.second) - 1LL * (B.second - A.second) * (C.first - A.first);
    return (val > 0) - (val < 0); // 1, 0, -1 반환
}

// 두 선분이 교차하는지 확인
bool isIntersect(Line A, Line B)
{
    pair<int, int> p1 = {A.x1, A.y1}, p2 = {A.x2, A.y2};
    pair<int, int> p3 = {B.x1, B.y1}, p4 = {B.x2, B.y2};

    int ccw1 = ccw(p1, p2, p3);
    int ccw2 = ccw(p1, p2, p4);
    int ccw3 = ccw(p3, p4, p1);
    int ccw4 = ccw(p3, p4, p2);

    if (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0)
        return true;

    auto between = [](pair<int, int> A, pair<int, int> B, pair<int, int> C)
    {
        return min(A.first, B.first) <= C.first && C.first <= max(A.first, B.first) && min(A.second, B.second) <= C.second && C.second <= max(A.second, B.second);
    };

    if (ccw1 == 0 && between(p1, p2, p3))
        return true;
    if (ccw2 == 0 && between(p1, p2, p4))
        return true;
    if (ccw3 == 0 && between(p3, p4, p1))
        return true;
    if (ccw4 == 0 && between(p3, p4, p2))
        return true;

    return false;
}

int main()
{
    FIO;

    cin >> N;
    lines.resize(N);
    parent.resize(N);
    groupSize.resize(N, 1);

    for (int i = 0; i < N; i++)
    {
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
        parent[i] = i;
    }

    // 모든 선분 비교하여 교차하면 Union
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (isIntersect(lines[i], lines[j]))
            {
                union_sets(i, j);
            }
        }
    }

    unordered_map<int, int> groupCount;
    int maxGroupSize = 0;

    for (int i = 0; i < N; i++)
    {
        int root = find(i);
        groupCount[root] = groupSize[root];
        maxGroupSize = max(maxGroupSize, groupSize[root]);
    }

    cout << groupCount.size() << "\n"
         << maxGroupSize << "\n";

    return 0;
}
