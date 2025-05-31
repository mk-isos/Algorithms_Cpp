#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int getColorValue(string color)
{
    if (color == "black")
        return 0;
    if (color == "brown")
        return 1;
    if (color == "red")
        return 2;
    if (color == "orange")
        return 3;
    if (color == "yellow")
        return 4;
    if (color == "green")
        return 5;
    if (color == "blue")
        return 6;
    if (color == "violet")
        return 7;
    if (color == "grey")
        return 8;
    if (color == "white")
        return 9;
    return -1; // error
}

int main()
{
    FIO;
    string a, b, c;
    cin >> a >> b >> c;

    int first = getColorValue(a);
    int second = getColorValue(b);
    int multiplier = getColorValue(c);

    long long result = (first * 10 + second) * pow(10, multiplier);
    cout << result << '\n';
    return 0;
}
