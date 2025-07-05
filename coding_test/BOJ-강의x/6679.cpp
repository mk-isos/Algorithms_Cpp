#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int digitSum(int n, int base)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % base;
        n /= base;
    }
    return sum;
}

int main()
{
    FIO;
    for (int i = 1000; i <= 9999; ++i)
    {
        int decSum = digitSum(i, 10);
        int duodecSum = digitSum(i, 12);
        int hexSum = digitSum(i, 16);
        if (decSum == duodecSum && decSum == hexSum)
        {
            cout << i << '\n';
        }
    }
    return 0;
}
