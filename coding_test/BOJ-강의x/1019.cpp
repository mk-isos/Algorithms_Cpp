#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef long long ll;

ll cnt[10];

void count(ll A, ll B, ll digit)
{
    while (A % 10 != 0 && A <= B)
    {
        ll n = A;
        while (n > 0)
        {
            cnt[n % 10] += digit;
            n /= 10;
        }
        A++;
    }

    if (A > B)
        return;

    while (B % 10 != 9 && A <= B)
    {
        ll n = B;
        while (n > 0)
        {
            cnt[n % 10] += digit;
            n /= 10;
        }
        B--;
    }

    // A는 10의 배수, B는 9로 끝나는 수
    ll count_range = (B / 10 - A / 10 + 1);
    for (int i = 0; i < 10; i++)
    {
        cnt[i] += count_range * digit;
    }

    count(A / 10, B / 10, digit * 10);
}

int main()
{
    FIO;

    ll N;
    cin >> N;

    count(1, N, 1);

    for (int i = 0; i < 10; i++)
        cout << cnt[i] << " ";
}
