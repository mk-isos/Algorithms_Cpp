#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    string isbn;
    cin >> isbn;

    int sum = 0, pos = -1;

    for (int i = 0; i < 13; i++)
    {
        if (isbn[i] == '*')
        {
            pos = i;
            continue;
        }

        int num = isbn[i] - '0';
        sum += (i % 2 == 0 ? num : 3 * num);
    }

    // 훼손된 위치의 가중치
    int weight = (pos % 2 == 0 ? 1 : 3);

    // 0~9까지 대입
    for (int x = 0; x <= 9; x++)
    {
        int total = sum + x * weight;
        if (total % 10 == 0)
        {
            cout << x << '\n';
            break;
        }
    }

    return 0;
}
