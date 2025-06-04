#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int R, C;
    cin >> R >> C;

    vector<string> quarter(R);
    for (int i = 0; i < R; ++i)
    {
        cin >> quarter[i];
    }

    int A, B;
    cin >> A >> B;
    A--, B--; // 0-indexed

    // 상단 반쪽 만들기 (R행, 2C열)
    vector<string> upper(R, string(2 * C, '.'));
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            upper[i][j] = quarter[i][j];
            upper[i][2 * C - j - 1] = quarter[i][j]; // 수평 미러링
        }
    }

    // 전체 카드 만들기 (2R행, 2C열)
    vector<string> card(2 * R, string(2 * C, '.'));
    for (int i = 0; i < R; ++i)
    {
        card[i] = upper[i];
        card[2 * R - i - 1] = upper[i]; // 수직 미러링
    }

    // 에러 좌표 뒤집기
    card[A][B] = (card[A][B] == '#') ? '.' : '#';

    for (int i = 0; i < 2 * R; ++i)
    {
        cout << card[i] << '\n';
    }

    return 0;
}
