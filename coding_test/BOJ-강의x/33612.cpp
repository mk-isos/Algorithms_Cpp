#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int N;
    cin >> N;

    int startYear = 2024, startMonth = 8;

    int monthsLater = (N - 1) * 7;
    int totalMonth = startYear * 12 + startMonth + monthsLater;

    int year = totalMonth / 12;
    int month = totalMonth % 12;

    if (month == 0)
    {
        year--;
        month = 12;
    }

    cout << year << " " << month << '\n';
    return 0;
}
