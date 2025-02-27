#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int n, m, k;
int note[42][42];
int paper[12][12];
int r, c;

// 90도 회전 함수
void rotate()
{
    int tmp[12][12];
    memcpy(tmp, paper, sizeof(paper)); // 기존 paper 배열을 tmp에 복사

    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            paper[i][j] = tmp[r - 1 - j][i]; // 90도 회전된 위치로 이동

    swap(r, c); // 회전 후 행과 열의 크기 변경
}

// 확인 & 붙이기
bool pastable(int x, int y)
{
    // 겹치는지 확인
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (paper[i][j] == 1 && note[x + i][y + j] == 1)
                return false; // 이미 채워진 칸과 겹치면 불가능
        }
    }

    // 붙일 수 있으면 실제로 note[][]에 스티커를 붙임
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (paper[i][j] == 1)
                note[x + i][y + j] = 1;
        }
    }

    return true; // 성공적으로 붙였으면 true 반환
}

int main()
{
    FIO;
    cin >> n >> m >> k;

    while (k--)
    {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> paper[i][j];

        // 4번 회전하면서 붙일 자리 찾기
        for (int rot = 0; rot < 4; rot++)
        {
            bool is_paste = false; // 스티커를 붙였는지 여부

            for (int x = 0; x <= n - r; x++)
            {
                if (is_paste)
                    break;

                for (int y = 0; y <= m - c; y++)
                {
                    if (pastable(x, y))
                    { // 스티커를 붙일 수 있는 자리 확인
                        is_paste = true;
                        break;
                    }
                }
            }

            if (is_paste)
                break;

            rotate(); // 붙일 수 없으면 90도 회전
        }
    }

    // 스티커가 붙은 칸 개수 세기
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt += note[i][j];

    cout << cnt << '\n';
}
