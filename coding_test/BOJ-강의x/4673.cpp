#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

// d(n) 함수
int d(int n)
{
    int sum = n;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    FIO;
    const int MAX = 10000;
    bool generated[MAX + 1] = {false};

    for (int i = 1; i <= MAX; i++)
    {
        int next = d(i);
        if (next <= MAX)
            generated[next] = true;
    }

    for (int i = 1; i <= MAX; i++)
    {
        if (!generated[i])
            cout << i << '\n';
    }
}
