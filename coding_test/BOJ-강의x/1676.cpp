#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int N;
    cin >> N;

    int count = 0;
    for (int i = 5; i <= N; i *= 5)
    {
        count += N / i;
    }

    cout << count << '\n';
    return 0;
}
