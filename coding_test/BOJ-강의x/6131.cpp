#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main()
{
    FIO;
    int N, count = 0;
    cin >> N;

    for (int i = 1; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            int x = i;
            int y = N / i;
            if ((x + y) % 2 == 0 && (y - x) % 2 == 0)
            {
                int A = (x + y) / 2;
                int B = (y - x) / 2;
                if (A >= 1 && B >= 1 && B <= A)
                    count++;
            }
        }
    }

    cout << count << '\n';
    return 0;
}
