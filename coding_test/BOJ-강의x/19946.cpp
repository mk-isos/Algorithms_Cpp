#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = unsigned long long;

int main()
{
    FIO;

    ll N;
    cin >> N;
    ll full = (1ULL << 63);
    full <<= 1; // 2^64 = 18,446,744,073,709,551,616

    ll diff = full - N;
    int power = 0;
    while ((1ULL << power) < diff)
        power++;

    int K = 64 - power;
    cout << K << '\n';
    return 0;
}
