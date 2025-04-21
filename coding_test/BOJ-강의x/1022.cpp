#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int A[50][50];
int r1, c1, r2, c2;

void makeMap()
{

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int offset = 0;
    int num = 1;
    int filled = 0;
    int H = r2 - r1 + 1;
    int W = c2 - c1 + 1;
    int total = H * W;

    int x = 0, y = 0;

    while (true)
    {
        /
            if (r1 <= x && x <= r2 && c1 <= y && y <= c2)
        {
            A[x - r1][y - c1] = num;
            if (++filled == total)
                return;
        }
        num++;

        int dir = 0;
        while (dir < 4)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (-offset <= nx && nx <= offset && -offset <= ny && ny <= offset)
            {
                x = nx;
                y = ny;
                if (r1 <= x && x <= r2 && c1 <= y && y <= c2)
                {
                    A[x - r1][y - c1] = num;
                    if (++filled == total)
                        return;
                }
                num++;
            }
            else
            {
                // 범위 벗어나면 다음 방향으로
                dir++;
            }
        }
        // 껍질 확장 후, 한 칸 동쪽으로 이동
        offset++;
        y++;
    }
}

// A에서 가장 큰 값을 찾아 그 자릿수를 반환
int findWidth()
{
    int H = r2 - r1 + 1;
    int W = c2 - c1 + 1;
    int mx = 0;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            mx = max(mx, A[i][j]);
    return to_string(mx).length();
}

int main()
{
    FIO;
    cin >> r1 >> c1 >> r2 >> c2;
    makeMap();
    int H = r2 - r1 + 1;
    int W = c2 - c1 + 1;
    int width = findWidth();

    // 출력: 각 수를 우측 정렬, 공백 최소
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            string s = to_string(A[i][j]);
            // 앞에 모자란 공백 채우기
            cout << string(width - s.length(), ' ') << s;
            if (j + 1 < W)
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
