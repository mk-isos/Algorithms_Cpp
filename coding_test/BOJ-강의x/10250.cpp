#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;

    int T;
    cin >> T;

    while (T--)
    {
        int H, W, N;
        cin >> H >> W >> N;

        int floor = N % H;    // 층수 (나머지)
        int room = N / H + 1; // 호수 (몫 + 1)

        if (floor == 0)
        { // 나머지가 0이면 꼭대기 층
            floor = H;
            room = N / H;
        }

        // 층수 + 호수를 두 자리 수로 맞추기 위해 출력 형식
        cout << floor << setw(2) << setfill('0') << room << "\n";
    }

    return 0;
}
