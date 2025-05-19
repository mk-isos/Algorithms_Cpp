#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    FIO;
    vector<int> A(6), B(6);
    for (int i = 0; i < 6; i++)
        cin >> A[i];
    for (int i = 0; i < 6; i++)
        cin >> B[i];

    int win = 0, total = 36;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (A[i] > B[j])
                win++;
        }
    }

    int g = gcd(win, total);
    cout << (win / g) << "/" << (total / g) << '\n';

    return 0;
}
