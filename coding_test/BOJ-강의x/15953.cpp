#include <iostream>
using namespace std;

int getPrize2017(int a)
{
    if (a == 0)
        return 0;
    if (a == 1)
        return 500;
    else if (a <= 3)
        return 300;
    else if (a <= 6)
        return 200;
    else if (a <= 10)
        return 50;
    else if (a <= 15)
        return 30;
    else if (a <= 21)
        return 10;
    else
        return 0;
}

int getPrize2018(int b)
{
    if (b == 0)
        return 0;
    if (b == 1)
        return 512;
    else if (b <= 3)
        return 256;
    else if (b <= 7)
        return 128;
    else if (b <= 15)
        return 64;
    else if (b <= 31)
        return 32;
    else
        return 0;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int a, b;
        cin >> a >> b;

        int total = getPrize2017(a) + getPrize2018(b);
        cout << total * 10000 << '\n';
    }

    return 0;
}
