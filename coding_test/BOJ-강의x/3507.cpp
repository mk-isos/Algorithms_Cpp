#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int n;
    cin >> n;

    int count = 0;
    for (int a = 0; a <= 99; a++)
    {
        int b = n - a;
        if (0 <= b && b <= 99)
        {
            count++;
        }
    }
    cout << count << '\n';
}
