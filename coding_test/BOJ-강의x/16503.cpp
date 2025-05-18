#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int my_div(int a, int b)
{
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;
    return sign * (abs(a) / abs(b));
}

int calc(int a, string op, int b)
{
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/")
        return my_div(a, b);
    return 0;
}

int main()
{
    FIO;
    int k1, k2, k3;
    string o1, o2;
    cin >> k1 >> o1 >> k2 >> o2 >> k3;

    int res1 = calc(calc(k1, o1, k2), o2, k3);
    int res2 = calc(k1, o1, calc(k2, o2, k3));

    cout << min(res1, res2) << '\n';
    cout << max(res1, res2) << '\n';
}
