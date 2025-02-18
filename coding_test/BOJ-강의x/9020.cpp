#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

const int MAX = 10000;
vector<bool> is_prime(MAX + 1, true);

void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int main()
{
    FIO;
    sieve();

    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        int a = 0, b = 0;
        for (int i = n / 2; i >= 2; i--)
        {
            if (is_prime[i] && is_prime[n - i])
            {
                a = i, b = n - i;
                break;
            }
        }
        cout << a << " " << b << '\n';
    }
}
