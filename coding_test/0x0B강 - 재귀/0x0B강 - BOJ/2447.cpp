#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

// (i, j) 좌표에서 별을 찍을지 공백을 찍을지
void print_star(int i, int j, int num)
{
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1)
        cout << ' ';
    else
    {
        if (num / 3 == 0)
            cout << '*';
        else
            print_star(i, j, num / 3);
    }
}

int main()
{
    FIO;

    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            print_star(i, j, num);
        cout << '\n';
    }
}