#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    while (true)
    {
        vector<int> sides(3);
        cin >> sides[0] >> sides[1] >> sides[2];

        if (sides[0] == 0 && sides[1] == 0 && sides[2] == 0)
            break;

        sort(sides.begin(), sides.end()); // 변의 길이를 정렬하여 가장 큰 값을 마지막에 둠

        if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2])
        {
            cout << "right" << '\n';
        }
        else
        {
            cout << "wrong" << '\n';
        }
    }
    return 0;
}