#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

const int MAX = 1000000;
vector<bool> is_prime(MAX + 1, true);
vector<int> primes;

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
    for (int i = 3; i <= MAX; i += 2)
    {
        if (is_prime[i])
            primes.push_back(i);
    }
}

int main()
{
    FIO;

    sieve();

    int n;
    while (cin >> n, n)
    {
        bool found = false;
        for (int a : primes)
        {
            if (a >= n)
                break;
            int b = n - a;
            if (b > 0 && is_prime[b])
            {
                cout << n << " = " << a << " + " << b << '\n';
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Goldbach's conjecture is wrong.\n";
    }
}
